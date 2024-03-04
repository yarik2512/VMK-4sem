#include <iostream>
#include <string>

using std::string;

class BinaryNumber
{
    string bin;
public:
    BinaryNumber(const string &s);
    operator string () const;
    const BinaryNumber &operator++();
};

BinaryNumber::BinaryNumber(const string &s)
{
    bin = s;
}

BinaryNumber::operator string() const
{
    return bin;
}

const BinaryNumber &
BinaryNumber::operator++()
{
    int add = 0;
    for (long long i = (long long) bin.length() - 1; i >= 0; --i) {
        if (bin[i] == '0') {
            bin[i] = '1';
            return *this;
        } else {
            if (add == 1 || i == (long long) bin.length() - 1) {
                bin[i] = '0';
                add = 1;
            } else {
                return *this;
            }
        }
    }
    bin = '1' + bin;
    return *this;
}
