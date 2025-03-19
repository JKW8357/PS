#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> myMap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	while (n--) {
		string name, password;
		cin >> name >> password;
		myMap[name] = password;
	}

	while (m--) {
		string query; cin >> query;
		cout << myMap[query] << '\n';
	}

	return 0;
}