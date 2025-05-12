#include <bits/stdc++.h>
using namespace std;

int arr[1030][1030];
int prefix[1030][1030];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}