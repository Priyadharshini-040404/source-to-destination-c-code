#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string fileA = "Employee.csv";     
    std::string fileB = "Promotion.csv";

    // Check if Employee.csv exists
    if (!fs::exists(fileA)) {
        std::cerr << "Error: " << fileA << " does not exist.\n";
        return 1;
    }

    // Check if Employee.csv is empty
    if (fs::file_size(fileA) == 0) {
        std::cerr << "Error: " << fileA << " is empty.\n";
        return 1;
    }

    // Open Employee.csv for reading
    std::ifstream inFile(fileA);
    if (!inFile) {
        std::cerr << "Error: Cannot open " << fileA << " for reading.\n";
        return 1;
    }

    // Open Promotion.csv for writing (this will create it if not exists, or empty it if exists)
    std::ofstream outFile(fileB, std::ios::trunc);
    if (!outFile) {
        std::cerr << "Error: Cannot open " << fileB << " for writing.\n";
        return 1;
    }

    // Copy content from Employee.csv to Promotion.csv
    std::string line;
    while (std::getline(inFile, line)) {
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();
    std::cout << "Successfully copied to " << fileB << "\n";
    return 0;
}
