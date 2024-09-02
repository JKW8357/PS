#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

void parser(const string& str, deque<int>& dq) {
	int st = 0, len = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '[') continue;

		else if (str[i] == ']') {
			if (len == 0) continue;
			else {
				int num = stoi(str.substr(st + 1, len));
				dq.push_back(num);
			}
		}

		else if (isdigit(str[i])) len++;

		else {
			int num = stoi(str.substr(st + 1, len));
			dq.push_back(num);
			st = i;
			len = 0;
		}
	}
}

void show(const deque<int>& dq, bool isreversed) {
	cout << '[';
	for (int i = 0; i < dq.size(); i++) {
		if (!isreversed) cout << dq[i];
		else cout << dq[dq.size() - 1 - i];

		if (i != dq.size() - 1) cout << ",";
	}
	cout << ']' << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		string cmd, str;
		cin >> cmd >> n >> str;

		dq.clear();
		parser(str, dq);

		bool isreversed = false, error = false;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') isreversed = !isreversed;
			
			else {
				if (dq.empty()) {
					cout << "error\n";
					error = true;
					break;
				}

				else isreversed ? dq.pop_back() : dq.pop_front();
			}
		}

		if (!error) show(dq, isreversed);
	}

	return 0;
}

/*
reverse() 함수의 시간복잡도는 O(N)으로, 
R 명령을 처리할 때 reverse() 함수를 반복적으로 사용하면 TLE가 발생할 가능성이 높다. 
따라서 reverse() 함수를 사용하지 않고 R 명령을 처리하는 방법을 고려해야 한다. 
deque는 양쪽 끝에서의 데이터 삭제를 O(1)에 처리할 수 있는 성질을 이용해, 
isreversed를 사용하여 R 명령을 효율적으로 처리한다.
*/