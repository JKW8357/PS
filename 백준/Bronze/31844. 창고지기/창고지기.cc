#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int robot, box, goal;
	for (int i = 0; i < 10; i++) {
		if (str[i] == '@') robot = i;
		if (str[i] == '#') box = i;
		if (str[i] == '!') goal = i;
	}

	cout << ((robot < box && box < goal) || (goal < box && box < robot) ? abs(goal - robot) - 1 : -1) << '\n';

	return 0;
}