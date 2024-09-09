#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> um;
int order[1005];
string cypher[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string key1;
			cin >> key1;
			um[key1] = i;
		}

		for (int i = 0; i < n; i++) {
			string key2;
			cin >> key2;
			order[um[key2]] = i;
		}

		for (int i = 0; i < n; i++) cin >> cypher[i];
		for (int i = 0; i < n; i++) cout << cypher[order[i]] << ' ';
		cout << '\n';
	}

	return 0;
}