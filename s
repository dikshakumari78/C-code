#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

void readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Error: The file '" + filePath + "' was not found.");
    }

    std::string line;
    while (std::getline(file, line)) {
        try {
            std::istringstream iss(line);
            int number;
            if (!(iss >> number)) {
                throw std::runtime_error("Unexpected data format: " + line);
            }
            std::cout << "Processed number: " << number << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    if (file.bad()) {
        throw std::runtime_error("Error: An I/O error occurred while reading the file.");
    }
}

int main() {
    try {
        std::string filePath = "example.txt";
        readFile(filePath);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
