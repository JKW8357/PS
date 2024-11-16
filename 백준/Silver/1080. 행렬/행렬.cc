#include <bits/stdc++.h>
using namespace std;

int n, m;
string arr1[55];
string arr2[55];

bool possible() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr1[i][j] != arr2[i][j]) return false;
    return true;
}

void flip(int x, int y) {
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            arr2[i][j] = '1' - arr2[i][j] + '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (arr1[i][j] != arr2[i][j]) {
                ans++;
                flip(i, j);
            }
        }
    }

    cout << (possible() ? ans : -1) << '\n';
    return 0;
}