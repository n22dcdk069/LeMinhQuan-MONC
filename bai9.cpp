#include <iostream>
#include <iomanip>

const int NUM_EMPLOYEES = 7;

int main() {
    long empId[NUM_EMPLOYEES] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[NUM_EMPLOYEES];
    double payRate[NUM_EMPLOYEES];
    double wages[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        std::cout << "Enter hours worked for employee " << empId[i] << ": ";
        std::cin >> hours[i];

        // Input validation for hours
        while (hours[i] < 0) {
            std::cout << "Hours worked cannot be negative. Enter hours worked for employee " << empId[i] << ": ";
            std::cin >> hours[i];
        }

        std::cout << "Enter pay rate for employee " << empId[i] << ": ";
        std::cin >> payRate[i];

        // Input validation for pay rate
        while (payRate[i] < 15.00) {
            std::cout << "Pay rate cannot be less than $15.00. Enter pay rate for employee " << empId[i] << ": ";
            std::cin >> payRate[i];
        }

        wages[i] = hours[i] * payRate[i];
    }

    // Display employee information
    std::cout << "\nEmployee Information:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        std::cout << "Employee ID: " << empId[i] << ", Gross Wages: $" << std::fixed << std::setprecision(2) << wages[i] << std::endl;
    }

    return 0;
}
