#include <iostream>

int main() {
    using std::string, std::cin, std::cout, std::endl;
    string s;
    while (cin >> s) {
        string::size_type i;
        bool ans = true;
        for (i = 0; i < s.length(); ++i) {
            if (s[i] != '3' && s[i] != '4') {
                break;
            }
        }
        for (; i < s.length(); ++i) {
            if (s[i] != '1' && s[i] != '2') {
                ans = false;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
