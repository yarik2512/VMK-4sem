/*
 S -> aSd | bBc
 B -> bBc | eps
*/

#include <iostream>

void S(int n, int k) {
    if (n == k) {
        return;
    }
    std::cout << 'a';
    S(n + 1, k);
    std::cout << 'b';
}

void S(int n, int k) {
    if (n == k) {
        return;
    }
    std::cout << 'b';
    B1(n + 1, k);
    std::cout << 'c';
}

void B(int n, int k) {
    if (n == k) {
        return;
    }
    std::cout << 'b';
    B(n + 1, k);
    std::cout << 'c';
}

int main() {

    return 0;
}
