#include <bits/stdc++.h>
using namespace std;
using s=string;
s v="aeiou";
s f(s x){int i=x.find_first_of(v);int j=x.find_first_not_of(v,i);return(i|j)==-1?"":x.substr(0,j);}
int main(){s a,b;cin>>a>>b;s c=f(a);s d=f(b);cout<<(c==""||d==""?"no such exercise":c+d);}