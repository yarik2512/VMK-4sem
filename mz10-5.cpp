#include <iostream>
#include <stack>

using std::cin, std::cout, std::stack, std::endl, std::string, std::getline;

void
bobr(stack<string> &s, string &input, string::size_type i = 0)
{
    for (; i < input.size() && input[i] == ' '; ++i);
    if (i == input.size()) {
        return;
    }
    string v1, v2;
    switch (input[i]) {
    case '+':
        v2 = s.top();
        s.pop();
        v1 = s.top();
        s.pop();
        s.push("(" + v1 + "+" + v2 + ")");
        break;
    case '-':
        v2 = s.top();
        s.pop();
        v1 = s.top();
        s.pop();
        s.push("(" + v1 + "-" + v2 + ")");
        break;
    case '*':
        v2 = s.top();
        s.pop();
        v1 = s.top();
        s.pop();
        s.push("(" + v1 + "*" + v2 + ")");
        break;
    case '/':
        v2 = s.top();
        s.pop();
        v1 = s.top();
        s.pop();
        s.push("(" + v1 + "/" + v2 + ")");
        break;
    default:
        s.emplace(1, input[i]);
        break;
    }
}

int
main()
{
    string input;
    getline(cin, input);
    string ops = "+-*/";
    stack<string> s;
    for (string::size_type i = 0; i < input.size(); ++i) {
        for (; i < input.size() && input[i] == ' '; ++i);
        if (i == input.size()) {
            break;
        }
        string v1, v2;
        if (ops.contains(input[i])) {
            v2 = s.top();
            s.pop();
            v1 = s.top();
            s.pop();
            s.emplace("(" + v1 + input[i] + v2 + ")");
        } else {
            s.emplace(1, input[i]);
        }
    }
    cout << s.top() << endl;
    return 0;
}
