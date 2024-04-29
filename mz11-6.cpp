#include <iostream>

char c;

void gc() {
    for (std::cin >> c; !std::cin.eof() && isspace(c); std::cin >> c);
    if (std::cin.eof()) c = '#';
}

void S();
void A();
void B();

void S() {
    if (c == 'a') {
        gc();
        A();
        if (c != 'b') throw c;
        gc();
    } else if (c == 'c') {
        if (c != 'c') throw c;
        gc();
        B();
    } else throw c;
}

void A() {
    if (c == 'c') {
        gc();
        A();
        if (c != 'd') throw c;
        gc();
    } else if (c == 'e') {
        gc();
    } else throw c;
}

void B() {
    if (c == 'b') {
        gc();
        B();
    } else if (c == 'd') {
        gc();
    }
}

int main() {
    try {
        gc();
        S();
        if (!std::cin.eof()) throw '#';
    } catch (char c) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << 1 << std::endl;
    return 0;
}
