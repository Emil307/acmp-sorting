#include <iostream>
using namespace std;

int bubbleSortWithInversions(int arr[], int n) {
    int inversions = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                inversions++;
            }
        }
    }
    
    return inversions;
}

int main() {
    int n, a[1000], i;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << bubbleSortWithInversions(a, n);

    return 0;
}