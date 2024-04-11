#include <iostream>
#include <vector>
#include <algorithm>

bool
cmp(const Figure *a, const Figure *b)
{
    return a->get_square() < b->get_square();
}

int
main()
{
    char type;
    std::string params;
    std::vector<Figure *> figs;
    while (std::cin >> type) {
        std::getline(std::cin, params);
        switch (type) {
        case 'R':
            figs.push_back(Rectangle::make(params));
            break;
        case 'S':
            figs.push_back(Square::make(params));
            break;
        case 'C':
            figs.push_back(Circle::make(params));
            break;
        }
    }
    std::stable_sort(figs.begin(), figs.end(), cmp);
    for (unsigned i = 0; i < figs.size(); ++i) {
        std::cout << figs[i]->to_string() << std::endl;
    }
    for (unsigned i = 0; i < figs.size(); ++i) {
        delete figs[i];
    }
    return 0;
}
