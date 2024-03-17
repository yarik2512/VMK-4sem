#include <vector>
#include <algorithm>

void
process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> v1_copy(v1);
    std::sort(v1_copy.begin(), v1_copy.end());
    std::vector<int>::iterator new_end = std::unique(v1_copy.begin(), v1_copy.end());
    v1_copy.erase(new_end, v1_copy.end());
    int count = 0;
    for (const int &x: v1_copy) {
        if (x - count < 0 || x - count >= (int) v2.size()) {
            continue;
        }
        v2.erase(v2.begin() + x - count);
        count++;
    }
}
