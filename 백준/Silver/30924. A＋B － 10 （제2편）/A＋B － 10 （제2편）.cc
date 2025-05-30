#include <bits/stdc++.h>
using namespace std;

unordered_set<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    srand((unsigned int)time(NULL));

    int a, b, ans, num;
    bool found = false;

    for (int i = 1; i <= 10000; i++) {
        A.insert(i);
        B.insert(i);
    }

    for (int i = 1; i <= 9999; i++) {
        num = rand() % 10000 + 1;
        while (!A.count(num)) num = rand() % 10000 + 1;
        cout << "? A " << num << endl;
        cin >> ans;
        if (A.size() >= 2) A.erase(num);
        if (ans) { 
            a = num;
            found = true;
            break;
        }
    }

    if (!found) a = *A.begin();
    found = false;

    for (int i = 1; i <= 9999; i++) {
        num = rand() % 10000 + 1;
        while (!B.count(num)) num = rand() % 10000 + 1;
        cout << "? B " << num << endl;
        cin >> ans;
        if (B.size() >= 2) B.erase(num);
        if (ans) {
            b = num;
            found = true;
            break;
        }
    }

    if (!found) b = *B.begin();
    
    cout << "! " << a + b << endl;
    return 0;
}