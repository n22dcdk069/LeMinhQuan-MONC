#include <iostream>

int main() {
    const int size = 10;
    int numbers[size];

    // Input values into the array
    std::cout << "Enter 10 values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    // Find the largest and smallest values
    int largest = numbers[0];
    int smallest = numbers[0];

    for (int i = 1; i < size; ++i) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    // Display the largest and smallest values
    std::cout << "Largest value: " << largest << std::endl;
    std::cout << "Smallest value: " << smallest << std::endl;

    return 0;
}
