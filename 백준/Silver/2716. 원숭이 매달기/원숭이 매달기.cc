#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc; cin.ignore();
    while (tc--) {
        string s; getline(cin, s);
        int st = 0, depth = 0;
        for (char c : s) {
            if (c == '[') st++;
            else st--;
            depth = max(depth, st);
        }
        cout << (1 << depth) << '\n';
    }

    return 0;
}