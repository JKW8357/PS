#include <bits/stdc++.h>
using namespace std;

char arr[14];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		
		string n1, n2;
		int zerocnt = 0;
		for (int i = 0; i < n - 2; i++)
			if (arr[i] == '0') zerocnt++;

		int rem = zerocnt;
		n1 += arr[zerocnt];
		n2 += arr[zerocnt + 1];

		if (zerocnt > 0) {
			bool flag = true;
			while (true) {
				if (flag) {
					n1 += '0';
					flag = false;
				}
				else{
					n2 += '0';
					flag = true;
				}
				zerocnt--;
				if (zerocnt == 0) break;
			}
		}

		bool flag;
		if (n1.size() != n2.size()) flag = n1.size() < n2.size() ? true : false;
		else flag = n1[0] < n2[0] ? true : false;

		for (int i = rem + 2; i < n; i++) {
			if (flag) {
				n1 += arr[i];
				flag = false;
			}
			else {
				n2 += arr[i];
				flag = true;
			}
		}

		cout << stoi(n1) + stoi(n2) << '\n';
	}

	return 0;
}