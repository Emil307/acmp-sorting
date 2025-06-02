#include <iostream>
using namespace std;

void countingSort(int temperatures[], int n) {
    // Массив для подсчета температур от -100 до +100
    // count[0] соответствует -100°C, count[200] соответствует +100°C
    int count[201] = {0};
    
    // Подсчитываем количество каждой температуры
    for (int i = 0; i < n; i++) {
        count[temperatures[i] + 100]++; // сдвигаем на 100 для положительных индексов
    }
    
    // Восстанавливаем отсортированный массив
    int index = 0;
    for (int i = 0; i < 201; i++) {
        int temperature = i - 100; // преобразуем индекс обратно в температуру
        
        // Записываем эту температуру столько раз, сколько она встречалась
        for (int j = 0; j < count[i]; j++) {
            temperatures[index] = temperature;
            index++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int* temperatures = new int[n]();
    
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }
    
    countingSort(temperatures, n);
    
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << temperatures[i];
    }
    cout << endl;
    
    return 0;
}
