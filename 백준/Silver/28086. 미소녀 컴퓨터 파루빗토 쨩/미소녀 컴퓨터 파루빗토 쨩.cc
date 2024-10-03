#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	long long num1, num2, ans;
	char op;
	cin >> oct >> num1 >> op >> oct >> num2;

	if (op == '+') ans = num1 + num2;
	else if (op == '-') ans = num1 - num2;
	else if (op == '*') ans = num1 * num2;
	else if (op == '/') {
		if (num2 == 0) {
			cout << "invalid\n";
			return 0;
		}
		else ans = floor(double(num1) / num2);
	}

	if (ans < 0) cout << "-";
	cout << oct << abs(ans);
	return 0;
}

/*
고정된 포맷의 입력을 처리할 때는 굳이 문자열을 통해 복잡하게 파싱할 필요가 없이, 
C++의 입출력 조작자(cin, cout)를 활용하면 훨씬 더 간단하고 효율적으로 파싱할 수 있다.

cin은 기본적으로 공백을 구분자로 사용하지만, 숫자와 문자의 조합을 입력할 때
cin은 타입에 따라 입력을 숫자와 문자로 구분해 적절한 변수에 값을 저장한다.
*/

/*
고정된 포맷의 입력을 처리할 때는 굳이 문자열을 통해 복잡하게 파싱할 필요가 없다.
특히 숫자와 연산자를 직접 다루는 경우, C++의 입출력 조작자(cin, cout)를 활용하면 훨씬 더 간단하고 효율적으로 파싱할 수 있다.
*/
