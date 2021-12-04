class Solution {
public:
     vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubset(nums,i,ans,tmp);
        return ans;
    }
    void findSubset(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> &tmp){
        // Base Case
        if(i>=nums.size()){
            ans.push_back(tmp);
            return;
        }
        
        //Recursion
        //not including i
        findSubset(nums,i+1,ans,tmp);
        //including i
        tmp.push_back(nums[i]);
        findSubset(nums,i+1,ans,tmp);
        tmp.pop_back(); //Backtracking
    }
};