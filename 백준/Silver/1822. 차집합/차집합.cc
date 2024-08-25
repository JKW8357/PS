#include <bits/stdc++.h>
using namespace std;

int a[500005];
int b[500005];
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int na, nb;
	cin >> na >> nb;
	for (int i = 0; i < na; i++) cin >> a[i];
	for (int i = 0; i < nb; i++) cin >> b[i];
	sort(b, b + nb);

	for (int i = 0; i < na; i++)
		if (!binary_search(b, b + nb, a[i])) v.push_back(a[i]);
	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	if (v.size() > 0)
		for (auto i : v) cout << i << ' ';

	return 0;
}