#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    if (t == 1) {
        ll a, b; cin >> a >> b;
        ll sum = a + b;
        string s(13, 'a');
        for (int i = 12; i >= 0; i--) {
            s[i] = 'a' + (sum % 26);
            sum -= sum % 26;
            sum /= 26;
        }
        cout << s << '\n';
    }
    else {
        string s; cin >> s;
        ll sum = 0;
        for (int i = 0; i <= 12; i++)
            sum = sum * 26 + (s[i] - 'a');
        cout << sum << '\n';
    }

    return 0;
}