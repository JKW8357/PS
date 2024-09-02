#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> jewels;
multiset<int> bags;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int weight, value;
		cin >> weight >> value;
		jewels.push_back({ weight, value });
	}
	sort(jewels.begin(), jewels.end(), cmp);

	for (int i = 0; i < k; i++) {
		int capacity;
		cin >> capacity;
		bags.insert(capacity);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = bags.lower_bound(jewels[i].first);

		// bags가 빈 경우 (즉, 모든 가방에 보석을 넣은 경우) it == bags.end()가 되어
		// 해당 보석을 처리하지 않고 넘어가므로 문제가 발생하지 않음
		if (it != bags.end()) {
			bags.erase(it);
			ans += jewels[i].second;
		}
	}

	cout << ans << '\n';
	return 0;
}

/*
가치가 가장 높은 보석부터 순차적으로 확인한다.
이때, 해당 보석을 넣을 수 있는 가방 중에서 수용량이 가장 작은 것을 이분 탐색을 통해 찾고 선택한다.
가방을 선택한 후에는 해당 가방을 배제해야 하는데,
배열에서 단순히 제거하는 경우에는 O(K)의 시간이 소요된다.
또한, bool 변수를 사용하여 가방을 선택했는지 여부를 표시하더라도 최악의 경우 여전히 O(K)의 시간이 걸린다.
따라서, 이분 탐색과 제거가 모두 O(logK)에 수행 가능한 multiset 자료구조를 사용하는 것이 더 효율적이다.
*/