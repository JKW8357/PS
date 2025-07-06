#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
bool board[MX + 5][MX + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int t = 0; t < 4; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				board[i][j] = true;
	}

	int res = 0;
	for (int i = 1; i < 100; i++)
		for (int j = 1; j < 100; j++)
			if (board[i][j]) res++;
	
	cout << res << '\n';
	return 0;
}