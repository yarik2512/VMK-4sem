#include <iostream>
#include <set>
#include <map>
#include <format>

class Date
{
    int year = 0, month = 0, day = 0;

public:
    friend std::istream &operator>>(std::istream &in, Date &d);

    friend std::ostream &operator<<(std::ostream &out, const Date &d);

    bool
    operator<(const Date &b) const
    {
        if (year == b.year) {
            if (month == b.month) {
                return day < b.day;
            }
            return month < b.month;
        }
        return year < b.year;
    }
};

std::istream &
operator>>(std::istream &in, Date &d)
{
    std::string str;
    in >> str;
    int i;
    for (i = 0; str[i] != '/'; ++i);
    d.year = stoi(str.substr(0, i));
    int j;
    for (j = i + 1; str[j] != '/'; ++j);
    d.month = stoi(str.substr(i + 1, j - i - 1));
    d.day = stoi(str.substr(j + 1, str.length() - j - 1));
    return in;
}

std::ostream &operator<<(std::ostream &out, const Date &d) {
    out << std::format("{:04}/{:02}/{:02}", d.year, d.month, d.day);
    return out;
}

int
main()
{
    using std::cin, std::cout, std::endl, std::set, std::map, std::string, std::pair;
    map<string, map<Date, int>> marks;
    set<Date> dates;
    string name;
    Date date;
    int mark;
    while (cin >> name) {
        cin >> date >> mark;
        marks[name][date] = mark;
        dates.insert(date);
    }
    cout << '.';
    for (const Date &d: dates) {
        cout << ' ' << d;
    }
    cout << endl;
    for (pair<const string, map<Date, int>>& rec: marks) {
        cout << rec.first;
        for (const Date &d: dates) {
            if (rec.second.contains(d)) {
                cout << ' ' << rec.second[d];
            } else {
                cout << " .";
            }
        }
        cout << endl;
    }
    return 0;
}
