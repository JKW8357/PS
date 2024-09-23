#include <bits/stdc++.h>
using namespace std;

char arr[20][20];
string name[3] = { "chunbae", "nabi", "yeongcheol" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'w') ans = 0;
			else if (arr[i][j] == 'b') ans = 1;
			else if (arr[i][j] == 'g') ans = 2;
		}
	}

	cout << name[ans] << '\n';
	return 0;
}