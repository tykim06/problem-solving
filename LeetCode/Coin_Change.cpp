/*
 * =====================================================================================
 *
 *       Filename:  Coin_Change.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017/09/19 17시 09분 36초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Taeyeop Kim (Tommy), ktim610@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    private:
        int count;
        vector<int> coins;
        map<int, int> amount_map;

        void makeAmount(int c_amount, int c_coin_idx, int c_count) {
            if(c_amount < 0) return;
            if(c_coin_idx < 0) return;
            if(c_count >= count) return;
            if(c_amount == 0 and c_count < count) {
                count = c_count;
                return;
            }

            makeAmount(c_amount-coins[c_coin_idx], c_coin_idx, c_count+1);
            makeAmount(c_amount, c_coin_idx-1, c_count);
        }
    public:
        int coinChange(vector<int>& coins, int amount) {
            if(amount == 0) return 0;

            sort(coins.begin(), coins.end());
            this->coins = coins;

            for(int a=1; a<=amount; a++) {
                count = amount+1;

                if(amount_map.find(a) == amount_map.end()) {

                }
                makeAmount(amount-coins.back(), coins.size()-1, 1);
                makeAmount(amount, coins.size()-2, 0);
            }

            return count == amount+1 ? -1 : count;
        }
};
