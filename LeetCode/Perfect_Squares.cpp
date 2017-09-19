/*
 * =====================================================================================
 *
 *       Filename:  Perfect_Squares.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017/09/19 15시 12분 26초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Taeyeop Kim (Tommy), ktim610@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cmath>
#include <vector>

using namespace std;

class Solution {
    private:
        int count;
        vector<int> sqr_num;

        void findSum(int c_n, int c_sqr_idx, int c_count){
            if(c_n < 0) return;
            if(c_sqr_idx < 0) return;
            if(c_count >= count) return;
            if(c_n == 0 && c_count < count) {
                count = c_count;
                return;
            }

            findSum(c_n-sqr_num[c_sqr_idx], c_sqr_idx, c_count+1);
            findSum(c_n, c_sqr_idx-1, c_count);
        }
    public:
        int numSquares(int n) {
            if(n < 4) return n;

            this->count = n;
            int sqr_idx = 0;

            while(1) {
                sqr_num.push_back(pow(sqr_idx+1, 2));
                if(sqr_num.back() > n) break;
                sqr_idx++;
            }

            findSum(n-sqr_num[sqr_idx], sqr_idx, 1);
            findSum(n, sqr_idx-1, 0);

            return count;
        }
};
