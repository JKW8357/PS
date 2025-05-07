#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int cnt = 0;
    int l = 0, r = n - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == m) {
            cnt++;
            l++;
            r--;
        }
        else if (sum < m) l++;
        else r--;
    }

    cout << cnt << '\n';
    return 0;
}