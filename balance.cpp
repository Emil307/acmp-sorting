#include <iostream>
using namespace std;

void sortDescending(int digits[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (digits[j] < digits[j + 1]) {
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }
}

void sortAscending(int digits[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (digits[j] > digits[j + 1]) {
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }
}

int extractDigits(long long num, int digits[]) {
    if (num == 0) {
        digits[0] = 0;
        return 1;
    }
    
    if (num < 0) {
      num = -num;
    }
    
    int count = 0;
    while (num > 0) {
        digits[count] = num % 10;
        num /= 10;
        count++;
    }
    return count;
}

long long createNumber(int digits[], int count) {
    long long result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + digits[i];
    }
    return result;
}

long long makeMaxNumber(int digits[], int count) {
    if (count == 0) return 0;
    
    sortDescending(digits, count);
    
    if (digits[0] == 0) {
      return 0;
    }
    
    return createNumber(digits, count);
}

long long makeMinNumber(int digits[], int count) {
    if (count == 0) return 0;
    
    sortAscending(digits, count);
    
    bool hasNonZero = false;
    for (int i = 0; i < count; i++) {
        if (digits[i] != 0) {
            hasNonZero = true;
            break;
        }
    }
    
    if (!hasNonZero) {
      return 0;
    }
    
    if (digits[0] == 0) {
        for (int i = 1; i < count; i++) {
            if (digits[i] != 0) {
                int temp = digits[0];
                digits[0] = digits[i];
                digits[i] = temp;
                break;
            }
        }
    }
    
    return createNumber(digits, count);
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    int digits_a[20], digits_b[20];
    int count_a, count_b;
    
    count_a = extractDigits(a, digits_a);
    count_b = extractDigits(b, digits_b);
    
    long long max_a, min_b;
    
    if (a >= 0) {
        max_a = makeMaxNumber(digits_a, count_a);
    } else {
        max_a = -makeMinNumber(digits_a, count_a);
    }
    
    if (b >= 0) {
        min_b = makeMinNumber(digits_b, count_b);
    } else {
        min_b = -makeMaxNumber(digits_b, count_b);
    }
    
    cout << max_a - min_b << endl;
    
    return 0;
}
