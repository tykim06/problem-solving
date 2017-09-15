class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int length=1; length<=s.size()/2; length++) {
            for(int i=length; i<s.size(); i+=length) {
                if(s.substr(0,length) != s.substr(i, length)) break;
                if(i+length == s.size()) return true;
            }
        }
        return false;
    }
};