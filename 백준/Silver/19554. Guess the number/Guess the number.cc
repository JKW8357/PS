#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << endl;
        int ans; cin >> ans;
        if (ans == 1) hi = mid - 1;
        else if (ans == -1) lo = mid + 1;
        else {
            cout << "= " << mid << endl;
            break;
        }
    }

    return 0;
}