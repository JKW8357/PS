#include <bits/stdc++.h>
using namespace std;

vector<int> res = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k; string skills;
    cin >> n >> m >> k >> skills;
    int ans = 2 * (n - 1) + m;

    for (char skill : skills) {
        vector<int> cur(9);
        if (skill == 'A') cur = { 0, res[5], res[6], res[7], res[8], res[1], res[2], res[3], res[4] };
        if (skill == 'B') cur = { 0, res[4], res[3], res[2], res[1], res[8], res[7], res[6], res[5] };
        if (skill == 'C') cur = { 0, res[8], res[7], res[6], res[5], res[4], res[3], res[2], res[1] };
        if (skill == 'D') cur = { 0, res[3], res[1], res[5], res[2], res[7], res[4], res[8], res[6] };
        res = cur;
    }

    for (int i = 1; i <= 8; i++) {
        if (res[i] == ans) {
            cout << (i - 1) / 2 + 1 << ' ' << (i - 1) % 2 + 1 << '\n';
            break;
        }
    }

    return 0;
}