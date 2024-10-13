#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int cmd; cin >> cmd;
		string str; cin >> str;
		vector<int> nums;

		if (cmd == 1) {
			stringstream ss(str); string num;
			while (getline(ss, num, '.')) { nums.push_back(stoull(num)); }

			ull output = 0;
			for (int i = 0; i < 8; i++) output += (nums[i] * (1ULL << (8 * (7 - i))));
			cout << output << '\n';
		}

		else {
			ull num = stoull(str);
			for (int i = 0; i < 8; i++) {
				nums.push_back(num & ((1ULL << 8) - 1));
				num >>= 8;
			}

			reverse(nums.begin(), nums.end());
			for (int i = 0; i < 7; i++) cout << nums[i] << '.';
			cout << nums[7] << '\n';
		}
	}

	return 0;
}