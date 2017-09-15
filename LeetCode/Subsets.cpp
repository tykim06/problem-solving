class Solution {
private:
    std::vector<std::vector<int> > subset;
    std::vector<int> nums;

    void insertSubset(int idx, std::vector<int> sub) {
        if(idx == this->nums.size()-1) {
            subset.push_back(sub);
            return;
        }

        insertSubset(idx+1, sub);
        sub.push_back(nums[idx+1]);
        insertSubset(idx+1, sub);
    }
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        if(nums.size() == 0) return subset;

        this->nums = nums;
        std::vector<int> sub;

        insertSubset(0, sub);
        sub.push_back(nums[0]);
        insertSubset(0, sub);

        return this->subset;
    }
};