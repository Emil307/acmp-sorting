#include <iostream>
using namespace std;

const int MAX_K = 5000;

long long toMinutes(int day, int month, int hour, int minute) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    long long totalDays = 0;

    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth[m];
    }

    totalDays += day - 1;
    
    return totalDays * 24 * 60 + hour * 60 + minute;
}

long long calculateWorkTime(int start_day, int start_month, int start_hour, int start_minute, int end_day, int end_month, int end_hour, int end_minute) {
    long long totalMinutes = 0;
    
    if (start_day == end_day && start_month == end_month) {
        int startMin = max(start_hour * 60 + start_minute, 10 * 60);
        int endMin = min(end_hour * 60 + end_minute + 1, 18 * 60);
        
        if (startMin < endMin) {
            totalMinutes += endMin - startMin;
        }
        return totalMinutes;
    }
    
    int current_day = start_day;
    int current_month = start_month;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (true) {
        if (current_day == start_day && current_month == start_month) {
            int startMin = max(start_hour * 60 + start_minute, 10 * 60);
            int endMin = 18 * 60;
            if (startMin < endMin) {
                totalMinutes += endMin - startMin;
            }
        } else if (current_day == end_day && current_month == end_month) {
            int startMin = 10 * 60;
            int endMin = min(end_hour * 60 + end_minute + 1, 18 * 60);
            if (startMin < endMin) {
                totalMinutes += endMin - startMin;
            }
            break;
        } else {
            totalMinutes += 8 * 60;
        }
        
        current_day++;
        if (current_day > daysInMonth[current_month]) {
            current_day = 1;
            current_month++;
        }
    }
    
    return totalMinutes;
}

int main() {
    int k;
    cin >> k;
    
    int days[MAX_K], months[MAX_K], hours[MAX_K], minutes[MAX_K];
    long long timeInMinutes[MAX_K];
    int indices[MAX_K];
    
    for (int i = 0; i < k; i++) {
        scanf("%d.%d. %d:%d", &days[i], &months[i], &hours[i], &minutes[i]);
        timeInMinutes[i] = toMinutes(days[i], months[i], hours[i], minutes[i]);
        indices[i] = i;
    }
     
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (timeInMinutes[indices[j]] > timeInMinutes[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    long long totalWorkMinutes = 0;
    
    for (int i = 0; i < k; i += 2) {
        int start_idx = indices[i];
        int end_idx = indices[i + 1];
        
        totalWorkMinutes += calculateWorkTime(
            days[start_idx], months[start_idx], hours[start_idx], minutes[start_idx],
            days[end_idx], months[end_idx], hours[end_idx], minutes[end_idx]
        );
    }
    
    long long total_hours = totalWorkMinutes / 60;
    long long total_minutes = totalWorkMinutes % 60;
    
    printf("%lld:%02lld\n", total_hours, total_minutes);
    
    return 0;
}
