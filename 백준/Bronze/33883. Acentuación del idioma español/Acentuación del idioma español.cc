#include <bits/stdc++.h>
using namespace std;
string vns = "aeiouns", v = "aeiou";
int main() {
    string s; cin >> s; int idx = -1;
    int vc = count_if(s.begin(), s.end(), [&](char c) { return string(v).find(c) != -1; });
    if (vc >= 2 && vns.find(s.back()) != -1) idx = s.find_last_of(v, s.find_last_of(v) - 1);
    else if (vns.find(s.back()) == -1) idx = s.find_last_of(v);
    cout << (idx != -1 ? idx + 1 : -1);
}