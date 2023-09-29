#include <iostream>
#include <string>

int main() {
    const int numSalsas = 5;
    std::string salsaNames[numSalsas] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };
    int jarsSold[numSalsas];
    int totalSales = 0;
    int maxSalesIndex = 0;
    int minSalesIndex = 0;

    // Input number of jars sold for each salsa type
    for (int i = 0; i < numSalsas; ++i) {
        do {
            std::cout << "Enter the number of jars sold for " << salsaNames[i] << ": ";
            std::cin >> jarsSold[i];

            if (jarsSold[i] < 0) {
                std::cout << "Number of jars sold cannot be negative. Please enter a valid value." << std::endl;
            }
        } while (jarsSold[i] < 0);

        totalSales += jarsSold[i];

        if (jarsSold[i] > jarsSold[maxSalesIndex]) {
            maxSalesIndex = i;
        }

        if (jarsSold[i] < jarsSold[minSalesIndex]) {
            minSalesIndex = i;
        }
    }

    // Display sales data
    std::cout << "\nSales Data:\n";
    for (int i = 0; i < numSalsas; ++i) {
        std::cout << salsaNames[i] << " Salsa: " << jarsSold[i] << " jars" << std::endl;
    }

    // Display total sales
    std::cout << "Total Sales: " << totalSales << " jars" << std::endl;

    // Display highest selling and lowest selling products
    std::cout << "Highest Selling Product: " << salsaNames[maxSalesIndex] << " Salsa (" << jarsSold[maxSalesIndex] << " jars)" << std::endl;
    std::cout << "Lowest Selling Product: " << salsaNames[minSalesIndex] << " Salsa (" << jarsSold[minSalesIndex] << " jars)" << std::endl;

    return 0;
}
