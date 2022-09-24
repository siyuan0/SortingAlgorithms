#include "utils.hpp"

std::vector<int> insertion_sort(std::vector<int> vec)
{
    START_TIMING()
    START_TRACK_SPACE("insertion_sort <baseline>")

    assert(vec.size()>=2);
    std::vector<int> sorted = {vec[0]};

    for(int i = 1; i < vec.size(); i++)
    {
        bool inserted = false;
        for(auto iter = sorted.begin(); iter != sorted.end() ; iter++)
        {
            if(vec[i] <= *iter){
                sorted.insert(iter, vec[i]);
                inserted = true;
                break;
            }
        }
        if(!inserted) sorted.push_back(vec[i]);
    }

    
    TRACK_VECTOR(sorted)
    END_TRACK_SPACE()
    END_TIMING()
    return sorted;
}