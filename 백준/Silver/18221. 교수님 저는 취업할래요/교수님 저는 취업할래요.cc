#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int classroom[1005][1005];
int friends = 0;
pair<int, int> student, professor;
bool canEscape = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> classroom[i][j];
			if (classroom[i][j] == 2) student = { i, j };
			if (classroom[i][j] == 5) professor = { i, j };
		}
	}

	int max_x = max(student.X, professor.X);
	int min_x = min(student.X, professor.X);
	int max_y = max(student.Y, professor.Y);
	int min_y = min(student.Y, professor.Y);

	if (hypot(max_x - min_x, max_y - min_y) < 5) canEscape = false;
		
	for (int i = min_x; i <= max_x; i++)
		for (int j = min_y; j <= max_y; j++)
			if (classroom[i][j] == 1) friends++;

	if (friends < 3) canEscape = false;
	cout << (canEscape ? 1 : 0) << '\n';

	return 0;
}