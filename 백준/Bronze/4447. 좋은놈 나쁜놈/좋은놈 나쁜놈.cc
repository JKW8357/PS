#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	// cin 이후 getline을 사용할 때, cin은 개행 문자를 버퍼에 그대로 남겨 두기 때문에, 
	// 바로 다음 getline으로 입력을 받을 때 버퍼에 있던 개행 문자가 그대로 입력돼버리는 문제가 발생
	// 따라서 cin.ignore()를 통해 개행 문자를 무시해야 정상적인 입력이 가능

	while (n--) {
		string name;
		getline(cin, name);
		
		int good = 0, bad = 0;
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == 'G' || name[i] == 'g') good++;
			if (name[i] == 'B' || name[i] == 'b') bad++;
		}

		cout << name << ' ';
		if (good > bad) cout << "is GOOD" << '\n';
		else if (good < bad) cout << "is A BADDY" << '\n';
		else cout << "is NEUTRAL" << '\n';
	}

	return 0;
}