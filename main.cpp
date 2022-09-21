#include <iostream>
#include "lib/algor.hpp"
#include "lib/utils.hpp"

int main(int argc, char* argv[])
{
    int TEST_SIZE;
    if(argc == 2) TEST_SIZE = std::stoi(std::string(argv[1]));
    else
    {
        std::cout << "Invalid number of arguments, default TEST_SIZE to 10\n";
        TEST_SIZE = 10;
    }

    std::vector<int> otest_set = generate_test_set(TEST_SIZE);

    auto correct_ans = insertion_sort(otest_set);

    for(auto sortfunc : sort_functs)
    {
        std::vector<int> test_set = otest_set;
        auto ans = (*sortfunc)(test_set);
        if(check_ans(ans, correct_ans))
        {
            std::cout << "\tCorrect ans obtained\n";
        }
        else
        {
            std::cout << "\tIncorrect ans\n";
            printVector(ans);
            printVector(correct_ans);
        }
    }
    
    return 0;
}