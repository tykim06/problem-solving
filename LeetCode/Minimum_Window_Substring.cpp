#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string minWinStr;
    std::vector<string> winStrs;
    std::vector<int> winIdxs;
    string window;

    void checkMinWinStr(int winIdx, int winLength) {
        if(minWinStr == "" || minWinStr.size() > winLength) {
            minWinStr = window.substr(winIdx, winLength);        }

    }

    void eraseCharInWinStrs(int chIdx) {
        char ch = window[chIdx];
        size_t findIdx;
        int winLength;

        for(int j=0; j<winStrs.size(); j++) {
            winLength = chIdx - winIdxs[j] + 1;
            if(minWinStr != "" and winLength >= minWinStr.size()) {
                winStrs.erase(winStrs.begin()+j);
                winIdxs.erase(winIdxs.begin()+j);
                j--;
                continue;
            }

            findIdx = winStrs[j].find(ch);
            if(findIdx != string::npos) {
                winStrs[j].erase(findIdx, 1);

                if(winStrs[j] == "") {
                    checkMinWinStr(winIdxs[j], winLength);
                    winStrs.erase(winStrs.begin()+j);
                    winIdxs.erase(winIdxs.begin()+j);
                    j--;
                }
            }
        }
    }
public:
    string minWindow(string s, string t) {
        if(s == "") return "";
        if(t == "") return s.substr(0, 1);

        minWinStr = "";
        window = s;

        for(int i=0; i<s.size(); i++) {
            if(t.find(s[i]) != string::npos) {
                if(s.size()-i >= t.size()) {
                    winStrs.push_back(t);
                    winIdxs.push_back(i);    
                }

                eraseCharInWinStrs(i);
            }
        }

        return minWinStr;
    }
};