#include <bits/stdc++.h>
using namespace std;
string o="aeiouns",v="aeiou";
int main() {
    string s;cin >> s;int i=-1;
    int c=count_if(s.begin(),s.end(),[&](char c){return v.find(c)!=-1;});
    if(c>=2&&o.find(s.back())!=-1)i=s.find_last_of(v,s.find_last_of(v)-1);
    if(o.find(s.back())==-1)i=s.find_last_of(v);
    cout<<(i!=-1?i+1:-1);
}