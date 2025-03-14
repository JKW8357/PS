#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		queue<int> D, P;
		queue<int> Q;
		vector<int> sortedArr = { 0 };

		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			Q.push(num);
		}

		bool outerFlag = true;

		while (!Q.empty()) {
			if (!D.empty() && (D.front() == sortedArr.back() + 1)) {
				while (!D.empty()) {
					sortedArr.push_back(D.front());
					D.pop();
				}
			}
			if (!P.empty() && (P.front() == sortedArr.back() + 1)) {
				while (!P.empty()) {
					sortedArr.push_back(P.front());
					P.pop();
				}
			}

			bool flag = false;

			if (Q.front() == sortedArr.back() + 1) {
				sortedArr.push_back(Q.front());
				Q.pop();
				flag = true;
			}
			else if (!D.empty() && Q.front() == D.back() + 1) {
				D.push(Q.front());
				Q.pop();
				flag = true;
			}
			else if (!P.empty() && Q.front() == P.back() + 1) {
				P.push(Q.front());
				Q.pop();
				flag = true;
			}
			else if (D.empty()) {
				D.push(Q.front());
				Q.pop();
				flag = true;
			}
			else if (P.empty()) {
				P.push(Q.front());
				Q.pop();
				flag = true;
			}

			if (!flag) {
				outerFlag = false;
				break;
			}
		}

		cout << (outerFlag ? "YES" : "NO") << '\n';
	}

	return 0;
}