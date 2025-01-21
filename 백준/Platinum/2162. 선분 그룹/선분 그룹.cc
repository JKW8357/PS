#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> p;
#define x first
#define y second

vector<int> parent;
vector<pair<p, p>> lines;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;
}

int ccw(const p& a, const p& b, const p& c) {
	double d = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
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
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		p p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		lines.push_back({ p1, p2 });
	}

	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (isIntersect(lines[i - 1].x, lines[i - 1].y, lines[j - 1].x, lines[j - 1].y)) unite(i, j);

	vector<int> cnt(n + 1);
	for (int e : parent) 
		if (find(e) >= 1)
			cnt[find(e)]++;

	int groupCnt = 0;
	for (int e : cnt)
		if (e > 0) groupCnt++;

	cout << groupCnt << '\n' << *max_element(cnt.begin(), cnt.end()) << '\n';
	return 0;
}