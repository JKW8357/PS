#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        string str; cin >> str;
        if (str.ends_with("Cheese")) s.insert(str);
    }

    cout << (s.size() >= 4 ? "yummy" : "sad") << '\n';
    return 0;
}