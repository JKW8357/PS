#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string pattern; cin >> pattern;
	int index = pattern.find('*');
	string l = pattern.substr(0, index);
	string r = pattern.substr(index + 1);
	
	while (n--) {
		string name; cin >> name;
		if (name.size() < l.size() + r.size()) {
			cout << "NE\n";
			continue;
		}

		cout << ((l == name.substr(0, l.size()) && r == name.substr(name.size() - r.size())) ? "DA\n" : "NE\n");
	}

	return 0;
}