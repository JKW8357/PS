#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, ans;
    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << endl;
        cin >> ans;
        if (ans) { a = i; break; }
    }

    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << endl;
        cin >> ans;
        if (ans) { b = i; break; }
    }
    
    cout << "! " << a + b << endl;
    return 0;
}