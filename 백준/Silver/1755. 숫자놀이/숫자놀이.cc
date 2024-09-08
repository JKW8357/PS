#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> vec;

string num_to_word(int num) {
	string res;
	string word[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	if (num < 10) res += word[num];
	else res += word[num / 10] + word[num % 10];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int  m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) vec.push_back({ num_to_word(i), i });
	sort(vec.begin(), vec.end(), [](auto p1, auto p2) { return p1 < p2; });
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second << ' ';
		if (i % 10 == 9) cout << '\n';
	}

	return 0;
}