#include "bmp.h"
#include "logger.h"
#include "operation_params.h"
#include "messages.h"
int main(int argc, char *argv[]) {
  OperationParams params = parseCommandLine(argc, argv);
  const std::string input_file = "imgs/" + params.input_file;

  if (params.input_file == params.output_file) {
    Logger::exit(1, same_input_output_message);
  }

  BMP bmp(input_file);
  if (!bmp.isValid()) {
    Logger::exit(1, invalid_bmp_message);
  }

  if (params.info) {
    bmp.getInfo();
  }

  if (params.mirror) {
    Logger::warn(mirror_warning);
    bmp.mirror(params.axis, params.left_up, params.right_down);
    Logger::log(success_message);
  }

  if (params.color_replace) {
    Logger::warn(color_replace_warning);
    bmp.colorReplace(params.old_color, params.new_color);
    Logger::log(success_message);
  }

  if (params.split) {
    Logger::warn(image_split_warning);
    bmp.split(params.number_x, params.number_y, params.thickness, params.line_color);
    Logger::log(success_message);
  }

  if (params.copy) {
    Logger::warn(image_copy_warning);
    bmp.copy(params.left_up, params.right_down, params.dest_left_up);
    Logger::log(success_message);
  }

  bmp.save(params.output_file);

  return 0;
}