// MEMOIZATION

class Solution {
public:

    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        int n = triangle.size();

        if(i==(n-1)) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(i+1,j,triangle,dp);
        int diagonal = triangle[i][j] + solve(i+1,j+1, triangle,dp);

        return dp[i][j] = min(down,diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int> (n,-1));

        return solve(0,0,triangle,dp);
    }
};

// TABULATION

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int> (n,-1));

        for(int i = 0;i<n;i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diagonal);
            }
        }

        return dp[0][0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> front(n,0),cur(n,0);

        for(int i = 0;i<n;i++)
        {
            front[i] = triangle[n-1][i];
        }
        for(int i = n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];

                cur[j] = min(down,diagonal);
            }
            front = cur;
        }

        return front[0];
    }
};
