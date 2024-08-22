#include <bits/stdc++.h>
using namespace std;

double arr[4][2];
vector<double> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (j == i) continue;
			v.push_back(hypot(arr[i][0] - arr[0][0], arr[i][1] - arr[0][1])
				+ hypot(arr[j][0] - arr[i][0], arr[j][1] - arr[i][1])
				+ hypot(arr[6 - i - j][0] - arr[j][0], arr[6 - i - j][1] - arr[j][1]));
		}
	}

	cout << (int)*min_element(v.begin(), v.end());
	return 0;
}