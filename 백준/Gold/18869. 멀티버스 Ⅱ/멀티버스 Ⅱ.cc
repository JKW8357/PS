#include <bits/stdc++.h>
using namespace std;

int m, n;
int spaces[105][10005];

void compress(int space[]) {
	vector<int> v;
	for (int j = 0; j < n; j++) v.push_back(space[j]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int j = 0; j < n; j++) space[j] = lower_bound(v.begin(), v.end(), space[j]) - v.begin();
}

bool check(int space1[], int space2[]) {
	for (int j = 0; j < n; j++)
		if (space1[j] != space2[j]) return false;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> spaces[i][j];
		compress(spaces[i]);
	}

	int cnt = 0;
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (check(spaces[i], spaces[j])) cnt++;

	cout << cnt << '\n';
	return 0;
}

/*
좌표 압축(compress) 함수는 각 우주의 좌표들을 정렬한 후, 
중복을 제거하고 작은 값들로 재배치하는 역할을 하며, 시간 복잡도는 O(n log n)
두 우주를 비교하는 check 함수는 좌표 압축된 값들을 O(n) 시간 내에 비교 가능
총 시간복잡도: O(n * m^2)
*/