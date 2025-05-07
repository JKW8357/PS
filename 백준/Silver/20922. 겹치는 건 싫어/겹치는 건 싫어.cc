#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int cnt[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 0;
    int ans = 0;
    while (r < n) {
        if (cnt[arr[r]] < k) {
            cnt[arr[r]]++;
            r++;
            ans = max(ans, r - l);
        }
        else {
            cnt[arr[l]]--;
            l++;
        }
    }

    cout << ans << '\n';
    return 0;
}