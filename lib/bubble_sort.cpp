#include "utils.hpp"

std::vector<int> bubble_sort(std::vector<int> vec)
{
    START_TIMING()
    START_TRACK_SPACE("bubble_sort")

    int i, ii, tmp;
    bool sorted;

    for(i=vec.size(); i>0; i--)
    {
        sorted = true;
        for(ii=0; ii < i-1; ii++)
        {
            if(vec[ii] > vec[ii+1])
            {
                sorted = false;
                tmp = vec[ii];
                vec[ii] = vec[ii+1];
                vec[ii+1] = tmp;
            }
        }
        if(sorted) break;
    }

    TRACK_VAR(i)
    TRACK_VAR(sorted)
    TRACK_VECTOR(vec)
    END_TRACK_SPACE()
    END_TIMING()
    return vec;
}