#include <bits/stdc++.h>
using namespace std;

vector <long long> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		vec.push_back(stoll(str));
	}
	
	sort(vec.begin(), vec.end());
	for (auto i : vec) cout << i << '\n';

	return 0;
}