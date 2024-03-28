#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
private:
  static bool colorsEnabled;
  static constexpr const char *RESET = "\033[0m";
  static constexpr const char *BLACK = "\033[30m";   /* Black */
  static constexpr const char *RED = "\033[31m";     /* Red */
  static constexpr const char *GREEN = "\033[32m";   /* Green */
  static constexpr const char *YELLOW = "\033[33m";  /* Yellow */
  static constexpr const char *BLUE = "\033[34m";    /* Blue */
  static constexpr const char *MAGENTA = "\033[35m"; /* Magenta */
  static constexpr const char *CYAN = "\033[36m";    /* Cyan */
  static constexpr const char *WHITE = "\033[37m";   /* White */

public:
  static void setColorsEnabled(bool enableColors);
  static void log(const std::string &message);
  static void warn(const std::string &message);
  static void error(const std::string &message);
  static void exit(const int exitCode, const std::string &exitMessage);
};

#endif // LOGGER_H