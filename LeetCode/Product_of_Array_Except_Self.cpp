#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result;
        int nums_size = nums.size();
        map<int, int> product_at_i, r_product_at_i;
        
        product_at_i[0] = nums[0];
        r_product_at_i[nums_size-1] = nums.back();

        for(int i=1; i<nums_size; i++) {
            product_at_i[i] = product_at_i[i-1] * nums[i];
            r_product_at_i[nums_size-1-i] = r_product_at_i[nums_size-i] * nums[nums_size-1-i];
        }

        result.push_back(r_product_at_i[1]);
        for(int i=1; i<nums_size-1; i++) {
            result.push_back(product_at_i[i-1] * r_product_at_i[i+1]);
        }
        result.push_back(product_at_i[nums_size-2]);

        return result;
    }
};