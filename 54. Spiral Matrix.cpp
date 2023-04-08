class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>ans;
        int i=0,j=0,left=0,top=0,bottom = n-1, right = m-1;

        while(left<=right && top<=bottom)
        {
            for(i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom)
            {
                for(i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;

            if(left<=right)
            {
                for(i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }

        return ans;
    }
};
