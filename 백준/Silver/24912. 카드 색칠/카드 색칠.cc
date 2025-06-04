#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if ((arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) && arr[i] != 0) {
            cout << -1 << '\n';
            return 0;
        }
        if (arr[i]) continue; 
        set<int> color = { 1, 2, 3 };
        if (i > 1) color.erase(arr[i - 1]);
        if (i < n) color.erase(arr[i + 1]);
        arr[i] = *color.begin();
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}