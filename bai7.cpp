#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file " << fileName << std::endl;
        return 1;
    }

    std::vector<double> numbers;
    double number;
    double total = 0;
    double lowest = std::numeric_limits<double>::max();
    double highest = std::numeric_limits<double>::min();

    while (inputFile >> number) {
        numbers.push_back(number);
        total += number;
        if (number < lowest) {
            lowest = number;
        }
        if (number > highest) {
            highest = number;
        }
    }

    inputFile.close();

    if (numbers.empty()) {
        std::cerr << "No numbers found in the file." << std::endl;
        return 1;
    }

    double average = total / numbers.size();

    std::cout << "Lowest number: " << lowest << std::endl;
    std::cout << "Highest number: " << highest << std::endl;
    std::cout << "Total of numbers: " << total << std::endl;
    std::cout << "Average of numbers: " << average << std::endl;

    return 0;
}