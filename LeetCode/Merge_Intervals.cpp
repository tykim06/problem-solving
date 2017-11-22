#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct IntervalCustom
{
    inline bool operator() (const Interval& itv1, const Interval& itv2)
    {
        return (itv1.start < itv2.start);
    }
};
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<Interval> result;
        if(intervals.size() < 1) return result;

        sort(intervals.begin(), intervals.end(), IntervalCustom());

        int i=1;
        while(i<intervals.size()) {
            if(intervals[i-1].end < intervals[i].start) {
                result.push_back(intervals[i-1]);
                i++;
            } else {
                if(intervals[i-1].end < intervals[i].end) intervals[i-1].end = intervals[i].end;
                intervals.erase(intervals.begin() + i);
            }
        }
        if(intervals.size() > 1) result.push_back(intervals.back());

        return result;
    }
};