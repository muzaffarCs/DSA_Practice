#include <iostream>

using namespace std;

const int SIZE = 100;

void insertElement(int arr[], int& size, int value, int idx) {
    if (size >= SIZE) {
        cout << "Array is full, cannot insert more elements." << endl;
        return;
    }

    if (idx < 0 || idx > size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = size; i > idx; i--) {
        arr[i] = arr[i - 1];
    }

    arr[idx] = value;
    size++;
}

void deleteElement(int arr[], int& size, int idx) {
    if (size == 0) {
        cout << "Array is empty, nothing to delete." << endl;
        return;
    }

    if (idx < 0 || idx >= size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = idx; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[SIZE] = { 10, 20, 30, 40, 50 };
    int size = 5;

    cout << "Original Array: ";
    displayArray(arr, size);

    // Insert at Start
    insertElement(arr, size, 5, 0);
    cout << "After inserting 5 at start: ";
    displayArray(arr, size);

    // Insert at End
    insertElement(arr, size, 60, size);
    cout << "After inserting 60 at end: ";
    displayArray(arr, size);

    // Insert at Index 3
    insertElement(arr, size, 25, 3);
    cout << "After inserting 25 at index 3: ";
    displayArray(arr, size);

    // Delete from Start
    deleteElement(arr, size, 0);
    cout << "After deleting from start: ";
    displayArray(arr, size);

    // Delete from End
    deleteElement(arr, size, size - 1);
    cout << "After deleting from end: ";
    displayArray(arr, size);

    // Delete from Index 2
    deleteElement(arr, size, 2);
    cout << "After deleting from index 2: ";
    displayArray(arr, size);

    return 0;
}
