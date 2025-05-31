#include <bits/stdc++.h>
using namespace std;
const size_t npos = string::npos;

int main() {
    string s; cin >> s; int idx = npos;
    int vc = count_if(s.begin(), s.end(), [&](char c) { return string("aeiou").find(c) != npos; });
    if (vc >= 2 && string("aeiouns").find(s.back()) != npos) idx = s.find_last_of("aeiou", s.find_last_of("aeiou") - 1);
    else if (string("aeiouns").find(s.back()) == npos) idx = s.find_last_of("aeiou");
    cout << (idx != npos ? idx + 1 : -1) << '\n';
}