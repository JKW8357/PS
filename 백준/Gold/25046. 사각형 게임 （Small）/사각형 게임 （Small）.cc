#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll arr[20][20];
ll rowSum[20];

void player1(int row, ll& player1Score) {
	for (int i = 0; i < n; i++)
		if (row & (1 << i)) player1Score += rowSum[i];
}

void player2(int row, ll& player1Score) {
	for (int j = 0; j < n; j++) {
		ll extraPlayer1Score = 0;
		ll Player2Score = 0;
		for (int i = 0; i < n; i++) {
			if (row & (1 << i)) {
				extraPlayer1Score -= arr[i][j];
				Player2Score += arr[i][j];
			}
			else {
				extraPlayer1Score += arr[i][j];
				Player2Score -= arr[i][j];
			}
		}
		if (Player2Score > 0) player1Score += extraPlayer1Score;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			rowSum[i] += arr[i][j];
		}
	}

	ll maxPlayer1Score = LLONG_MIN;
	for (int row = 0; row < (1 << n); row++) {
		ll player1Score = 0;
		player1(row, player1Score);
		player2(row, player1Score);
		maxPlayer1Score = max(maxPlayer1Score, player1Score);
	}

	cout << maxPlayer1Score << '\n';
	return 0;
}

/*
비트마스킹을 사용하면 각 행과 열의 선택 상태를 정수 하나로 표현할 수 있으며, 상태 전환이나 조건 체크가 매우 효율적이다.
비트마스킹은 Big-O 관점에서 시간복잡도를 줄여주진 않지만, 연산의 효율성을 크게 향상시켜 상수배로 시간을 절약할 수 있다.

이 문제에서 비트마스킹 여부와 관계없이 시간복잡도는 O(4^N) (N = 18일 때 약 687억 번 연산)이지만,
비트마스킹을 통해 효율적으로 상태를 관리했기 때문에 실질적인 연산 시간이 수백 배에서 수천 배 이상 감소하게 된다.
*/