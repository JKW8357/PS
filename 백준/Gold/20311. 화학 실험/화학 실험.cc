#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

priority_queue<pii> pq;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int num = 1; num <= k; num++) {
        int cnt; cin >> cnt;
        pq.push({ cnt, num });
    }

    while (!pq.empty()) {
        auto [cnt1, num1] = pq.top(); pq.pop();
        if (v.empty() || (!v.empty() && v.back() != num1)) {
            v.push_back(num1);
            if (--cnt1 > 0) pq.push({ cnt1, num1 });
        }
        else if (!pq.empty()) {
            auto [cnt2, num2] = pq.top(); pq.pop();
            v.push_back(num2);
            pq.push({ cnt1, num1 });
            if (--cnt2 > 0) pq.push({ cnt2, num2 });
        }
        else {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int x : v) cout << x << ' ';
    return 0;
}