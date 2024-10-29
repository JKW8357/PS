#include <bits/stdc++.h>
using namespace std;

char calc(int st, int en, const string& binary) {
    int result = 0;
    for (int i = st; i < en; i++) {
        result *= 2;
        if (binary[i] == '1') result += 1;
    }
    return result + '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string binary, octal;
    cin >> binary;
    int size = binary.size();
    if (size % 3 != 0) octal += calc(0, size % 3, binary);
    for (int i = size % 3; i < binary.size(); i += 3) octal += calc(i, i + 3, binary);

    cout << octal << '\n';
    return 0;
}