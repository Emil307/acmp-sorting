#include <iostream>
#include <iomanip>
using namespace std;

long long* selectionSort(long long arr[], int n) {
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
    int n;
    long long arr[40], gorgonaMoney;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long* sortedArray = selectionSort(arr, n);

    cin >> gorgonaMoney;

    long double currentMoney = gorgonaMoney;

    for (int i = 0; i < n; i++) {
      if (sortedArray[i] > currentMoney) {
        long double total = currentMoney + sortedArray[i];

        currentMoney = total / 2.0;
      }
    }

    cout << fixed << setprecision(6) << currentMoney << endl;

    return 0;
}