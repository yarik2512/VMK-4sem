#include <iostream>
#include <map>

int main() {
    using std::cout, std::cin, std::endl, std::map, std::pair, std::string;
    map<string, pair<int, int>> students;
    string name;
    int mark;
    while (cin >> name >> mark) {
        if (!students.contains(name)) {
            students.insert({name, {mark, 1}});
        } else {
            students[name].first += mark;
            ++students[name].second;
        }
    }
    for (const pair<const string, pair<int, int>> &x: students) {
        cout << x.first << ' ' << (double) x.second.first / x.second.second << endl;
    }
    return 0;
}
