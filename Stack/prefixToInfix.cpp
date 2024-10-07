#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToInfix(string prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            string operand(1, prefix[i]);
            s.push(operand);
        }
        else if (isOperator(prefix[i])) {
            string operand1 = s.top(); s.pop();
            string operand2 = s.top(); s.pop();

            string expression = "(" + operand1 + prefix[i] + operand2 + ")";

            s.push(expression);
        }
    }

    return s.top();
}

int32_t main(){

    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}