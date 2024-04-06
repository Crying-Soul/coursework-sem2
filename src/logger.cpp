/**
 * @file logger.cpp
 * @brief Implementation file for the Logger class.
 */
#include "logger.h"
#include "messages.h"
#include <iostream>


namespace {
    inline void setColor(const Color color, std::ostream &stream = std::cout) {
        switch (color) {
            case Color::RED:
                stream << "\033[31m"; // Red
                break;
            case Color::GREEN:
                stream << "\033[32m"; // Green
                break;
            case Color::YELLOW:
                stream << "\033[33m"; // Yellow
                break;
            case Color::BLUE:
                stream << "\033[34m"; // Blue
                break;
            case Color::MAGENTA:
                stream << "\033[35m"; // Magenta
                break;
            case Color::CYAN:
                stream << "\033[36m"; // Cyan
                break;
            case Color::WHITE:
                stream << "\033[37m"; // White
                break;
            default:
                break;
        }
    }

    inline void resetColor(std::ostream &stream = std::cout) {
        stream << "\033[0m"; // Reset color
    }
}

bool Logger::colorsEnabled = false;

Logger::Logger(bool enableColors) {
    setColorsEnabled(enableColors); // Setting colorsEnabled upon Logger object creation
}

void Logger::setColorsEnabled(bool enableColors) {
    colorsEnabled = enableColors;
}

void Logger::log(const std::string &message, Color color, std::ostream &stream) {
    resetColor(stream);
    if (colorsEnabled) {
        setColor(color, stream);
    }
    stream << message << std::endl;
    if (colorsEnabled) {
        resetColor(stream);
    }
}

void Logger::warn(const std::string &message, std::ostream &stream) {
    log(message, Color::YELLOW, stream);
}

void Logger::error(const std::string &message, std::ostream &stream) {
    log(message, Color::RED, stream);
}

void Logger::exit(int exitCode, const std::string &exitMessage, std::ostream &stream) {
    if (!exitMessage.empty()) {
        error(exitMessage, stream);
    }
    std::exit(exitCode);
}
