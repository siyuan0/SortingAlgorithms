#include "utils.hpp"

void quick_sort(std::vector<int>& vec, int start, int end)
{
    int pivotpt = end;
    {
        int i = start;
        int tmp;

        while(i < pivotpt)
        {
            while(vec[i] > vec[pivotpt] && pivotpt > start)
            {
                tmp = vec[pivotpt-1];
                vec[pivotpt-1] = vec[pivotpt];
                vec[pivotpt] = vec[i];
                vec[i] = tmp;
                pivotpt -= 1;
            }
            if(pivotpt == i)
            {
                if(vec[pivotpt] > vec[pivotpt+1])
                {
                    tmp = vec[pivotpt+1];
                    vec[pivotpt+1] = vec[pivotpt];
                    vec[pivotpt] = tmp;
                }
            }
            i += 1;
        }
    }
    
    if(pivotpt > start) quick_sort(vec, start, pivotpt-1);
    if(pivotpt < end) quick_sort(vec, pivotpt+1, end);

    TRACK_VAR(start)
    TRACK_VAR(end)
    TRACK_VAR(pivotpt)
}

std::vector<int> quick_sort(std::vector<int> vec)
{
    START_TIMING()
    START_TRACK_SPACE("quick_sort")

    quick_sort(vec, 0, vec.size()-1);

    TRACK_VECTOR(vec)
    END_TRACK_SPACE()
    END_TIMING()
    return vec;
}