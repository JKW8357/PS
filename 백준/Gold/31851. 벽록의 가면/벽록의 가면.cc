#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool isconvex(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
	vector<pair<int, int>> v = { p1, p2, p3, p4 };
	int convex = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			vector<int> others;
			for (int k = 0; k < 4; k++)
				if (k != i && k != j)
					others.push_back(k);

			int other1 = others[0];
			int other2 = others[1];

			if (v[i].X == v[j].X) {
				if ((v[other1].X < v[i].X && v[other2].X < v[i].X) || (v[other1].X > v[i].X && v[other2].X > v[i].X)) convex++;
			}

			else {
					double slope = (double)(v[i].Y - v[j].Y) / (v[i].X - v[j].X);
					bool check1 = v[other1].Y > slope * (v[other1].X - v[i].X) + v[i].Y;
					bool check2 = v[other2].Y > slope * (v[other2].X - v[i].X) + v[i].Y;
					if (check1 == check2) convex++;
			}
		}
	}

	return convex == 4;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> dot;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dot.push_back({ x, y });
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					if (isconvex(dot[i], dot[j], dot[k], dot[l])) cnt++;

	cout << cnt << '\n';
	return 0;
}