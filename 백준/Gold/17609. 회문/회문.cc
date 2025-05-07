#include <bits/stdc++.h>
using namespace std;

int isPalindrome(const string& str, int l, int r) {
    while (l < r) if (str[l++] != str[r--]) return 0;
    return 1;
}

int solve(const string& str) {
    int l = 0, r = (int)str.size() - 1;
    while (l < r) {
        if (str[l] == str[r]) {
            l++;
            r--;
        }
        else {
            if (isPalindrome(str, l + 1, r) || isPalindrome(str, l, r - 1)) return 1;
            else return 2;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string str; cin >> str;
        cout << solve(str) << '\n';
    }

    return 0;
}