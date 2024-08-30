#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
vector<int> ans;

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

	for (int num : vec) {
		auto pos = lower_bound(ans.begin(), ans.end(), num);
		if (pos == ans.end()) ans.push_back(num);
		else *pos = num;
	}

	cout << ans.size() << '\n';
	return 0;
}

/*
LIS에서 현재 원소의 lower_bound 위치 pos를 구한다.
만약 pos가 LIS.end()라면 (현재 원소가 LIS의 가장 큰 원소일 경우) 현재 원소를 LIS의 끝에 추가한다.
그렇지 않을 경우, pos 위치의 원소를 현재 원소로 대체한다. (이때 *pos를 더 작은 값으로 갱신)

이렇게 작은 값으로 대체함으로써 LIS 배열을 오름차순으로 유지하여
이분 탐색을 효율적으로 수행할 수 있고, 이후 원소들이 더 긴 LIS에 포함될 가능성을 높인다.

또 주의할 점은, ans 배열은 단순히 LIS의 길이를 구하기 위한 보조 배열이지, 실제 LIS가 아니라는 것이다.
반례: [3, 5, 7, 1, 2, 8]
ans: [1, 2, 7, 8]
LIS: [3, 5, 7, 8]

시간 복잡도: O(NlogN)
*/
