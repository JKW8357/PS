#include <bits/stdc++.h>
using namespace std;

vector<bool> state(2000001, true);
void sieve() {
	state[1] = false;
	for (int i = 2; i * i <= 2000000; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= 2000000; j += i)
			state[j] = false;
	}
}

bool ispalindrome(int n) {
	string num = to_string(n);
	string rev_num = num;
	reverse(rev_num.begin(), rev_num.end());
	return num == rev_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	sieve();
	for (int i = n; i <= 2000000; i++) {
		if (state[i] && ispalindrome(i)) {
			cout << i << '\n';
			return 0;
		}
	}
}

/*
참고:
1000000 이상의 가장 작은 팰린드롬 소수는 1003001
따라서 탐색 범위는 최소 1003001 이상으로 설정해야 하며,
state 배열의 크기는 이 범위를 포함하도록 충분히 크게 설정해야 함
*/