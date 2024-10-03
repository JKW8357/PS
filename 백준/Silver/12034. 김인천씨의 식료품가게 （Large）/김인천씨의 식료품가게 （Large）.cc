#include <bits/stdc++.h>
using namespace std;

multiset<int> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		for (int i = 0; i < n * 2; i++) {
			int num;
			cin >> num;
			ms.insert(num);
		}

		cout << "Case #" << t << ": ";
		while (n--) {
			int discount = *ms.begin();
			cout << discount << ' ';
			ms.erase(ms.find(discount / 3 * 4));
			ms.erase(ms.begin());
		}

		cout << '\n';
	}

	return 0;
}