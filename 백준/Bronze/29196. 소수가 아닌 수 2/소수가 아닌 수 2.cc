#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double k; cin >> k;
    int p = k * 1e8, q = 1e8;
    int GCD = gcd(p, q);
    p /= GCD; q /= GCD;
    cout << "YES\n" << p << ' ' << q << '\n';

    return 0;
}