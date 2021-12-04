class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        vector<int> indices(2,-1);
        while(low<=high) {
            int mid= low+(high-low)/2;
            int l,b;
            if(nums[mid]>target) high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else {
                l=mid;
                b=mid;
                while(l>0 && nums[l-1]==target) l--;
                while(b<n-1 && nums[b+1]==target) b++;
                indices[0]=l, indices[1]=b;
                return indices;
            }
        }
        return indices;
    }
};