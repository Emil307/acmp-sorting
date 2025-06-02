#include <iostream>
using namespace std;

struct Point {
    long long coord;
    int index;
};

int partition(Point arr[], int low, int high) {
    Point pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j].coord <= pivot.coord) {
            i++;
            Point temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    Point temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(Point arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    Point points[100000];
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].coord;
        points[i].index = i + 1;
    }
    
    quickSort(points, 0, n - 1);
    
    // Ищем минимальное расстояние между соседними точками
    long long minDistance = points[1].coord - points[0].coord;
    int leftIndex = 0;   // индекс левой точки в отсортированном массиве
    int rightIndex = 1;  // индекс правой точки в отсортированном массиве
    
    for (int i = 1; i < n - 1; i++) {
        long long distance = points[i + 1].coord - points[i].coord;
        
        if (distance < minDistance) {
            minDistance = distance;
            leftIndex = i;
            rightIndex = i + 1;
        } else if (distance == minDistance) {
            // При равных расстояниях выбираем пару, которая левее по координатам
            if (points[i].coord < points[leftIndex].coord) {
                leftIndex = i;
                rightIndex = i + 1;
            }
        }
    }
    
    // Получаем номера точек в исходном порядке
    int leftPoint = points[leftIndex].index;
    int rightPoint = points[rightIndex].index;
    
    // Убеждаемся, что выводим меньший номер первым
    if (leftPoint > rightPoint) {
        int temp = leftPoint;
        leftPoint = rightPoint;
        rightPoint = temp;
    }
    
    cout << minDistance << endl;
    cout << rightPoint << " " << leftPoint << endl;
    
    return 0;
}
