#include <iostream>

int
main()
{
    using std::string, std::cin, std::cout, std::endl;
    string left, right;
    bool empty = true;
    bool leftS = false;
    bool rightS = false;
    bool emptyS = false;
    bool leftT = false;
    bool G;
    bool CF = true;
    bool US = true;
    while ((cin >> left >> right) && !leftT) {
        if (left == "0") break;
        if (empty) {
            empty = false;
        }
        if (!leftS && left == "S") {
            leftS = true;
        }
        bool leftN = false;
        for (char c : left) {
            if (isupper(c) && !leftN) {
                leftN = true;
            }
            if (c == 'S' && !rightS) {
                rightS = true;
            }
        }
        if (!leftN) {
            leftT = true;
        }
        if (left.size() != 1 || !isupper(left[0])) {
            CF = false;
        }
        if (CF && right == "_") {
            if (left != "S") {
                US = false;
            } else if (!emptyS) {
                emptyS = true;
            }
        }
    }
    if (CF && emptyS) {
        US = !rightS;
    }
    G = !empty && !leftT && leftS;
    if (!G) {
        cout << -1 << endl;
    } else {
        if (CF) {
            if (US) {
                cout << 23 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << 10 << endl;
        }
    }
    return 0;
}
