#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        while (a != b) {
            if (a > b) a /= 2;
            else b /= 2;
        }
        cout << 10 * a << '\n';
    }

    return 0;
}