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
    int n, a[1000], i, minVotes = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] = a[i] / 2 + 1;
            continue;
        } 

        a[i] = (a[i] + 1) / 2;
    }

    int* sortedArray = selectionSort(a, n);

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 + 1; i++) {
            minVotes += sortedArray[i];
        }
    } else {
        for (int i = 0; i < (n + 1) / 2; i++) {
            minVotes += sortedArray[i];
        }
    }

    cout << minVotes;

    return 0;
}