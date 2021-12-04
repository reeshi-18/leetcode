class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i=0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubset(nums,i,ans,tmp,false);
        return ans;
    }
    void findSubset(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> &tmp, bool prev){
        // Base Case
        if(i>=nums.size()){
            ans.push_back(tmp);
            return;
        }
        
        //Recursion
        //not including i
        findSubset(nums,i+1,ans,tmp,false);
        
        // if we ignored last repeated value, ignore present repeated value
        if(i>0 && nums[i]==nums[i-1] && (!prev)) return;
        
        //including i
        tmp.push_back(nums[i]);
        findSubset(nums,i+1,ans,tmp,true);
        tmp.pop_back(); //Backtracking
    }
};