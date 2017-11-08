#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<int> _candidates;
    std::vector<std::vector<int> > _res;

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> loc;
        int prevCandidate = -1;

        if(candidates.size() == 0) return _res;
        if(target == 0) {
            _res.push_back(loc);
            return _res;
        }

        sort(candidates.begin(), candidates.end());
        _candidates = candidates;

        for(int i=0; i<candidates.size(); i++) {
            if(prevCandidate != -1 and prevCandidate == candidates[i]) continue;
            prevCandidate = candidates[i];

            loc.push_back(candidates[i]);
            findTarget(target-candidates[i], i, loc);
            loc.pop_back();
        }

        return _res;
    }

    void findTarget(int target, int idx, std::vector<int> loc) {
        if(target == 0) {
            _res.push_back(loc);
            return;
        }
        if(target < 0) return;

        int prevCandidate = -1;

        for(int i=idx+1; i<_candidates.size(); i++) {
            if(prevCandidate != -1 and prevCandidate == _candidates[i]) continue;
            prevCandidate = _candidates[i];

            loc.push_back(_candidates[i]);
            findTarget(target-_candidates[i], i, loc);
            loc.pop_back();
        }
    }
};