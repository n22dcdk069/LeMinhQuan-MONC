#include <iostream>
#include <iomanip>

const int numMonkeys = 3;
const int numDays = 5;

int main() {
    double foodEaten[numMonkeys][numDays];
    
    // Input the data for each monkey
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        std::cout << "Enter data for Monkey " << monkey + 1 << ":" << std::endl;
        for (int day = 0; day < numDays; ++day) {
            do {
                std::cout << "Enter pounds of food eaten on Day " << day + 1 << ": ";
                std::cin >> foodEaten[monkey][day];
                if (foodEaten[monkey][day] < 0) {
                    std::cout << "Pounds of food eaten cannot be negative. Please enter a valid value." << std::endl;
                }
            } while (foodEaten[monkey][day] < 0);
        }
    }

    // Calculate and display the average amount of food eaten per day by all monkeys
    double totalFood = 0;
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        for (int day = 0; day < numDays; ++day) {
            totalFood += foodEaten[monkey][day];
        }
    }
    double averageFoodPerDay = totalFood / (numMonkeys * numDays);
    std::cout << "Average amount of food eaten per day by the whole family of monkeys: " << std::fixed << std::setprecision(2) << averageFoodPerDay << " pounds" << std::endl;

    // Calculate and display the least amount of food eaten during the week by any one monkey
    double minFood = foodEaten[0][0];
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        for (int day = 0; day < numDays; ++day) {
            if (foodEaten[monkey][day] < minFood) {
                minFood = foodEaten[monkey][day];
            }
        }
    }
    std::cout << "The least amount of food eaten during the week by any one monkey: " << std::fixed << std::setprecision(2) << minFood << " pounds" << std::endl;

    // Calculate and display the greatest amount of food eaten during the week by any one monkey
    double maxFood = foodEaten[0][0];
    for (int monkey = 0; monkey < numMonkeys; ++monkey) {
        for (int day = 0; day < numDays; ++day) {
            if (foodEaten[monkey][day] > maxFood) {
                maxFood = foodEaten[monkey][day];
            }
        }
    }
    std::cout << "The greatest amount of food eaten during the week by any one monkey: " << std::fixed << std::setprecision(2) << maxFood << " pounds" << std::endl;

    return 0;
}