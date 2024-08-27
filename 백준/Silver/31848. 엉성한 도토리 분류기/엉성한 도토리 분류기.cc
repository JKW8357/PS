#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<p> holes;
int acorns[100005];
int min_holes[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		holes.push_back({ num + i, i + 1 });
	}
	sort(holes.begin(), holes.end());

	min_holes[n - 1] = holes[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		min_holes[i] = min(holes[i].second, min_holes[i + 1]);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> acorns[i];
		auto it = lower_bound(holes.begin(), holes.end(), acorns[i], [](p a, int b) { return a.first < b; });
		int idx = it - holes.begin();
		cout << min_holes[idx] << ' ';
	}

	return 0;
}