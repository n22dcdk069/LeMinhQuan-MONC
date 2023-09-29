#include <iostream>

const int SIZE = 3;

bool isLoShuMagicSquare(int square[][SIZE]) {
    int magicSum = square[0][0] + square[0][1] + square[0][2]; // Calculate the magic sum for the first row

    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        int rowSum = 0;
        int colSum = 0;
        
        for (int j = 0; j < SIZE; ++j) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }

        if (rowSum != magicSum || colSum != magicSum) {
            return false;
        }
    }

    // Check diagonals
    int diagonal1Sum = square[0][0] + square[1][1] + square[2][2];
    int diagonal2Sum = square[0][2] + square[1][1] + square[2][0];

    return diagonal1Sum == magicSum && diagonal2Sum == magicSum;
}

int main() {
    int square[SIZE][SIZE];

    std::cout << "Enter the elements of a 3x3 square (1-9):" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cin >> square[i][j];
        }
    }

    if (isLoShuMagicSquare(square)) {
        std::cout << "It is a Lo Shu Magic Square!" << std::endl;
    } else {
        std::cout << "It is not a Lo Shu Magic Square." << std::endl;
    }

    return 0;
}