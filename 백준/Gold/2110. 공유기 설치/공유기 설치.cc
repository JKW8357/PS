#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[200005];

// 최적화 문제를 결정 문제로 전환
// 공유기를 C개 설치할 때, 가장 인접한 두 공유기 사이의 거리의 최댓값은 얼마인가?
// -> 가장 인접한 두 공유기 사이의 거리가 num 이상일 때 공유기를 C개 설치할 수 있는가?
bool param(int num) {
	int cnt = 1;
	int cur = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] - cur >= num) {
			cur = arr[i];
			cnt++;
		}
	}

	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int lo = 0, hi = 1e10 + 1;
	while (lo + 1 < hi) {
		int mid = midpoint(lo, hi);
		if (param(mid)) lo = mid;
		else hi = mid;
	}

	cout << lo << '\n';
	return 0;
}

/*
첫 번째 집에 반드시 공유기를 설치해야 하는 이유: 그리디 전략에 기반

첫 번째 집에 공유기를 설치하지 않고 최적해를 구했다고 가정하자.
가장 왼쪽에 설치된 공유기를 첫 번째 집으로 옮겨도 최소 거리(인접한 두 공유기 사이의 거리)는 줄지 않는다.

오히려 첫 번째 집에 공유기를 설치함으로써 최소 거리가 유지되거나 늘어나기 때문에,
첫 번째 집에 공유기를 설치하는 것이 항상 최적해를 보장한다.

따라서 첫 번째 집에 공유기를 설치한다고 가정해도 무방하다.
*/