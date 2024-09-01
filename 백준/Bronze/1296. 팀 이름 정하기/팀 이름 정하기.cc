#include <bits/stdc++.h>
using namespace std;

int arr[4];
vector<pair<int, string>> vec;

void countlove(string teamname, int arr[]) {
	for (int i = 0; i < teamname.size(); i++) {
		if (teamname[i] == 'L') arr[0]++;
		if (teamname[i] == 'O') arr[1]++;
		if (teamname[i] == 'V') arr[2]++;
		if (teamname[i] == 'E') arr[3]++;
	}
}

bool cmp(pair<int, string> p1, pair<int, string> p2) {
	if (p1.first != p2.first) return p1.first > p2.first;
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string yeondoo, teamname;
	cin >> yeondoo >> n;

	while (n--) {
		cin >> teamname;
		fill(arr, arr + 4, 0);
		
		countlove(yeondoo, arr);
		countlove(teamname, arr);

		int probability = 1;
		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 4; j++)
				probability *= (arr[i] + arr[j]);
		probability %= 100;
		vec.push_back({ probability, teamname });
	}

	sort(vec.begin(), vec.end(), cmp);
	cout << vec[0].second << '\n';

	return 0;
}