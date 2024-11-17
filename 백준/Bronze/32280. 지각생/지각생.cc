#include <bits/stdc++.h>
using namespace std;

vector<string> arrivalTime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string time1, time2;

	for (int i = 0; i < n + 1; i++) {
		string time, classMember;
		cin >> time >> classMember;
		if (classMember == "student") arrivalTime.push_back(time);
		else time1 = time;
	}
	cin >> time2;
	sort(arrivalTime.begin(), arrivalTime.end());

	int cnt = 0;
	for (const auto& time : arrivalTime)
		if (time >= time1 && time >= time2) cnt++;
	cout << cnt << '\n';

	return 0;
}