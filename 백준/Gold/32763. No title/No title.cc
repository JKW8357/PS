#include <bits/stdc++.h>
using namespace std;

bool isSameSign[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    string signs;
    
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " * " << i << endl;
        char ans; cin >> ans;
        if (ans == '+') isSameSign[i] = true;
    }

    bool sameSignExists = false;
    for (int i = 2; i <= n; i++) {
        if (!isSameSign[i]) continue;
        sameSignExists = true;
        cout << "? " << 1 << " + " << i << endl;
        char ans; cin >> ans;
        if (ans == '+') signs += '+';
        else signs += '-';
        break;
    }

    if (!sameSignExists) {
        cout << "? " << 2 << " + " << 3 << endl;
        char ans; cin >> ans;
        if (ans == '+') signs += '-';
        else signs += '+';
    }

    string ss = signs[0] == '+' ? "-+" : "+-";
    for (int i = 2; i <= n; i++) signs += ss[(int)isSameSign[i]];

    cout << "! "; for (char c : signs) cout << c << ' '; cout << endl;
    return 0;
}