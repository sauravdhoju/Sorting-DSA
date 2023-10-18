/*#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // Include conio.h for getch
#include <Windows.h>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to print the integer vector
void printIntArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

bool quickSort(std::vector<int>& arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return false;

    int i = startIndex, j = endIndex;
    while (j >= i) {
        while (arr[i] < arr[startIndex]) {
            i++;
        }
        while (arr[j] > arr[startIndex]) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Recursively sort the subarrays
    quickSort(arr, startIndex, j);
    quickSort(arr, i, endIndex);

    return true;
}

inline void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to get the console window's width in characters
int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// Function to draw a single box with an integer
void drawBox(int num, int x, int y) {
    int numWidth = std::to_string(num).length();
    int boxWidth = numWidth + 4; // Adjust box width based on the number of digits
    int padding = (boxWidth - numWidth) / 2;

    gotoxy(x + padding, y);
    std::cout << char(218);
    for (int i = 0; i < boxWidth; i++) std::cout << char(196);
    std::cout << char(191) << std::endl;

    gotoxy(x + padding, y + 1);
    std::cout << char(179);
    std::cout << ' ' << num << ' ';
    std::cout << char(179) << std::endl;

    gotoxy(x + padding, y + 2);
    std::cout << char(192);
    for (int i = 0; i < boxWidth; i++) std::cout << char(196);
    std::cout << char(217) << std::endl;
}

void collectAndVisualizeInput() {
    std::vector<int> intVector;
    int num;
    int windowWidth = getWindowWidth();
    int boxWidth = 10;
    int totalWidth = 0; // Initialize the total width of boxes

    int x = (windowWidth - totalWidth) / 2; // Initial X position, centered

    gotoxy(x, 0);
    std::cout << "Quick Sort Visualization" << std::endl;
    int y = 2;

    std::cout << "Data: \n";
    std::string inputLine;
    char key;

    while (true) {
        if (_kbhit()) { // Check if a key is pressed
            key = _getch();

            if (key == 's' || key == 'S') { // Start sorting
                if (intVector.empty()) {
                    std::cout << "No data to sort.\n";
                }
                else {
                    break;
                }
            }
            else if (isdigit(key)) {
                std::cout << key;
                inputLine += key;
            }
            else if (key == 13 && !inputLine.empty()) { // Enter key
                num = std::stoi(inputLine);
                intVector.push_back(num);

                // Draw the new box immediately
                drawBox(num, x, y);

                // Update the total width and X position for the next box
                totalWidth += boxWidth;
                x = (windowWidth - totalWidth) / 2;
                inputLine.clear();
            }
        }
    }

    // Start the Quick Sort process
    if (!intVector.empty()) {
        quickSort(intVector, 0, intVector.size() - 1);

        // Print the sorted array
        std::cout << "\nSorted integer vector: ";
        printIntArray(intVector);
    }
}

int main() {
    collectAndVisualizeInput();
    return 0;
}
*/