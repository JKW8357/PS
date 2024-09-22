#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	for (char c : str) arr[c - 'a']++;
	for (int i : arr) cout << i << ' ';

	return 0;
}