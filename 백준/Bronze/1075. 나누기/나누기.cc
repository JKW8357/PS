#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, f;
    cin >> n >> f;
    n = n / 100 * 100;
    
    for (int i = 0; i < 100; i++) {
        if (n % f == 0) {
            cout << setw(2) << setfill('0') << n % 100 << '\n';
            break;
        }
        n++;
    }

    return 0;
}