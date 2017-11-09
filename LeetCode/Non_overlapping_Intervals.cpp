#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct compare
{
    bool operator () (const Interval& i1, const Interval& i2)
    {
        return (i1.start < i2.start);
    }
};
 
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());

        int overlapCnt = 0;
        int compIdx = 0;

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start < intervals[compIdx].end) {
                overlapCnt++;
                if(intervals[i].end < intervals[compIdx].end) compIdx = i;
            }
            else compIdx = i;
        }

        return overlapCnt;
    }
};