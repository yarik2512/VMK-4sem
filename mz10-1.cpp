#include <iostream>

int
main()
{
    using std::string, std::cin, std::cout, std::endl;
    bool rightS = false; // S in the right part
    bool epsS = false; // S -> eps
    bool US = true; // unshortening
    bool leftR = true; // left regular
    bool rightR = true; // right regular
    bool leftA = true; // left auto
    bool rightA = true; // right auto
    string left, right;
    while (cin >> left >> right) {
        if (!epsS && left == "S" && right == "_") {
            epsS = true;
        }
        if (left != "S" && right == "_") {
            US = leftA = rightA = false;
        }
        if (!rightS && right.contains("S")) {
            rightS = true;
        }
        long long i;
        for (i = (long long) right.size() - 1; leftR && i >= 0 && !isupper(right[i]); --i)
            ;
        if (i > 0) {
            leftR = false;
        }
        for (i = 0; rightR && i < (long long) right.size() && !isupper(right[i]); ++i)
            ;
        if (i < (long long) right.size() - 1) {
            rightR = false;
        }
        if ((leftA || rightA) && right.size() > 2) {
            leftA = rightA = false;
        }
        if ((left != "S" || right != "_") && (left != "S" || right.size() != 1 || !isupper(right[0]))) {
            if (leftA && (isupper(right.back()) || (right.size() == 2 && !isupper(right.front())))) {
                leftA = false;
            }
            if (rightA && (isupper(right.front()) || (right.size() == 2 && !isupper(right.back())))) {
                rightA = false;
            }
        }
    }
    if (epsS) {
        US = US && !rightS;
    }
    if (leftA && US) {
        cout << 311 << endl;
    } else if (rightA && US) {
        cout << 321 << endl;
    } else if (leftR) {
        cout << 31 << endl;
    } else if (rightR) {
        cout << 32 << endl;
    } else if (US) {
        cout << 21 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}
