#include "bmp.h"
#include "logger.h"
#include "operation_params.h"

int main(int argc, char *argv[]) {
  OperationParams params = parseCommandLine(argc, argv);
  std::string input_file = "imgs/" + params.input_file;

  

  BMP bmp(input_file);
  if (!bmp.isValid()) {
    Logger::error("Invalid bmp file!");
    return 1;
  }

  if (params.info) {
    bmp.getInfo();
  }

  if (params.mirror) {
    Logger::warn("=Mirror operation requested!=");
    bmp.mirror(params.axis, params.left_up, params.right_down);
    Logger::log("Success!");
  }

  if (params.color_replace) {
    Logger::warn("=Color replace operation requested!=");
    bmp.colorReplace(params.old_color, params.new_color);
    Logger::log("Success!");
  }

  if (params.split) {
    Logger::warn("=Image split operation requested=.");
    bmp.split(params.number_x, params.number_y, params.thickness, params.line_color);
    Logger::log("Success!");
  }
  if (params.copy) {
    Logger::warn("=Image copy operation requested=.");
    bmp.copy(params.left_up, params.right_down, params.dest_left_up);
    Logger::log("Success!");
  }


  bmp.save(params.output_file);

  return 0;
}