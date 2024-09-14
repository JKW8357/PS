#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool solved = false;
int arr[10][10];
bool isused1[10][10]; // isused1[row][num]: 행에서 num이 쓰였는지 확인
bool isused2[10][10]; // isused2[col][num]: 열에서 num이 쓰였는지 확인
bool isused3[10][10]; // isused3[box][num]: 3 * 3 박스에서 num이 쓰였는지 확인
vector<pair<int, int>> blanks;

bool check(int row, int col, int num) {
	return !isused1[row][num] && !isused2[col][num] && !isused3[row / 3 * 3 + col / 3][num];
}

void solve(int depth) {
	if (depth == blanks.size()) {
		if (!solved) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << arr[i][j] << ' ';
				cout << '\n';
			}
			solved = true;
		}
		return;
	}

	int row = blanks[depth].X;
	int col = blanks[depth].Y;
	for (int num = 1; num <= 9; num++) {
		if (solved) return;
		if (check(row, col, num)) {
			arr[row][col] = num;
			isused1[row][num] = true;
			isused2[col][num] = true;
			isused3[row / 3 * 3 + col / 3][num] = true;
			solve(depth + 1);
			isused1[row][num] = false;
			isused2[col][num] = false;
			isused3[row / 3 * 3 + col / 3][num] = false;
			arr[row][col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) blanks.push_back({ i, j });
			else {
				isused1[i][arr[i][j]] = true;
				isused2[j][arr[i][j]] = true;
				isused3[i / 3 * 3 + j / 3][arr[i][j]] = true;
			}
		}
	}

	solve(0);
	return 0;
}

/*
isused1, isused2, isused3 배열을 통해
행, 열, 3x3 박스에서 특정 숫자의 사용 여부를 미리 기록하고,
이를 이용해 중복된 검사를 피함으로써 탐색 범위를 줄인다.

각 칸에 숫자를 넣기 전에 이미 사용된 숫자는 즉시 배제하는 효율적인 가지치기를 통해
불필요한 재귀 호출을 방지하고, 더 빠르게 정답을 찾을 수 있다.
(N-Queen 문제의 코드 참고)
*/