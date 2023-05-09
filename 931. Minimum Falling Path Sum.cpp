// MEMOIZATION

class Solution {
public:

    int solve(int i,int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();

        if(j<0 || j>=n) return INT_MAX;
        if(i==0) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int d = solve(i-1,j,matrix,dp);
        int dl = solve(i-1,j-1,matrix,dp);
        int dr = solve(i-1,j+1,matrix,dp);

        return dp[i][j] = (matrix[i][j] + min(d,min(dl,dr)));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int ans = INT_MAX;

        for(int j=0;j<n;j++) ans = min(ans,solve(n-1,j, matrix , dp));

        return ans;
    }
};

// TABULATION

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) dp[i][j] = matrix[i][j];
                else
                {
                    int d = matrix[i][j] + dp[i-1][j];

                    int dl = matrix[i][j];
                    if(j>0) dl += dp[i-1][j-1];
                    else dl+= 1e9;

                    int dr = matrix[i][j];
                    if(j<n-1) dr += dp[i-1][j+1];
                    else dr+= 1e9;

                    dp[i][j] = min(d, min(dl,dr));
                }
            }
        }

        int ans = INT_MAX;

        for(int j=0;j<n;j++) ans = min(ans,dp[n-1][j]);

        return ans;
    }
};


//SPACE OPTIMIZATION

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int>prev(n,0), cur(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) prev[j] = matrix[i][j];
                else
                {
                    int d = matrix[i][j] + prev[j];

                    int dl = matrix[i][j];
                    if(j>0) dl += prev[j-1];
                    else dl+= 1e9;

                    int dr = matrix[i][j];
                    if(j<n-1) dr += prev[j+1];
                    else dr+= 1e9;

                    cur[j] = min(d, min(dl,dr));
                }
            }

            if(i> 0) prev = cur;
        }

        int ans = INT_MAX;

        for(int j=0;j<n;j++) ans = min(ans,prev[j]);

        return ans;
    }
};
