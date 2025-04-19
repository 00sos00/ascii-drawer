#include <iostream>
#include <stdio.h>
using namespace std;

void OutChar(char c) {
    if (c == '\'') {
        cout << "\\\'";
    }
    else if (c == '\\') {
        cout << "\\\\";
    }
    else {
        cout << c;
    }
}

int main()
{
    cout << "Please enter how many rows your drawing has: ";
    int rows; cin >> rows;
    char** input = new char*[rows];
    for (int i = 0; i < rows; i++) {
        input[i] = new char[200];
    }
    system("cls");

    cout << "Please enter the final drawing method: " << endl;
    char dm[200];
    gets_s(dm);
    gets_s(dm);
    system("cls");

    cout << "Please enter the drawing: " << endl;
    for (int i = 0; i < rows; i++) {
        gets_s(input[i], 200);
    }
    system("cls");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; input[i][j] != '\0'; j++) {
            for (int k = 0; dm[k] != '\0'; k++) {
                if (dm[k] == '{' && dm[k + 2] == '}') {
                    if (dm[k + 1] == 'x') {
                        cout << j;
                    }
                    if (dm[k + 1] == 'y') {
                        cout << i;
                    }
                    if (dm[k + 1] == 'c') {
                        OutChar(input[i][j]);
                    }
                    k += 2;
                }
                else {
                    cout << dm[k];
                }
            }
            cout << endl;
        }
    }
    for(;;){}
    for (int i = 0; i < rows; i++) {
        delete[] input[i];
    }
    delete[] input;
}
