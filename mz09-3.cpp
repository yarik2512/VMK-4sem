#include <iostream>

int main() {
    using std::cin, std::cout, std::string, std::endl;
    string s;
    while (cin >> s) {
        string::size_type n;
        string::size_type m;
        string::size_type i;
        for (i = 0; i < s.length() && s[i] == 'a'; ++i);
        n = i;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        for (; i < s.length() && s[i] == '0'; ++i);
        m = i - n;
        if (m == 1 || s.length() != 2 * (m + n)) {
            cout << 0 << endl;
            continue;
        }
        string::size_type count;
        for (count = 0; count < n && i < s.length() && s[i] == 'b'; ++count, ++i);
        if (count != n) {
            cout << 0 << endl;
            continue;
        }
        for (count = 0; count < m && i < s.length() && s[i] == '1'; ++count, ++i);
        if (count != m) {
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}
