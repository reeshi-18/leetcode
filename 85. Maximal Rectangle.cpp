class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_area=0;
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        vector<vector<int>> height(row, vector<int> (col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j]=='1') {
                    if(i==0) height[i][j]=1;
                    else height[i][j]= 1+height[i-1][j];
                }
            }
            max_area=max(max_area,histArea(height[i]));
        }
        return max_area;
    }
    int histArea(vector<int> &height) {
        stack<int> st;
        int n=height.size();
        int max_area=0;
        vector<int> nextSmaller(n,-1);
        vector<int> prevSmaller(n,-1);
        for(int i=0; i<n; i++) {
            while(!st.empty() && height[st.top()]>height[i]) {
                nextSmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
             nextSmaller[st.top()]=n;
             st.pop();
        }
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && height[st.top()]>height[i]) {
                prevSmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
             prevSmaller[st.top()]=-1;
             st.pop();
        }
        for(int i=0; i<n; i++) {            
            max_area=max(max_area, height[i]*(nextSmaller[i]-prevSmaller[i]-1));
        }
        return max_area;
        
    }
};