class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<high) {
            int mid= low+(high-low)/2;
            if(nums[mid]>=target) {
                high=mid;
            }
            else low=mid+1;
        }
        if(target>nums[low]) return low+1;
        return low;
    }
};