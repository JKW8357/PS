#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define x first
#define y second

struct slash {
	p s, e;
	ll w, m;
};

vector<slash> atk;

int ccw(const p& a, const p& b, const p& c) {
	ll d = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

bool isIntersect(const p& p1, const p& p2, const p& p3, const p& p4) {
	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0)
		return max(p1, p2) >= min(p3, p4) && max(p3, p4) >= min(p1, p2);

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	atk.resize(n);
	for (int i = 0; i < n; i++)
		cin >> atk[i].s.x >> atk[i].s.y >> atk[i].e.x >> atk[i].e.y >> atk[i].w;

	sort(atk.begin(), atk.end(), [](const slash& a, const slash& b) { return a.w < b.w; });

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			if (isIntersect(atk[i].s, atk[i].e, atk[j].s, atk[j].e)) atk[i].m++;
		sum += (atk[i].m + 1) * atk[i].w;
	}

	cout << sum << '\n';
	return 0;
}