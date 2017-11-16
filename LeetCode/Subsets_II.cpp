#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<int> _nums;
    std::vector<std::vector<int> > result;

    void makeSubsets(int idx, std::vector<int> subset) {
        int prevNum = _nums[idx] + 1;

        for(int i=idx; i<_nums.size(); i++) {
            if(prevNum == _nums[i]) {
                continue;
            }
            prevNum = _nums[i];

            subset.push_back(_nums[i]);
            result.push_back(subset);
            makeSubsets(i+1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        std::vector<int> subset;
        result.push_back(subset);

        if(nums.size() == 0) return result;

        sort(nums.begin(), nums.end());
        _nums = nums;
        int prevNum = nums[0] + 1;

        for(int i=0; i<nums.size(); i++) {
            if(prevNum == nums[i]) continue;
            prevNum = nums[i];
            
            subset.push_back(nums[i]);
            result.push_back(subset);
            makeSubsets(i+1, subset);
            subset.pop_back();
        }

        return result;
    }
};