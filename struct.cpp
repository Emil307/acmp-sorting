#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Result {
    string surname;
    int math;
    int informatics;
    int russian;
};

bool cmp(Result a, Result b) {
    if (a.math + a.informatics + a.russian > b.math + b.informatics + b.russian) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    Result results[1000];
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> results[i].surname >> results[i].math >> results[i].informatics >> results[i].russian;
    }

    sort(results, results+n, cmp);

    for (int i = 0; i < n; i++) {
        cout << results[i].surname << " " 
             << results[i].math << " " 
             << results[i].informatics << " " 
             << results[i].russian << " " 
             << results[i].math + results[i].informatics + results[i].russian << endl;
    }

    return 0;
}