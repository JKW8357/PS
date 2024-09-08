#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

bool cmp(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		string tmp;
		for (char c : str) {
			if (isdigit(c)) tmp += c;
			else if (!tmp.empty()) {
				while (*tmp.begin() == '0' && tmp.size() > 1) tmp.erase(0, 1);
				vec.push_back(tmp);
				tmp.clear();
			}
		}
		if (!tmp.empty()) {
			while (*tmp.begin() == '0' && tmp.size() > 1) tmp.erase(0, 1);
			vec.push_back(tmp);
		}
	}

	sort(vec.begin(), vec.end(), cmp);
	for (const string& i : vec) cout << i << '\n';
	return 0;
}