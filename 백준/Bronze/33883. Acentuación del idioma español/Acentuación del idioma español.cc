#include <bits/stdc++.h>
using namespace std;
const size_t npos = string::npos;
string vns = "aeiouns", v = "aeiou";
int main() {
    string s; cin >> s; int idx = npos;
    int vc = count_if(s.begin(), s.end(), [&](char c) { return string(v).find(c) != npos; });
    if (vc >= 2 && vns.find(s.back()) != npos) idx = s.find_last_of(v, s.find_last_of(v) - 1);
    else if (vns.find(s.back()) == npos) idx = s.find_last_of(v);
    cout << (idx != npos ? idx + 1 : -1);
}