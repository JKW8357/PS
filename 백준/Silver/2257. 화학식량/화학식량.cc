#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string chem; cin >> chem;
    for (char c : chem) {
        if (c == '(') st.push(-1);
        else if (c == 'H') st.push(1);
        else if (c == 'C') st.push(12);
        else if (c == 'O') st.push(16);
        else if (c == ')') {
            int s = 0;
            while (st.top() != -1) {
                s += st.top();
                st.pop();
            }
            st.pop();
            st.push(s);
        }
        else st.top() *= (c - '0');
    }

    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    cout << res << '\n';
    return 0;
}