#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums) {

    auto counts = unordered_map<int, int>();

    for (int i = 0; i < nums.size(); ++i)
    {
        int val = nums[i];

        if (counts.find(val) == counts.end())
        {
            counts[val] = 0;
        }

        counts[val]++;
    }

    vector<int> duplicates;

    for (auto it = counts.begin(); it != counts.end(); it++)
    {
        int key = it->first;
        int value = it->second;

        if (value > 1)
        {
            duplicates.push_back(key);
        }
    }

    return duplicates;
}