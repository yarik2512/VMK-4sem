#include <iostream>
#include <iomanip>

constexpr int STR_LEN = 16;
constexpr int BASE = 16;
constexpr int CHAR_BIT = 8;
constexpr int OCTS_CNT = 4;

int main() {
    using std::cin, std::cout, std::endl, std::setbase;
    cin >> setbase(BASE);
    unsigned long long offset, c, x = 0;
    while (cin >> offset) {
        int i;
        for (i = 0; i < STR_LEN && (cin >> c); ++i) {
            if (i != 0 && i % OCTS_CNT == 0) {
                cout << x << endl;
                x = 0;
            }
            x = (x << CHAR_BIT) | c;
        }
        if (i != 0 && i % OCTS_CNT == 0) {
            cout << x << endl;
            x = 0;
        }
    }
    return 0;
}
