#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new T[size]{};
    }

    Array(const Array& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void setValues(T arr[], int n) {
        if (n != size) {
            cout << "Error: Mismatched array size!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // non-member comparison operators
    friend bool operator==(const Array& a, const Array& b) {
        if (a.size != b.size) return false;
        for (int i = 0; i < a.size; i++) {
            if (a.data[i] != b.data[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const Array& a, const Array& b) {
        return !(a == b);
    }

    friend bool operator<(const Array& a, const Array& b) {
        int minSize = (a.size < b.size) ? a.size : b.size;
        for (int i = 0; i < minSize; i++) {
            if (a.data[i] < b.data[i])
                return true;
            if (a.data[i] > b.data[i])
                return false;
        }
        return a.size < b.size;  // If elements are equal, compare by size
    }

    friend bool operator>(const Array& a, const Array& b) {
        return b < a; // Reverse of <
    }

    friend bool operator<=(const Array& a, const Array& b) {
        return !(a > b);
    }

    friend bool operator>=(const Array& a, const Array& b) {
        return !(a < b);
    }
};

int main() {
    Array<int> arr1(5);
    Array<int> arr2(5);

    int values1[] = { 1, 2, 3, 4, 5 };
    arr1.setValues(values1, 5);

    int values2[] = { 1, 2, 3, 4, 6 };
    arr2.setValues(values2, 5);

    cout << "Array 1: ";
    arr1.display();

    cout << "Array 2: ";
    arr2.display();

    if (arr1 == arr2) cout << "Arrays are equal\n";
    if (arr1 != arr2) cout << "Arrays are not equal\n";
    if (arr1 < arr2) cout << "Array 1 is less than Array 2\n";
    if (arr1 > arr2) cout << "Array 1 is greater than Array 2\n";
    if (arr1 <= arr2) cout << "Array 1 is less than or equal to Array 2\n";
    if (arr1 >= arr2) cout << "Array 1 is greater than or equal to Array 2\n";

    return 0;
}
