#include <iostream>
#include <iomanip>
using namespace std;

const int row = 5;
const int col = 10;

void display(bool seats[row][col]) {
    cout << " ";
    for (int i = 1; i <= col; i++) {
        cout << "   " << i;
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < col; j++) {
            if (seats[i][j]) {
                cout << "  #";
            }
            else {
                cout << "   _";
            }
        }
        cout << endl;
    }
}

void reservation(bool seats[row][col], int col, char row) {
    if (seats[row - 'A'][col - 1]) {
        cout << "Seat is already booked " << endl;
    }
    else {
        seats[row - 'A'][col - 1] = true;
        cout << "You have booked seat successfully" << endl;
    }
}

void cancellation(bool seats[row][col], int col, char row) {
    if (!seats[row - 'A'][col - 1]) {
        cout << "Seat is not booked yet " << endl;
    }
    else {
        seats[row - 'A'][col - 1] = false;
        cout << "You have cancelled seat successfully" << endl;
    }
}

int main() {
    bool seats[row][col] = { false };
    int col;
    char row;
    display(seats);
    while (true) {
        cout << "Enter Row (A-E): "; cin >> row;
        cout << "Enter col (1-10): ";  cin >> col;
        if (row < 'A' || row > 'E' || col < 1 || col > 10) {
            cout << "Enter valid Seat";
            continue;
        }
        char choice;
        cout << "Do you want to book or cancel seat (B/C) : "; cin >> choice;
        if (choice == 'B' || choice == 'b') {
            reservation(seats, col, row);
        }
        else if (choice == 'C' || choice == 'c') {
            cancellation(seats, col, row);
        }
        else {
            cout << "Invalid choice" << endl;
            continue;
        }
        display(seats);
        cout << "Do you want to book more seat : "; cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }
}
