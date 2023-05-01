class Solution {
public:

    int solve(int n, int dp[]){

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);

    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0] = dp[1] = 1;
        solve(n, dp);

        return solve(n, dp);;
    }
};
