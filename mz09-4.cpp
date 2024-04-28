/*
 * S -> aAd
 * A -> aAd | bBc
 * B -> bBc | eps
 */

#include <iostream>

void S(int, int);
void A(int, int);
void B(int);

void
S(int k, int n)
{
    std::cout << 'a';
    A(k - 2, n - 1);
    std::cout << 'd';
}

void
A(int k, int n)
{
    if (n == 0) {
        std::cout << 'b';
        B(k / 2 - 1);
        std::cout << 'c';
    } else {
        std::cout << 'a';
        A(k - 2, n - 1);
        std::cout << 'd';
    }
}

void
B(int n)
{
    if (n > 0) {
        std::cout << 'b';
        B(n - 1);
        std::cout << 'c';
    }
}

void
gen(int k, int n)
{
    if (k & 1) {
        return;
    }
    if (n == 0) {
        return;
    }
    S(k, n);
    std::cout << std::endl;
    gen(k, n - 1);
}

int
main()
{
    int k;
    std::cin >> k;
    gen(k, k / 2 - 1);
    return 0;
}
