#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s; int idx = string::npos;
    int vc = count_if(s.begin(), s.end(), [&](char c) { return string("aeiou").find(c) != string::npos; });
    if (vc >= 2 && string("aeiouns").find(s.back()) != string::npos) idx = s.find_last_of("aeiou", s.find_last_of("aeiou") - 1);
    else if (string("aeiouns").find(s.back()) == string::npos) idx = s.find_last_of("aeiou");
    cout << (idx != string::npos ? idx + 1 : -1) << '\n';

    return 0;
}