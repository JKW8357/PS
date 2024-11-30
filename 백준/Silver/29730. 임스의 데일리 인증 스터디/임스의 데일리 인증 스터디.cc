#include <bits/stdc++.h>
using namespace std;

vector<string> boj, others;

bool cmp1(const string& s1, const string& s2) {
	return stoi(s1.substr(7, 5)) < stoi(s2.substr(7, 5));
}

bool cmp2(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	cin.ignore();

	while (n--) {
		string name; getline(cin, name);
		if (name.substr(0, 7) == "boj.kr/") boj.push_back(name);
		else others.push_back(name);
	}

	sort(boj.begin(), boj.end(), cmp1);
	sort(others.begin(), others.end(), cmp2);

	for (const string& name : others) cout << name << '\n';
	for (const string& name : boj) cout << name << '\n';

	return 0;
}