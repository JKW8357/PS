#include <bits/stdc++.h>
using namespace std;

int findNum(char c) {
    set<int> s;
    int num, ans, res;
    bool found = false;
    for (int i = 1; i <= 10000; i++) s.insert(i);
    for (int i = 1; i <= 9999; i++) {
        num = rand() % 10000 + 1;
        while (!s.count(num)) num = rand() % 10000 + 1;
        cout << "? " << c << ' ' << num << endl;
        cin >> ans;
        if (s.size() >= 2) s.erase(num);
        if (ans) {
            res = num;
            found = true;
            break;
        }
    }
    if (!found) res = *s.begin();
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    srand((unsigned int)time(0));
    int a = findNum('A');
    int b = findNum('B');
    cout << "! " << a + b << endl;
    return 0;
}