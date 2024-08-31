#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> s = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		ll tmp = cur - i;
		cur = ((tmp < 0 || s.count(tmp)) ? cur + i : tmp);
		s.insert(cur);
	}

	cout << cur << '\n';
	return 0;
}

/*
불필요한 배열을 사용하지 않고, 변수 2개로 해결
*/