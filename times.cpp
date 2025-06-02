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
    int n, times[1000][3], seconds[1000], i;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> times[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        seconds[i] = times[i][0] * 3600 + times[i][1] * 60 + times[i][2];
    }

    int* sortedArray = selectionSort(seconds, n);

    for (int i = 0; i < n; i++) {
        int hours = sortedArray[i] / 3600;
        int minutes = (sortedArray[i] % 3600) / 60;
        int secs = sortedArray[i] % 60;
        cout << hours << " " << minutes << " " << secs << endl;
    }

    return 0;
}