#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colorCnt[3] = {0,0,0};

        for(int i=0; i<nums.size(); i++) {
            colorCnt[nums[i]]++;
        }

        nums.clear();
        while(true) {
            if(colorCnt[0] > 0) {
                colorCnt[0]--;
                nums.push_back(0);
            } else if(colorCnt[1] > 0) {
                colorCnt[1]--;
                nums.push_back(1);
            } else if(colorCnt[2] > 0) {
                colorCnt[2]--;
                nums.push_back(2);
            } else {
                return;
            }
        }
    }
};