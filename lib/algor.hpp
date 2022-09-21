#include <vector>

std::vector<int> insertion_sort(std::vector<int> vec);
std::vector<int> quick_sort(std::vector<int> vec);

std::vector<std::vector<int> (*)(std::vector<int>)> sort_functs = {
    &quick_sort,
};

