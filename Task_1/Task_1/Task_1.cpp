#include <iostream>
using namespace std;

void display(int arr[]) {
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

// swap array uisng pointer
void swapArr(int* a1, int* a2) {
    for (int i = 0; i < 5; i++) {
        int temp = *(a1 + i);
        *(a1 + i) = *(a2 + i);
        *(a2 + i) = temp;
    }
}

// swap array using value
//void swapArr(int a1[], int a2[]) {
//    
//    for (int i = 0; i < 5; i++) {
//        int temp = a1[i];
//        a1[i] = a2[i];
//        a2[i] = temp;
//    }
//}


int main()
{
    int arr1[5] = { 1,2,3,4,5 };
    int arr2[5] = { 0,9,8,7,6 };

    swapArr(arr1, arr2);
    
    cout << "Value of Array 1" << endl;
    display(arr1);
    
    cout << "Value of Array 2 " << endl;
    display(arr2);


    return 0;
}
