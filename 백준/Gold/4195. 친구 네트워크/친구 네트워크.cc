#include <bits/stdc++.h>
using namespace std;

vector<int> p, cnt;
unordered_map<string, int> um;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

// Union-by-Rank 최적화 없이도 충분히 빠른 시간 내 동작한다. 
void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (p[x] < p[y]) swap(x, y);
	if (p[x] == p[y]) p[y]--;
	p[y] = x;
	cnt[x] += cnt[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	int idx;
	while (tc--) {
		int f; cin >> f;
		idx = 0;

		um.clear();
		p.assign(f * 2, -1);
		cnt.assign(f * 2, 1);
		
		while (f--) {
			string id1, id2;
			cin >> id1 >> id2;

			if (!um[id1]) um[id1] = ++idx;
			if (!um[id2]) um[id2] = ++idx;
            
			unionSets(um[id1], um[id2]);
			cout << cnt[find(um[id1])] << '\n';
		}
	}

	return 0;
}