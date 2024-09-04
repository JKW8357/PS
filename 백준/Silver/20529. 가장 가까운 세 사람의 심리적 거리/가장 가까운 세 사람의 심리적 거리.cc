#include <bits/stdc++.h>
using namespace std;

string mbti[100005];

int dist(const string& mbti1, const string& mbti2) {
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		if (mbti1[i] != mbti2[i]) cnt++;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> mbti[i];
		
		if (n > 32) {
			cout << 0 << '\n';
			continue;
		}

		else {
			int ans = INT_MAX;
			for (int i = 0; i < n - 2; i++)
				for (int j = i + 1; j < n - 1; j++)
					for (int k = j + 1; k < n; k++)
						ans = min(ans, dist(mbti[i], mbti[j]) + dist(mbti[j], mbti[k]) + dist(mbti[i], mbti[k]));

			cout << ans << '\n';
		}
	}

	return 0;
}

/*
비둘기집 원리:
n+1개의 물건을 n개의 상자에 넣을 때, 적어도 하나의 상자에는 두 개 이상의 물건이 들어감
일반화: kn+1개의 물건을 n개의 상자에 넣을 때, 적어도 하나의 상자에는 반드시 k+1개 이상의 물건이 들어감

MBTI는 최대 16가지이므로 n > 32일 경우 모든 경우의 수 중 3명의 MBTI가 모두 일치하는 경우가 반드시 존재
따라서 n > 32일 때는 가장 가까운 세 사람의 심리적 거리는 0으로 고정
완전 탐색 시 경우의 수가 매우 많을 때, 비둘기집 원리 적용이 가능할 경우 문제를 효율적으로 해결 가능
*/