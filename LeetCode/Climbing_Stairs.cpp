class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        int two_steps_before = 1;
        int one_step_before = 2;
        int current_step;

        for(int i=3; i<=n; i++) {
            current_step = two_steps_before + one_step_before;
            two_steps_before = one_step_before;
            one_step_before = current_step;
        }

        return current_step;
    }
};