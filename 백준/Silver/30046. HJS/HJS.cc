#include <bits/stdc++.h>
using namespace std;


bool check(const string& P, const string& Q, const string& R, unordered_map<char, int>& um) {
	int n = P.size();
	string p = P;
	string q = Q;
	string r = R;
	for (int i = 0; i < n; i++) {
		p[i] = um[P[i]] + '0';
		q[i] = um[Q[i]] + '0';
		r[i] = um[R[i]] + '0';
	}
	if (p < q && q < r) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string P, Q, R;
	cin >> n >> P >> Q >> R;

	vector<int> digits = { 1,2,3 };

	do {
		unordered_map<char, int> um;
		um['H'] = digits[0];
		um['J'] = digits[1];
		um['S'] = digits[2];

		if (check(P, Q, R, um)) {
			cout << "HJS! HJS! HJS!" << '\n';
			return 0;
		}

	} while (next_permutation(digits.begin(), digits.end()));

	cout << "Hmm...\n";
	return 0;
}