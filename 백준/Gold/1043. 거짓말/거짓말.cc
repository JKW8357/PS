#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<vector<int>> party;

int find(int x) {
	if (p[x] == x) return x;
	else if (p[x] == -1) return -1;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	else if (x > y) swap(x, y);
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	party.resize(m);
	p.resize(n + 1);
	for (int i = 1; i < n + 1; i++) p[i] = i;

	int truthCnt;
	cin >> truthCnt;
	if (truthCnt == 0) {
		cout << m << '\n';
		return 0;
	}

	for (int i = 0; i < truthCnt; i++) {
		int num; cin >> num;
		p[num] = -1;
	}

	for (int i = 0; i < m; i++) {
		int invitee; cin >> invitee;
		for (int j = 0; j < invitee; j++) {
			int num; cin >> num;
			party[i].push_back(num);
		}
		for (int j = 0; j < invitee; j++) unite(party[i][0], party[i][j]);
	}

	int answer = m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (find(party[i][j]) == -1) {
				answer--;
				break;
			}
		}
	}

	cout << answer << '\n';
	return 0;
}