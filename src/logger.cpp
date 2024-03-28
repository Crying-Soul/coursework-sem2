/**
 * @file logger.cpp
 * @brief Implementation file for the Logger class.
 */

#include "logger.h"
#include "messages.h"
#include <iostream>


bool Logger::colorsEnabled = false;


void Logger::setColorsEnabled(bool enableColors)
{
  colorsEnabled = enableColors;
}


void Logger::log(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << GREEN << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}


void Logger::warn(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << YELLOW << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}


void Logger::error(const std::string &message)
{
  if (colorsEnabled)
  {
    std::cout << RED << message << RESET << std::endl;
  }
  else
  {
    std::cout << message << std::endl;
  }
}


void Logger::exit(const int exitCode, const std::string &exitMessage)
{
  if (!exitMessage.empty())
  {
    Logger::error(exitMessage);
  }
  std::exit(exitCode);
}
