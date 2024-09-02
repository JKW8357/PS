#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	string max_str = "";
	string min_str = "";
	int cnt_m = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'M') { 
			min_str += (cnt_m == 0) ? '1' : '0';
			max_str += '1';
			cnt_m++;
		}

		else {
			min_str += '5';
			max_str.erase(max_str.end() - cnt_m, max_str.end());
			max_str += '5';
			for (int i = 0; i < cnt_m; i++) max_str += '0';
			cnt_m = 0;
		}
	}

	cout << max_str << '\n' << min_str << '\n';
	return 0;
}