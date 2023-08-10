class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i=0,j=n-1,maxArea=INT_MIN;

        while(i<j)
        {
            int currArea = min(height[i],height[j])*(j-i);

            maxArea = max(maxArea, currArea);

            if(height[i]<height[j]) i++;
            else j--;
        }

        return maxArea;
    }
};
