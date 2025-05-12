#include <bits/stdc++.h>
using namespace std;

int prefix[26][200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str; cin >> str;
    for (int i = 1; i <= (int)str.size(); i++) {
        for (int j = 0; j < 26; j++) prefix[j][i] = prefix[j][i - 1];
        prefix[str[i - 1] - 'a'][i]++;
    }

    int tc; cin >> tc;
    while (tc--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << prefix[c - 'a'][r + 1] - prefix[c - 'a'][l] << '\n';
    }

    return 0;
}