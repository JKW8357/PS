#include <bits/stdc++.h>
using namespace std;

int holes[100005];
int acorns[100005];
int nums[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> holes[i];
        holes[i] += i;
        if (i > 0 && holes[i - 1] > holes[i]) holes[i] = holes[i - 1];
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> acorns[i];
        nums[i] = lower_bound(holes, holes + n, acorns[i]) - holes + 1;
    }

    for (int i = 0; i < q; i++) cout << nums[i] << ' ';
    cout << '\n';

    return 0;
}