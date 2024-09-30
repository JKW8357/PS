#include <bits/stdc++.h>
using namespace std;

int A[105][105];
int B[105][105];
int M[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	int tmp, k;
	cin >> tmp >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> B[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < m; l++)
				M[i][j] += A[i][l] * B[l][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) cout << M[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}