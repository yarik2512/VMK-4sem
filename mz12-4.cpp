#include <iostream>
#include <map>
#include <vector>

int main() {
    using std::string, std::map, std::vector;
    using std::cin, std::cout, std::endl;
    int pos = 1;
    vector<string> bobr;
    map<string, int> l;
    string cmd;
    while (cin >> cmd) {
        if (cmd.back() == ':') {
            l[cmd.substr(0, cmd.length() - 1)] = pos;
        } else {
            bobr.push_back(cmd);
            ++pos;
        }
    }
    for (const string &cmd: bobr) {
        auto p = l.find(cmd);
        if (p != l.end()) {
            cout << p->second << endl;
        } else {
            cout << cmd << endl;
        }
    }
    return 0;
}
