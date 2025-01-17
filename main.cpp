#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function to read lines from a file
std::vector<std::string> readLines(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;
    size_t lineCount = 0;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (++lineCount % 10000 == 0) {
            std::cout << "Read " << lineCount << " lines" << std::endl;
        }
    }
    return lines;
}

// Function to write lines to a file
void writeLines(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    size_t lineCount = 0;
    for (const auto& line : lines) {
        file << line << std::endl;
        if (++lineCount % 10000 == 0) {
            std::cout << "Written " << lineCount << " lines" << std::endl;
        }
    }
}

// Function to replace backslashes with forward slashes in a file path
std::string convertPath(const std::string& path) {
    std::string convertedPath = path;
    std::replace(convertedPath.begin(), convertedPath.end(), '\\', '/');
    return convertedPath;
}

int main() {
    std::string inputFilePath;
    std::cout << "Enter the input file path: ";
    std::cin >> inputFilePath;

    // Convert backslashes to forward slashes
    inputFilePath = convertPath(inputFilePath);

    // Read lines from input file
    std::vector<std::string> lines = readLines(inputFilePath);

    // Sort lines by length in descending order
    std::sort(lines.begin(), lines.end(), [](const std::string& a, const std::string& b) {
        return a.length() > b.length();
    });

    // Create output filename by appending "_sort" to the input filename
    std::string outputFilePath = inputFilePath.substr(0, inputFilePath.find_last_of('.')) + "_sort.txt";

    // Write sorted lines to output file
    writeLines(outputFilePath, lines);

    return 0;
}