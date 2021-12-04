class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>>v;
        for(int i=0; i<nums.size(); i++) v.push_back({nums[i],i});
        sort(v.begin(), v.end());
        int start=0, end=nums.size()-1;
        while(start<end)
        {
            int sum=v[start].first+v[end].first;
            if(sum==target) return {v[start].second, v[end].second};
            else if(sum>target)end--;
            else start++;
        }
        return {-1,-1};
        
    }
};