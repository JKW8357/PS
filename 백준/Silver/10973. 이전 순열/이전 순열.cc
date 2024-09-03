#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	if (prev_permutation(vec.begin(), vec.end())) {
		for (int i : vec) cout << i << ' ';
		cout << '\n';
	}

	else cout << -1 << '\n';
	return 0;
}

/*
<algorithm> 헤더의 next_permutation, prev_permutation:
vector, deque, list, string 등에서 iterator과 함께 사용 가능.
다음 순열 또는 이전 순열로 재배열하고, 가능하면 true, 없으면 false를 반환.
모든 순열을 탐색하려면:
next_permutation: 사전순으로 가장 앞서는 순서로 초기화해야 함.
prev_permutation: 사전순으로 가장 마지막 순서로 초기화해야 함.
재배열 시간 복잡도 : O(N), 총 시간 복잡도 : O(N* N!)
*/