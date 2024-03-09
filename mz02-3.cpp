#include <iostream>

constexpr int MAX_COUNT = 4;

void print(char prev_c, int count) {
    using std::cout, std::hex;
    if ((char) prev_c == '#' || count > MAX_COUNT) {
        cout << '#' << (char) prev_c << hex << count << '#';
    } else {
        for (int i = 0; i < count; ++i) {
            cout << (char) prev_c;
        }
    }
}

int main()
{
    using std::cin;
    int c;
    int prev_c = -1, count = 0;
    while ((c = cin.get()) != EOF) {
        if (c == prev_c) {
            count++;
        } else {
            print((char) prev_c, count);
            count = 1;
        }
        prev_c = c;
    }
    print((char) prev_c, count);
    return 0;
}
