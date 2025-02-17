#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

set<ll> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        A.insert(x - y);
        B.insert(x + y);
    }
    
    vector<ll> a(A.begin(), A.end());
    vector<ll> b(B.begin(), B.end());
    
    ll ABintersept = 0;
    for (ll t : b) {
        ll num = lower_bound(a.begin(), a.end(), t) - a.begin();
		ABintersept += num;
    }
    
	vector<ll> result;
	result.resize(A.size() + B.size());
	auto it = set_union(A.begin(), A.end(), B.begin(), B.end(), result.begin());
	result.resize(it - result.begin());
	ll xAxisIntersept = result.size();
    
    ll ans = xAxisIntersept + ABintersept;
    cout << ans << "\n";
    
    return 0;
}