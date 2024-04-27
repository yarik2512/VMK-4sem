#include <iostream>

int main() {
    using std::ios_base, std::string, std::cin, std::cout, std::endl;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    while (cin >> s) {
        string::size_type z_count;
        string::size_type n_count;
        string::size_type count;
        string::size_type i;
        bool ans = true;
        for (i = 0; i < s.length() && s[i] == '0'; ++i);
        z_count = i;
        if (z_count == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (; i < s.length() && s[i] == '1'; ++i);
        n_count = i - z_count;
        if (n_count == 0) {
            cout << 0 << '\n';
            continue;
        }
        while (i < s.length()) {
            for (count = 0; i < s.length() && s[i] == '0'; ++i, ++count);
            if (count != z_count) {
                ans = false;
                break;
            }
            for (count = 0; i < s.length() && s[i] == '1'; ++i, ++count);
            if (count != n_count) {
                ans = false;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
