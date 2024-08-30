#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	cin >> word;

	int size = word.size();
	string ans(size, 'z');
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - i; j++) {
			string s1 = word.substr(0, i);
			string s2 = word.substr(i, j);
			string s3 = word.substr(i + j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			ans = min(ans, s1 + s2 + s3);
		}
	}

	cout << ans << '\n';
	return 0;
}

/*
string의 생성자를 통한 초기화 방법 사용
min 함수를 통해 string의 사전순 대소 비교 수행
*/