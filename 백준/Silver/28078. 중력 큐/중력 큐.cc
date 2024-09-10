#include <bits/stdc++.h>
using namespace std;

deque<char> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	int turn = 0;
	int walls = 0;
	while (q--) {
		string cmd1;
		cin >> cmd1;

		if (cmd1 == "push") {
			char cmd2;
			cin >> cmd2;

			if (cmd2 == 'w') {
				walls++;
				dq.push_front('w');
			}

			else if (!dq.empty() && turn % 4 == 1) dq.push_front('b');

			else if (turn % 4 == 0 || turn % 4 == 2) dq.push_front(cmd2);
		}

		else if (cmd1 == "pop") {
			if (!dq.empty()) {
				if (dq.back() == 'w') walls--;
				dq.pop_back();

				if (turn % 4 == 1)
					while (!dq.empty() && dq.back() != 'w') dq.pop_back();

				if (turn % 4 == 3) 
					while (!dq.empty() && dq.front() != 'w') dq.pop_front();
			}
		}

		else if (cmd1 == "rotate") {
			char cmd2;
			cin >> cmd2;

			if (cmd2 == 'r') turn++;
			else turn--;
			
			// 음수 나눗셈은 양수 나눗셈 결과의 음수 값이 되므로 주의
			if (turn < 0) turn = 3;
			if (turn > 3) turn = 0;

			if (turn % 4 == 1)
				while (!dq.empty() && dq.back() != 'w') dq.pop_back();

			else if (turn % 4 == 3)
				while (!dq.empty() && dq.front() != 'w') dq.pop_front();
		}

		else {
			char cmd2;
			cin >> cmd2;

			if (cmd2 == 'b') cout << dq.size() - walls << '\n';
			else cout << walls << '\n';
		}
	}

	return 0;
}