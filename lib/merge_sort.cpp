#include "utils.hpp"

namespace MergeSort
{

    std::vector<int> merge(std::vector<int>& left, std::vector<int>& right)
    {
        std::vector<int> merged;
        int left_ptr = 0;
        int right_ptr = 0;

        while(left_ptr < left.size() && right_ptr < right.size())
        {
            if(left[left_ptr] < right[right_ptr])
            {
                merged.push_back(left[left_ptr]);
                left_ptr += 1;
            }
            else
            {
                merged.push_back(right[right_ptr]);
                right_ptr += 1;
            }
        }

        for(int i=left_ptr; i<left.size(); i++) merged.push_back(left[i]);
        for(int i=right_ptr; i<right.size(); i++) merged.push_back(right[i]);

        TRACK_VAR(left_ptr)
        TRACK_VAR(right_ptr)

        return merged;
    }

    std::vector<int> merge_sort(std::vector<int>& vec)
    {
        if(vec.size() == 1) return vec;

        int i;
        std::vector<int> left;
        std::vector<int> right;

        for(i = 0; i < vec.size(); i++) //splitting vec into two parts
        {
            if(i % 2 == 0)
            {
                left.push_back(vec[i]);
            }
            else
            {
                right.push_back(vec[i]);
            }
        }
        TRACK_VECTOR(left)
        TRACK_VECTOR(right)
        TRACK_VAR(i)
        left = MergeSort::merge_sort(left);
        right = MergeSort::merge_sort(right);

        return merge(left, right);
    }

} // namespace MergeSort

std::vector<int> merge_sort(std::vector<int> vec)
{
    START_TIMING()
    START_TRACK_SPACE("merge_sort")
    
    vec = MergeSort::merge_sort(vec);

    END_TRACK_SPACE()
    END_TIMING()

    return vec;
}