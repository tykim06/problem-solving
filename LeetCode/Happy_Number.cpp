/*
 * =====================================================================================
 *
 *       Filename:  Happy_Number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017/09/18 15시 40분 51초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Taeyeop Kim (Tommy), ktim610@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cmath>
#include <set>

using namespace std;

class Solution {
    private:
        set<int> happy_his;
        int makeHappy(int n) {
            if(n/10 == 0) return pow(n, 2);

            return pow(n%10, 2) + makeHappy(n/10);
        }
    public:
        bool isHappy(int n) {
            while(n != 1) {
                n = makeHappy(n);
                if(happy_his.find(n) == happy_his.end()) {
                    happy_his.insert(n);
                } else {
                    return false;
                }
            }
            return true;
        }
};
