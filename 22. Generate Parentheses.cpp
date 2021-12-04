class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        help(ans,0,0,n,tmp);
        return ans;
    }
    void help(vector<string> &ans, int open, int close, int n, string tmp) {
        if(close==n) {
            ans.push_back(tmp);
        }
        if(open<n) help(ans,open+1,close,n,tmp+'(');
        if(close<open) help(ans,open,close+1,n,tmp+')');
    }
};