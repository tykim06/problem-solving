<<<<<<< HEAD
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
    map<int, int> minCoinChangeMap;
public:
    int coinChange(vector<int>& coins, int amount) {
        int pre_amount;

        for(int c_amount=1; c_amount<=amount; c_amount++) {
            minCoinChangeMap[c_amount] = -1;

            for(int coin_idx=0; coin_idx<coins.size(); coin_idx++) {
                if(c_amount < coins[coin_idx]) continue;

                pre_amount = minCoinChangeMap[c_amount-coins[coin_idx]];
                if(pre_amount == -1) continue;

                minCoinChangeMap[c_amount] = (minCoinChangeMap[c_amount] == -1) ?
                    1 + pre_amount :
                    min(minCoinChangeMap[c_amount], 1+pre_amount);
            }
        }

        return minCoinChangeMap[amount];
    }
};
