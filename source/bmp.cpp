/**
 * @file bmp.cpp
 * @brief Реализация методов класса BMP для работы с изображениями в формате
 * BMP.
 */

#include "bmp.hpp"
#include "logger.hpp"
#include "messages.hpp"

BMP::BMP(const std::string& fileName)
: header()
, pixelData()
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) { Logger::exit(ERR_FILE_NOT_FOUND, open_bmp_error + fileName); }

    file.read(reinterpret_cast<char*>(&header), sizeof(header));

    if (!validateHeader())
    {
        file.close();
        Logger::exit(ERR_INCORRECT_FILE_FORMAT, invalid_header_error + fileName);
    }

    const uint32_t bytesPerPixel = header.bitsPerPixel / 8;
    const uint32_t rowSize = ((header.width * bytesPerPixel + 3) / 4) * 4;
    const uint32_t imageSize = rowSize * header.height;

    pixelData.resize(imageSize);

    file.seekg(header.dataOffset, std::ios_base::beg);

    file.read(reinterpret_cast<char*>(pixelData.data()), imageSize);

    file.close();
}

bool BMP::validateHeader() const
{
    if (std::strncmp(header.signature, "BM", 2) != 0)
    {
        Logger::exit(ERR_INCORRECT_FILE_FORMAT, invalid_signature_error);
        return false;
    }

    if (header.width <= 0 || header.height <= 0)
    {
        Logger::exit(ERR_INCORRECT_FILE_FORMAT, invalid_dimensions_error);
        return false;
    }

    if (header.bitsPerPixel != 24) { Logger::warn(invalid_bpp_warning); }

    if (header.compression != 0)
    {
        Logger::exit(ERR_INCORRECT_FILE_FORMAT, unsupported_compression_error);
        return false;
    }

    return true;
}

bool BMP::isValid() const { return !pixelData.empty(); }

RGB BMP::getColor(int x, int y) const
{
    if (x < 0 || x >= header.width || y < 0 || y >= header.height) return RGB();

    const uint32_t bytesPerPixel = header.bitsPerPixel / 8;
    const uint32_t bytesPerRow = (bytesPerPixel * header.width + 3) & ~3;
    const uint32_t index = ((header.height - 1 - y) * bytesPerRow) + (x * bytesPerPixel);

    return RGB(pixelData[index + 2], pixelData[index + 1], pixelData[index]);
}

void BMP::setColor(int x, int y, const RGB& newColor)
{
    if (x < 0 || x >= header.width || y < 0 || y >= header.height) return;

    const uint32_t bytesPerPixel = header.bitsPerPixel / 8;
    const uint32_t bytesPerRow = (bytesPerPixel * header.width + 3) & ~3;
    const uint32_t index = ((header.height - 1 - y) * bytesPerRow) + (x * bytesPerPixel);

    pixelData[index] = newColor.blue;
    pixelData[index + 1] = newColor.green;
    pixelData[index + 2] = newColor.red;
}

void BMP::colorReplace(const RGB& old_color, const RGB& new_color)
{
    for (int y = 0; y < header.height; y++)
    {
        for (int x = 0; x < header.width; x++)
        {
            RGB current_color = getColor(x, y);
            if (current_color.red == old_color.red && current_color.green == old_color.green && current_color.blue == old_color.blue) { setColor(x, y, new_color); }
        }
    }
}

