#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <algorithm>


int maxDigits = 0;
int boxWidth = 0;
int boxGap = 3; // Space between boxes
int count = 0;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}


void printIntArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

inline void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBox(int num, int x, int y, int boxWidth, int numWidth) {
    int padding = (boxWidth - numWidth) / 2;

    gotoxy(x, y);
    std::cout << char(218);
    for (int i = 0; i < boxWidth; i++) std::cout << char(196);
    std::cout << char(191) << std::endl;

    gotoxy(x, y + 1);
    std::cout << char(179);
    for (int i = 0; i < padding; i++) std::cout << ' ';
    std::cout << num;
    for (int i = 0; i < boxWidth - padding - numWidth; i++) std::cout << ' ';
    std::cout << char(179) << std::endl;

    gotoxy(x, y + 2);
    std::cout << char(192);
    for (int i = 0; i < boxWidth; i++) std::cout << char(196);
    std::cout << char(217) << std::endl;
}

//void rearrangewithpivot(std::vector<int>& arr, int pivot) {
//    int left = 0;
//    int right = arr.size() - 1;
//
//    while (left <= right) {
//        while (arr[left] <= pivot) {
//            left++;
//        }
//        while (arr[right] > pivot) {
//            right--;
//        }
//        if (left <= right) {
//            swap(arr[left], arr[right]);
//            left++;
//            right--;
//        }
//    }
//}

void printVector(const std::vector<int>& arr, int pivot) {
    std::cout << "\nPivot element: " << arr[pivot] << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == pivot) {
            std::cout << "[" << arr[i] << "] ";
        }
        else {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void printBoxVector(const std::vector<int>& arr, int start, int end) {
    //std::cout << "\nPivot element: " << arr[pivot] << std::endl;
    boxWidth = maxDigits + 4;
    int x = 5;
    int  y = 13;
    for (size_t i = start; i <= end; ++i) {
        /*if (i == pivot) {

            std::cout << "[" << arr[i] << "] ";
        }
        else {
            std::cout << arr[i] << " ";
        }*/


        drawBox(arr[i], x + start * (boxWidth + boxGap), y + 5 * count, boxWidth, std::to_string(arr[i]).length());

        x += boxWidth + boxGap; // Add gap between boxes
    }
    std::cout << std::endl;
}

bool quickSort(std::vector<int>& arr, int startIndex, int endIndex) {
    if (startIndex > endIndex) return false;
    printBoxVector(arr, startIndex - 1, endIndex);
    int i = startIndex, j = endIndex;
    int swapI = 0, swapJ = 0;
    bool inI = false, inJ = false;
    gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * (startIndex - 1), 17 + 5 * count); std::cout << "p-" << startIndex - 1;
    while (j >= i) {
        gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * i, 17 + 5 * count); std::cout << "i-" << i;
        gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * j, 17 + 5 * count); std::cout << "j-" << j;
        if (i == j) {
            gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * i, 17 + 5 * count); std::cout << "ij-" << i;
        }
        _getch();
        if (arr[i] > arr[startIndex - 1]) { swapI = i; inI = true; }
        if (arr[j] < arr[startIndex - 1]) { swapJ = j; inJ = true; }
        if (inI && inJ) {
            swap(arr[swapI], arr[swapJ]);
            inI = false; inJ = false;
        }

        if (!inI) {
            gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * i, 17 + 5 * count); std::cout << "     ";
            i++;
        }

        if (!inJ) {
            gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * j, 17 + 5 * count); std::cout << "     ";
            j--;
        }
    }
    int temp = arr[startIndex - 1];
    swap(arr[startIndex - 1], arr[j]);
    gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + maxDigits) * (startIndex - 1), 17 + 5 * count); std::cout << "    ";
    gotoxy(7 + (maxDigits + 1) / 2 + (boxGap + boxWidth) * j, 17 + 5 * count); std::cout << "p-" << j;
    printBoxVector(arr, startIndex - 1, endIndex);
    _getch();
    ++count;
    //system("cls");
    quickSort(arr, startIndex, j - 1);
    quickSort(arr, j + 2, endIndex);
    return true;
}


void headings() {
    gotoxy(70, 4);
    std::cout << "Quick Sort Visualization";

    gotoxy(125, 39);
    std::cout << " Press 'S' to start sorting :) ";

    gotoxy(73, 7);
    std::cout << " Enter data: ";
}

void collectAndVisualizeInput() {
    std::vector<int> intVector;
    int num;
    int windowWidth = getWindowWidth();
    int x = 0;

    headings();
    // Moved the Data: prompt to be displayed in front of "Data: "
    /*gotoxy( 70, 4);
    std::cout << "Quick Sort Visualization";

    gotoxy(x + 68, 25);
    std::cout << " Press 'S' to start sorting :) ";

    std::cout << " Enter data: ";
    gotoxy(x + 73, 7);*/

    int y = 10;
    std::string inputLine;
    char key;
    int pivotY = 8; // Y position for displaying the pivot element

    while (true) {
        if (_kbhit()) {
            key = _getch();

            if (key == 's' || key == 'S') {
                if (intVector.empty()) {
                    system("cls");
                    gotoxy(70, 4);
                    std::cout << "Quick Sort Visualization";
                    gotoxy(72, 20);
                    std::cout << "No data to sort.\n";
                    _getch();
                    system("cls");
                    headings();
                }
                else {
                    printBoxVector(intVector, 0, intVector.size() - 1); count++;
                    quickSort(intVector, 1, intVector.size() - 1);
                    std::cout << "Sorted integer vector: ";
                    printBoxVector(intVector, 0, intVector.size() - 1);
                    break;
                }
            }
            else if (isdigit(key) && inputLine.length() < 3) {
                inputLine += key;
                headings();
                std::cout << inputLine << "     ";
                gotoxy(86 + inputLine.length(), 7);
            }
            else if (key == 13 && !inputLine.empty()) {
                num = std::stoi(inputLine);
                intVector.push_back(num);



                for (int number : intVector) {
                    int digits = std::to_string(number).length();
                    if (digits > maxDigits) {
                        maxDigits = digits;
                        system("cls"); headings();
                    }
                }

                int boxWidth = maxDigits + 4;
                //drawBox(num, x, y, boxWidth, std::to_string(num).length());
                //x += boxWidth + boxGap; // Add gap between boxes

                printBoxVector(intVector, 0, intVector.size() - 1);
                inputLine.clear();
            }
        }
    }
}



int main() {
    gotoxy(70, 20);
    std::cout << "QUICK SORT VISUALIZATION";
    _getch();
    system("cls");


    collectAndVisualizeInput();

    std::cout << "Press any key to exit...";
    _getch();

    return 0;
}