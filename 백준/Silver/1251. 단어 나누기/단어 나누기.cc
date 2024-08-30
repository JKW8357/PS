#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	cin >> word;

	int size = word.size();
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - i; j++) {
			string s1 = word.substr(0, i);
			string s2 = word.substr(i, j);
			string s3 = word.substr(i + j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			vec.push_back(s1 + s2 + s3);
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec[0] << '\n';
	return 0;
}