#include "utils.hpp"

void printVector(std::vector<int>& vec, int start, int end)
{
    std::cout << "vector: {";
    for(int i = start; i <= end; i++) std::cout << vec[i] << ", ";
    std::cout << "}\n";
}

void printVector(std::vector<int>& vec, std::string extraText)
{
    std::cout << extraText;
    printVector(vec, 0, vec.size()-1);
}

std::vector<int> generate_test_set(int size)
{
    std::srand(std::time(0));

    std::vector<int> _test_set;

    for(int i=0; i<size; i++)
    {
        _test_set.push_back(std::rand());
    }

    return _test_set;
}

bool check_ans(std::vector<int>& to_check, std::vector<int>& ref)
{
    assert(to_check.size() == ref.size());
    for(int i=0; i<ref.size(); i++)
    {
        if(to_check[i] != ref[i]) return false;
    }
    return true;
}