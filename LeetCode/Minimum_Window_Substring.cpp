#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> targetCount;
        map<char, bool> targetMatch;
        
        for(int i=0; i<t.size(); i++) {
            targetCount[t[i]]++;
            targetMatch[t[i]] = true;
        }

        int startIdx = 0, endIdx = -1;
        int minIdx = 0, minLen = s.size()+1;
        int count = t.size();

        while(startIdx < s.size() and endIdx < s.size()) {
            if(count) {
                endIdx++;
                
                targetCount[s[endIdx]]--;
                if(targetMatch[s[endIdx]] and targetCount[s[endIdx]] >= 0) {
                    count--;
                }
            } else {
                if(minIdx == -1 or minLen > endIdx-startIdx) {
                    minIdx = startIdx;
                    minLen = endIdx - startIdx;
                }

                targetCount[s[startIdx]]++;
                if(targetMatch[s[startIdx]] and targetCount[s[startIdx]] > 0) {
                    count++;
                }

                startIdx++;
            }
        }

        return s.substr(minIdx, minLen);
    }
};