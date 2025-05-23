#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[55];
ll y[55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll xmin = LLONG_MAX, xmax = LLONG_MIN;
            ll ymin = LLONG_MAX, ymax = LLONG_MIN;

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                xmin = min(xmin, x[k]);
                xmax = max(xmax, x[k]);
                ymin = min(ymin, y[k]);
                ymax = max(ymax, y[k]);
            }

            ll d = max(xmax - xmin, ymax - ymin) + 2;
            ans = min(ans, d * d);
        }
    }

    cout << ans << '\n';
    return 0;
}