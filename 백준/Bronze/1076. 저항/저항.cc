#include <bits/stdc++.h>
using namespace std;

string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
int calc(const string& c) { for (int i = 0; i < 10; i++) if (c == color[i]) return i; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    cout << (calc(a) * 10 + calc(b)) * (long long)pow(10, calc(c)) << '\n';
    return 0;
}