#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;
int arr[10005];

bool param(ll num) {
	ll sum = 0;
	for (int i = 0; i < k; i++) sum += arr[i] / num;
	return sum >= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> arr[i];

	// 항상 정답의 범위를 포함하도록 lo, hi의 초기값을 잘 설정하는 것이 중요
	// 정답의 범위: 2^31-1보다 작거나 같은 자연수
	// hi = 2^31-1보다 큰 값으로 설정
	ll lo = 1, hi = pow(2, 31);
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (param(mid)) lo = mid;
		else hi = mid;
	}

	cout << lo << '\n';
	return 0;
}

/*
이분 탐색의 구현에서는 초기 lo와 hi를 설정할 때, 
Check(lo)와 Check(hi)가 서로 다른 값을 가지도록 설정합니다. 
그런 다음 lo + 1 < hi인 동안 mid = (lo + hi) / 2를 계산하여, 
Check(lo) == Check(mid)인 경우 lo = mid로, 
Check(hi) == Check(mid)인 경우 hi = mid로 설정합니다.

초기 상태에서 lo와 hi는 Check(lo) != Check(hi)이므로,
답이 바뀌는 경계가 [lo, hi] 구간 내에 존재함이 보장됩니다.

이후 lo + 1 < hi인 동안 [lo, hi] 구간을 [lo, mid] 또는 [mid, hi]로 좁혀나갑니다. 
이 과정에서 Check(lo)와 Check(hi)의 값은 바뀌지 않습니다.
이는 lo = mid 또는 hi = mid로 이동하는 방식 덕분입니다.
또한, lo + 1 < hi이기 때문에 lo와 hi 사이에는
항상 하나 이상의 중간 값(mid)이 존재하게 되며, 매번 구간의 길이가 절반씩 줄어듭니다.
결국 lo + 1 == hi가 되어 반복문이 종료됩니다.

(반복문이 종료되면 lo < hi 조건이 성립하며, lo + 1 == hi가 됩니다.)

이분 탐색이 종료되면 lo와 hi는 결정 문제의 답이 바뀌는 경계에 위치하게 됩니다.
만약 결정 문제의 답이 F에서 T로 바뀐다면, 가장 큰 F는 lo에, 가장 작은 T는 hi에 위치하게 됩니다.
반대로 결정 문제의 답이 T에서 F로 바뀐다면, 가장 큰 T는 lo에, 가장 작은 F는 hi에 위치하게 됩니다.
따라서 원하는 답에 따라 lo 또는 hi를 반환합니다.

<주의사항>
1. lo와 hi는 항상 정답의 범위를 포함하도록 lo, hi의 초기값을 잘 설정해야 합니다.
   예를 들어, lo를 출력해야 하는 문제에서 답의 최대값이 n이라면,
   hi는 n으로 설정하지 않고 n보다 큰 값으로 설정해야 합니다.
   반대로, hi를 출력해야 하는 문제에서 답의 최소값이 0이라면,
   lo를 0으로 설정하지 않고 0보다 작은 값으로 설정해야 합니다.
   이렇게 설정함으로써, lo와 hi가 정답의 경계에 위치하게 할 수 있습니다.

2. 오버플로에 주의해야 합니다.
   이분 탐색을 사용하는 문제는 대부분 탐색 범위가 크기 때문에,
   lo와 hi의 합을 계산할 때 오버플로가 발생할 수 있습니다.

3. 결정 문제에 맞게 Check 함수를 정확히 구현해야 합니다.
   예를 들어, lower_bound는 v[i] >= k인 i의 최솟값을 구하는 반면,
   upper_bound는 v[i] > k인 i의 최솟값을 구합니다.
   Check 함수의 부등호가 잘못 구현되면, 전혀 엉뚱한 값이 출력될 수 있습니다.
   따라서 부등호 방향과 조건을 정확하게 설정해야 합니다.

Reference : https://www.acmicpc.net/blog/view/109
*/