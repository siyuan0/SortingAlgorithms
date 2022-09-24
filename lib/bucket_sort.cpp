#include "utils.hpp"

struct Bucket
{
    std::vector<int> storedVal; // sorted vector

    void addVal(int val)
    {
        if(!storedVal.size())
        {
            storedVal.push_back(val);
        }
        else
        {
            bool inserted = false;
            for(auto iter=storedVal.begin(); iter!=storedVal.end(); iter++)
            {
                if(val <= *iter)
                {
                    inserted = true;
                    storedVal.insert(iter, val);
                    break;
                }
            }
            if(!inserted) storedVal.push_back(val);
        }
    }
};

int hash_funct(int val)
{
    // take input array and convert into bucket index
    return val / 100000;
}


std::vector<int> bucket_sort(std::vector<int> vec)
{
    START_TIMING()
    START_TRACK_SPACE("bucket_sort")

    int num_buckets = RAND_MAX / 100000 + 1;

    Bucket buckets[num_buckets];

    for(int i : vec) buckets[hash_funct(i)].addVal(i);

    int counter = 0;
    Bucket prevBucket = buckets[0];
    for(Bucket bucket : buckets)
    {
        TRACK_VECTOR(bucket.storedVal)
        for(int i : bucket.storedVal)
        {
            vec[counter] = i;
            counter += 1;
        }
    }
    
    TRACK_VAR(num_buckets)
    TRACK_VAR(counter)
    TRACK_VAR(buckets)
    END_TRACK_SPACE()
    END_TIMING()
    return vec;
}