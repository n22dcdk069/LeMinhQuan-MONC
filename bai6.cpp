#include <iostream>
#include <fstream>

const int numMonths = 3;
const int numDaysPerMonth = 30;
const char WEATHER_SYMBOLS[] = { 'R', 'C', 'S' };

int main() {
    char weatherData[numMonths][numDaysPerMonth];
    int rainyDays[numMonths] = { 0 };
    int cloudyDays[numMonths] = { 0 };
    int sunnyDays[numMonths] = { 0 };
    int maxRainyMonth = 0;

    // Read weather data from file
    std::ifstream inputFile("RainOrShine.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Populate the weatherData array
    for (int month = 0; month < numMonths; ++month) {
        for (int day = 0; day < numDaysPerMonth; ++day) {
            inputFile >> weatherData[month][day];
        }
    }
    inputFile.close();

    // Analyze the weather data and calculate statistics
    for (int month = 0; month < numMonths; ++month) {
        for (int day = 0; day < numDaysPerMonth; ++day) {
            switch (weatherData[month][day]) {
                case 'R':
                    rainyDays[month]++;
                    break;
                case 'C':
                    cloudyDays[month]++;
                    break;
                case 'S':
                    sunnyDays[month]++;
                    break;
                default:
                    std::cerr << "Invalid weather symbol: " << weatherData[month][day] << std::endl;
                    return 1;
            }
        }

        // Check for the month with the most rainy days
        if (rainyDays[month] > rainyDays[maxRainyMonth]) {
            maxRainyMonth = month;
        }
    }

    // Generate and display the report
    std::cout << "Weather Report:" << std::endl;
    for (int month = 0; month < numMonths; ++month) {
        std::cout << "Month " << month + 1 << " - ";
        std::cout << "Rainy: " << rainyDays[month] << " days, ";
        std::cout << "Cloudy: " << cloudyDays[month] << " days, ";
        std::cout << "Sunny: " << sunnyDays[month] << " days" << std::endl;
    }

    std::cout << "The month with the most rainy days is Month " << maxRainyMonth + 1 << std::endl;

    return 0;
}
