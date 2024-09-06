#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, int>> vec;
int ranking[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int country, gold, silver, bronze;
		cin >> country >> gold >> silver >> bronze;
		vec.push_back({ gold, silver, bronze, country });
	}

	sort(vec.begin(), vec.end(), greater<tuple<int, int, int, int>>());

	int rank = 1;
	ranking[get<3>(vec[0])] = rank;
	for (int i = 1; i < n; i++) {
		if (get<0>(vec[i]) == get<0>(vec[i - 1])
			&& get<1>(vec[i]) == get<1>(vec[i - 1])
			&& get<2>(vec[i]) == get<2>(vec[i - 1])) {
			ranking[get<3>(vec[i])] = rank;
		}
		else {
			rank = i + 1;
			ranking[get<3>(vec[i])] = rank;
		}
	}
	cout << ranking[k] << '\n';
	return 0;
}