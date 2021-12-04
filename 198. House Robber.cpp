class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=0, prev2=0, curr=0;
        for(int i=nums.size()-1; i>=0; i--) {
            curr= max(prev, nums[i]+prev2);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};