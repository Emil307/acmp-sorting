#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string surname;
    string name;
    string classNum;
    string birthDate;    
    int grade;
    char letter;
};

void parseClass(const string& classStr, int& grade, char& letter) {
    grade = 0;
    int i = 0;
    
    while (i < classStr.length() && classStr[i] >= '0' && classStr[i] <= '9') {
        grade = grade * 10 + (classStr[i] - '0');
        i++;
    }
    
    if (i < classStr.length()) {
        letter = classStr[i];
    }
}

bool compareStudents(const Student& a, const Student& b) {
    if (a.grade != b.grade) {
        return a.grade < b.grade;
    }
    
    if (a.letter != b.letter) {
        return a.letter < b.letter;
    }
    
    return a.surname < b.surname;
}

int main() {
    int n;    
    Student students[100];

    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].surname;
        cin >> students[i].name;
        cin >> students[i].classNum;
        cin >> students[i].birthDate;
        
        parseClass(students[i].classNum, students[i].grade, students[i].letter);
    }
    
    sort(students, students + n, compareStudents);
    
    for (int i = 0; i < n; i++) {
        cout << students[i].classNum << " " 
             << students[i].surname << " " 
             << students[i].name << " " 
             << students[i].birthDate << endl;
    }
    
    return 0;
}