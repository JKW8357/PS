#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	string max = "";
	string min = "";
	int cnt_m = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'M') { 
			if (cnt_m == 0) {
				min += '1';
				max += '1';
			}
			else if (cnt_m > 0) {
				min += '0';
				max += '1';
			}
			cnt_m++;
		}

		else {
			min += '5';
			max.erase(max.begin() + i - cnt_m, max.end());
			max += '5';
			for (int i = 0; i < cnt_m; i++) max += '0';
			cnt_m = 0;
		}
	}

	cout << max << '\n' << min << '\n';
	return 0;
}