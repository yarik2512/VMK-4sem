#include <iostream>
#include <map>
#include <set>

using std::string, std::cin, std::cout, std::endl, std::map, std::set, std::pair;

string analyse(map<string, map<char, string>> &G, const string &state, const string &s, string::size_type i) {
    if (i == s.size()) {
        return state;
    }
    auto it = G[state].find(s[i]);
    if (it == G[state].end()) {
        throw pair(i, state);
    }
    return analyse(G, it->second, s, i + 1);
}

int main()
{
    map<string, map<char, string>> G;
    set<string> E;
    string S;
    string input;
    string cur_s, new_s;
    char char_c;
    while (cin >> cur_s) {
        if (cur_s == "END") {
            break;
        }
        cin >> char_c >> new_s;
        G[cur_s][char_c] = new_s;
    }
    string state;
    while (cin >> state) {
        if (state == "END") {
            break;
        }
        E.insert(state);
    }
    cin >> S;
    cin >> input;
    try {
        string e = analyse(G, S, input, 0);
        if (!E.contains(e)) {
            throw pair(input.size(), e);
        }
        cout << 1 << endl << input.size() << endl << e << endl;
    }
    catch (const pair<string::size_type, string> &e) {
        cout << 0 << endl << e.first << endl << e.second << endl;
    }
    return 0;
}
