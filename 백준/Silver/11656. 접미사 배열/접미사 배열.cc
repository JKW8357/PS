#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int size = str.size();
	for (int i = 0; i < size; i++) vec.push_back(str.substr(i, size));
	sort(vec.begin(), vec.end());
	for (string i : vec) cout << i << '\n';

	return 0;
}