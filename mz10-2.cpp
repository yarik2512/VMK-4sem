#include <iostream>
#include <map>
#include <set>

int
main()
{
    using std::cin, std::cout, std::endl, std::string, std::multimap, std::pair, std::set;
    char left;
    string right;
    multimap<char, string> G;
    multimap<char, string> R;
    set<char> v_prev = {'S'};
    set<char> v = v_prev;
    while (cin >> left >> right) {
        G.insert({left, right});
    }
    while (true) {
        for (const auto &A : v_prev) {
            auto rules = G.equal_range(A);
            for (auto rule = rules.first; rule != rules.second; ++rule) {
                for (char c : rule->second) {
                    v.insert(c);
                }
            }
        }
        if (v == v_prev) {
            break;
        }
        v_prev = v;
    }
    for (const auto &rule : G) {
        if (!v.contains(rule.first)) {
            continue;
        }
        bool insert = true;
        for (char c: rule.second) {
            if (!v.contains(c)) {
                insert = false;
                break;
            }
        }
        if (insert) {
            R.insert(rule);
        }
    }
    for (const auto &rule: R) {
        cout << rule.first << " " << rule.second << endl;
    }
    return 0;
}
