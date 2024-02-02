/*
Aliaa Abobakr Elshiekh
120210151
CSE 3
*/

/*
 Write a function that accept two 2D arrays and then multiplicate them (dot product).
 Also, write another function to display the given array in a tabular form.
 Call the functions and print the contents of the two arrays and the resulted array in a tabular form.
*/

/*
This assignment shows usage of array which is type of data structure.
*/

#include <iostream>
using namespace std;

int dotProduct(int arr1[][2], int arr2[][2], int arr[][2], int rows, int cols) {
    int product = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr1[i][j] * arr2[i][j];
            product += arr[i][j];
        }
    }
    return product;
}

void displayArray(int arr[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: " << endl;
    cin >> rows;

    cout << "Enter number of columns: " << endl;
    cin >> cols;

    int arr1[rows][2], arr2[rows][2], arr[rows][2];

    cout << "Enter elements of the first array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter elements of the second array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr2[i][j];
        }
    }

    cout << "The first array" << endl;
    displayArray(arr1, rows, cols);

    cout << "The second array" << endl;
    displayArray(arr2, rows, cols);

    cout << "Dot Product Array" << endl;
    int result = dotProduct(arr1, arr2, arr, rows, cols);
    displayArray(arr, rows, cols);
    
    cout << "Dot product: " << result << endl;

    return 0;
}
