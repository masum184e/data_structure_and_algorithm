#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToPostfix(string prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            string operand(1, prefix[i]);
            s.push(operand);
        }else if (isOperator(prefix[i])) {
            string operand1 = s.top(); s.pop();
            string operand2 = s.top(); s.pop();

            string expression = operand1 + operand2 + prefix[i];

            s.push(expression);
        }
    }

    return s.top();
}

int32_t main(){

    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}