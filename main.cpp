#include "bmp.h"
#include "operation_params.h"

int main(int argc, char *argv[]) {
  OperationParams params = parseCommandLine(argc, argv);
  std::string fileName = "./imgs/24_2.bmp";
  BMP bmp(fileName);
  if (!bmp.isValid()) {
    std::cerr << "Failed to load BMP file." << std::endl;
    return 1;
  }

  if (params.mirror) {
    std::cout << "Mirror operation requested" << std::endl;
    bmp.mirror(params.axis, params.left_up, params.right_down);
  }

  // if (params.copy) {
  //   std::cout << "Copy operation requested" << std::endl;
  //   if (!params.left_up.empty()) {
  //     std::cout << "Source top-left corner coordinates: " << params.left_up
  //               << std::endl;
  //   }
  //   if (!params.right_down.empty()) {
  //     std::cout << "Source bottom-right corner coordinates: "
  //               << params.right_down << std::endl;
  //   }
  //   if (!params.dest_left_up.empty()) {
  //     std::cout << "Destination top-left corner coordinates: "
  //               << params.dest_left_up << std::endl;
  //   }
  // }

  // if (params.color_replace) {
  //   std::cout << "Color replacement operation requested" << std::endl;
  //   if (!params.old_color.empty()) {
  //     std::cout << "Old color: " << params.old_color << std::endl;
  //   }
  //   if (!params.new_color.empty()) {
  //     std::cout << "New color: " << params.new_color << std::endl;
  //   }
  // }

  // if (params.split) {
  //   std::cout << "Split operation requested" << std::endl;
  //   std::cout << "Number of parts along X-axis: " << params.number_x
  //             << std::endl;
  //   std::cout << "Number of parts along Y-axis: " << params.number_y
  //             << std::endl;
  //   std::cout << "Line thickness: " << params.thickness << std::endl;
  //   std::cout << "Line color: " << params.line_color << std::endl;
  // }

  bmp.save("output.bmp");

  return 0;
}