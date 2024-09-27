#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec;
vector<int> LIS;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end()); // LIS는 반드시 정렬된 배열에서 사용 가능!
	for (auto i : vec) {
		auto pos = lower_bound(LIS.begin(), LIS.end(), i.second);
		if (pos == LIS.end()) LIS.push_back(i.second);
		else *pos = i.second;
	}

	cout << n - LIS.size() << '\n';
	return 0;
}