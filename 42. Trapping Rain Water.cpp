class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n=height.size();
        if(n<=2) return 0;
        int area=0;
        int left=1,right=n-2;
        int maxLeft=height[0], maxRight=height[n-1];
        while(left<=right) {
            if(maxLeft<maxRight) {
                if(height[left]>maxLeft) maxLeft=height[left];
                else area+=maxLeft-height[left];
                left++;
            }
            else {
                if(height[right]>maxRight) maxRight=height[right];
                else area+=maxRight-height[right];
                right--;
            }
        }
        return area;
        
    }
};