#include <iostream>

int main()
{
    using std::cout, std::cin, std::hex;
    int c;
    int prev_c = -1, count = 0;
    while ((c = cin.get()) != EOF) {
        if (c == prev_c) {
            count++;
        } else {
            if ((char) prev_c == '#' || count > 4) {
                cout << '#' << (char) prev_c << hex << count << '#';
            } else {
                for (int i = 0; i < count; ++i) {
                    cout << (char) prev_c;
                }
            }
            count = 1;
        }
        prev_c = c;
    }
    if ((char) prev_c == '#' || count > 4) {
        cout << '#' << (char) prev_c << hex << count << '#';
    } else {
        for (int i = 0; i < count; ++i) {
            cout << (char) prev_c;
        }
    }
    return 0;
}
