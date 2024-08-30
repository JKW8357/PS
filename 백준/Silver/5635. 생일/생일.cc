#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, string>> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while(n--) {
		string name;
		int dd, mm, yy;
		cin >> name >> dd >> mm >> yy;
		vec.push_back({ yy, mm, dd, name });
	}

	sort(vec.begin(), vec.end());
	cout << get<3>(*prev(vec.end())) << '\n' << get<3>(*vec.begin()) << '\n';
	return 0;
}