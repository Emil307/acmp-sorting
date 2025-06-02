#include <iostream>
using namespace std;

void selectionSortPhasesMaximums(int arr[], int n) {
    int inversions = 0;
    
    for (int phase = 0; phase < n; phase++) {
        int maxIndex = 0;
        int currentEnd = n - phase - 1;
        
        for (int i = 1; i <= currentEnd; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        
        cout << maxIndex;

        if (phase < n - 1) {
            cout << " ";
        }
        
        if (maxIndex != currentEnd) {
            swap(arr[maxIndex], arr[currentEnd]);
        }
    }
}

int main() {
    int n, a[1000], i;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSortPhasesMaximums(a, n);

    return 0;
}