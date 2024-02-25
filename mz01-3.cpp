#include <iostream>
#include <string>

int
main()
{
    using std::cout, std::cin, std::string, std::ios;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    char c;
    bool zeros = false;
    bool numbers = false;
    while ((x = cin.get()) != EOF) {
        c = (char) x;
        if (c == '0') {
            zeros = true;
            if (numbers) {
                cout << c;
            }
        } else if (c <= '9' && c >= '1') {
            zeros = false;
            numbers = true;
            cout << c;
        } else {
            if (zeros && !numbers) {
                cout << '0';
            }
            zeros = false;
            numbers = false;
            cout << c;
        }
    }
    if (zeros && !numbers) {
        cout << '0';
    }
    return 0;
}
