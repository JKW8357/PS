#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[16];
bool visited[16];
vector<char> vec;
unordered_set<char> vowels = { 'a','e','i','o','u' };

void solve(int num, int depth) {
	if (depth == l) {
		int v_cnt = 0;
		for (char i : vec) if (vowels.count(i)) v_cnt++;
		if (v_cnt >= 1 && l - v_cnt >= 2) {
			for (char i : vec) cout << i;
			cout << '\n';
		}
		return;
	}

	for (int i = num; i < c; i++) {
		vec.push_back(arr[i]);
		solve(i + 1, depth + 1);
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);
	solve(0, 0);

	return 0;
}