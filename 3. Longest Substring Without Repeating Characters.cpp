class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substr;
        int c=0,l=0,r=0;
        while(r<s.length()) {
            if(substr.find(s[r])==substr.end()) {
                substr.insert(s[r]);
                c=max(c,r-l+1);
                r++;
            }
            else {
                substr.erase(s[l]);
                l++;
            }
        }
        return c;
    }
};