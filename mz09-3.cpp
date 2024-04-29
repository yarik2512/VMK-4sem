/* язык - {a^n 0^m a^n 1^m, n, m > 0}, типа 1
 * грамматика:
 * S -> AB
 * A -> ab | aAb
 * B -> C1 | CB1
 * bC -> Cb
 * aC -> a0
 * 0C -> 00
 */

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
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        for (; i < s.length() && s[i] == '0'; ++i);
        m = i - n;
        if (m == 0 || s.length() != 2 * (m + n)) {
            cout << 0 << endl;
            continue;
        }
        string::size_type count;
        for (count = 0; i < s.length() && s[i] == 'b'; ++count, ++i);
        if (count != n) {
            cout << 0 << endl;
            continue;
        }
        for (count = 0; i < s.length() && s[i] == '1'; ++count, ++i);
        if (count != m) {
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}
