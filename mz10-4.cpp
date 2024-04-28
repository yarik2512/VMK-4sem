#include <iostream>
#include <stack>
#include <map>

int main() {
    using std::stack, std::map, std::string, std::cin, std::cout, std::endl;
    map<char, int> priors = {
        {'(', 6},
        {'*', 1},
        {'/', 1},
        {'+', 2},
        {'-', 2},
        {'&', 3},
        {'^', 4},
        {'|', 5},
    };
    stack<char> ops;
    string cops = "*/+-&^|";
    string bobr;
    string input;
    cin >> input;
    input = '(' + input + ')';
    for (char c: input) {
        if (cops.contains(c)) {
            int prior = priors[c];
            while (!ops.empty() && priors[ops.top()] <= prior) {
                bobr += ops.top();
                ops.pop();
            }
            ops.push(c);
        } else if (c == '(') {
            ops.push('(');
        } else if (c == ')') {
            while (ops.top() != '(') {
                bobr += ops.top();
                ops.pop();
            }
            ops.pop();
        } else {
            bobr += c;
        }
    }
    stack<int> ops_priors;
    stack<string> res;
    for (char c: bobr) {
        if (cops.contains(c)) {
            int p = priors[c];
            int p2 = ops_priors.top();
            ops_priors.pop();
            int p1 = ops_priors.top();
            ops_priors.pop();
            ops_priors.push(p);
            string op2;
            if (p2 >= p) {
                op2 = "(" + res.top() + ")";
            } else {
                op2 = res.top();
            }
            res.pop();
            string op1;
            if (p1 > p) {
                op1 = "(" + res.top() + ")";
            } else {
                op1 = res.top();
            }
            string tmp = op1;
            tmp.push_back(c);
            tmp += op2;
            res.pop();
            res.push(tmp);
        } else {
            ops_priors.push(0);
            res.emplace(1, c);
        }
    }
    cout << res.top() << endl;
    return 0;
}
