#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
private:
    int start_num_idx;
    int last_num;
    char last_op;

    stack<int> cal;

    void apply_new_num(string s_new_num) {
        int current_num = atoi(s_new_num.c_str());
        if(last_op == '*') {
            last_num *= current_num;
            cal.pop();
        } else if(last_op == '/') {
            last_num /= current_num;
            cal.pop();
        } else if(last_op == '-') {
            last_num = -current_num;
        } else {
            last_num = current_num;
        }
        cal.push(last_num);
        start_num_idx = -1;
    }
public:
    int calculate(string s) {
        this->start_num_idx = -1;
        this->last_num = -1;
        this->last_op = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(start_num_idx == -1) {
                    start_num_idx = i;
                }
            } else {
                if(start_num_idx != -1) apply_new_num(s.substr(start_num_idx, i - start_num_idx));
                if(s[i] != ' ') last_op = s[i];
            }
        }
        if(start_num_idx != -1) apply_new_num(s.substr(start_num_idx, s.size() - start_num_idx));

        this->last_num = 0;

        while(!cal.empty()) {
            cout << cal.top();
            last_num += cal.top();
            cal.pop();
        }
        return last_num;
    }
};