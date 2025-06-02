#include <iostream>
using namespace std;

int partition(long long arr[], int low, int high) {
    long long pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            long long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    long long temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(long long arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int MAX_N = 100000;
    long long numbers[MAX_N];
    int n = 0;
    
    long long num;
    while (cin >> num && n < MAX_N) {
        numbers[n] = num;
        n++;
    }
    
    if (n < 2) {
        cout << "No" << endl;
        return 0;
    }
    
    quickSort(numbers, 0, n - 1);

    if (n == 2) {
        cout << "Yes" << endl;
        return 0;
    }
    
    long long diff = numbers[1] - numbers[0];
    
    for (int i = 2; i < n; i++) {
        long long currentDiff = numbers[i] - numbers[i - 1];
        if (currentDiff != diff) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}
