#include <vector>
#include <iterator>

void
process(const std::vector<unsigned long> &a, std::vector<unsigned long> &b,
        std::vector<unsigned long>::difference_type n)
{
    std::vector<unsigned long>::const_iterator i = a.begin();
    std::vector<unsigned long>::reverse_iterator j = b.rbegin();
    while (i < a.end() && j != b.rend()) {
        *j += *i;
        i += n;
        j++;
    }
}