void BMP::mirror(const std::string& axis, const Coordinate& left_up, const Coordinate& right_down)
{
    int width = right_down.x - left_up.x;
    int height = right_down.y - left_up.y;

    if (axis != "x" && axis != "y") { Logger::exit(ERR_INVALID_ARGUMENT, invalid_mirror_axis_error); }

    if (axis == "x")
    {
        for (int y = left_up.y; y <= right_down.y; ++y)
        {
            for (int x = left_up.x; x < left_up.x + width / 2; ++x)
            {
                int mirroredX = right_down.x - (x - left_up.x);
                RGB tempColor = getColor(x, y);
                setColor(x, y, getColor(mirroredX, y));
                setColor(mirroredX, y, tempColor);
            }
        }
    }
    else if (axis == "y")
    {
        for (int y = left_up.y; y < left_up.y + height / 2; ++y)
        {
            for (int x = left_up.x; x <= right_down.x; ++x)
            {
                int mirroredY = right_down.y - (y - left_up.y);
                RGB tempColor = getColor(x, y);
                setColor(x, y, getColor(x, mirroredY));
                setColor(x, mirroredY, tempColor);
            }
        }
    }
}
void BMP::split(int number_x, int number_y, int thickness, const RGB& color)
{
    if ((number_x <= 0 || number_x > header.width) || (number_y <= 0 || number_y > header.height) || (thickness <= 0 || thickness > header.width)) { Logger::exit(ERR_INVALID_ARGUMENT, invalid_split_parameters_error); }

    int gap;

    for (int i = 1; i < number_y; i++)
    {
        gap = header.height / number_y;
        for (int x = 0; x < header.width; x++)
        {
            for (int y = 0; y < thickness; y++) { setColor(x, i * gap + y, color); }
        }
    }

    for (int i = 1; i < number_x; i++)
    {
        gap = header.width / number_x;
        for (int x = 0; x < thickness; x++)
        {
            for (int y = 0; y < header.height; y++) { setColor(i * gap + x, y, color); }
        }
    }
}

void BMP::copy(const Coordinate& src_left_up, const Coordinate& src_right_down, const Coordinate& dest_left_up)
{
    int src_x_min = std::min(src_left_up.x, src_right_down.x);
    int src_x_max = std::max(src_left_up.x, src_right_down.x);
    int src_y_min = std::min(src_left_up.y, src_right_down.y);
    int src_y_max = std::max(src_left_up.y, src_right_down.y);

    int dest_x_min = dest_left_up.x;
    int dest_y_min = dest_left_up.y;

    for (int x = src_x_min; x <= src_x_max; x++)
    {
        for (int y = src_y_min; y <= src_y_max; y++) { setColor(dest_x_min + (x - src_x_min), dest_y_min + (y - src_y_min), getColor(x, y)); }
    }
}
void BMP::save(const std::string& fileName)
{
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open())
    {
        Logger::exit(ERR_FILE_WRITE_ERROR, failed_create_output_file + fileName);
        return;
    }

    const uint32_t bytesPerPixel = header.bitsPerPixel / 8;
    const uint32_t rowSize = ((header.width * bytesPerPixel + 3) / 4) * 4;

    file.write(reinterpret_cast<const char*>(&header), sizeof(header));
    file.seekp(header.dataOffset, std::ios::beg);
    for (int y = 0; y < header.height; ++y) { file.write(reinterpret_cast<const char*>(pixelData.data() + y * rowSize), rowSize); }

    file.close();
}

void BMP::getInfo() const
{
    Logger::log(signature_message + std::string(header.signature, 2));
    Logger::log(file_size_message + std::to_string(header.fileSize) + " bytes");
    Logger::log(data_offset_message + std::to_string(header.dataOffset) + " bytes");
    Logger::log(header_size_message + std::to_string(header.headerSize) + " bytes");
    Logger::log(image_dimensions_message + std::to_string(header.width) + "x" + std::to_string(header.height));
    Logger::log(bits_per_pixel_message + std::to_string(header.bitsPerPixel));
    Logger::log(compression_message + std::to_string(header.compression));
    Logger::log(image_size_message + std::to_string(header.imageSize) + " bytes");
    Logger::log(pixels_per_meter_x_message + std::to_string(header.xPixelsPerMeter));
    Logger::log(pixels_per_meter_y_message + std::to_string(header.yPixelsPerMeter));
    Logger::log(colors_used_message + std::to_string(header.colorsUsed));
    Logger::log(important_colors_message + std::to_string(header.colorsImportant));
}
