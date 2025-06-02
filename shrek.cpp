#include <iostream>
using namespace std;

int* selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    
    return arr;
}

int main() {
    int n, a[1000], i, playerSum = 0, crupierSum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int* sortedArray = selectionSort(a, n);

    for (int i = 0; i < n; i++) {
      if (i < n / 2) {
        crupierSum += sortedArray[i];
        continue;
      } 
      
      playerSum += sortedArray[i];
    }

    cout << playerSum - crupierSum;

    return 0;
}