#include <iostream>

void displayNumbersGreaterThanN(int arr[], int size, int n) {
    std::cout << "Numbers greater than " << n << ": ";
    for (int i = 0; i < size; ++i) {
        if (arr[i] > n) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    const int size = 10;
    int numbers[size] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
    int n;

    std::cout << "Enter a number (n): ";
    std::cin >> n;

    displayNumbersGreaterThanN(numbers, size, n);

    return 0;
}
