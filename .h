#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
public:
    // Constructor: Opens the log file in append mode
    explicit Logger(const std::string& filename);

    // Destructor: Closes the log file if open
    ~Logger();

    // Method to log a message with a timestamp
    void log(const std::string& message);

private:
    std::ofstream log_file; // Output file stream for logging
};

#endif // LOGGER_H
