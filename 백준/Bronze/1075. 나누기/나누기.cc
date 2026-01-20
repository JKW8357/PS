#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, f;
    cin >> n >> f;
    n = n / 100 * 100;
    
    while (n % f != 0) n++;
    cout << setw(2) << setfill('0') << n % 100 << '\n';

    return 0;
}