class Solution {
public:

    bool solve(int k,int j,vector<vector<bool>> &dp, string &s)
    {  
        if(k==j) return dp[k][j] = true;

        if((j-k) == 1)
        {
            if(s[j]==s[k])
            return dp[k][j] = true;
            else return dp[k][j] = false;
        }

        if( (dp[k+1][j-1]) && (s[j]==s[k])) return dp[k][j] = true;

        return dp[k][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size(),i,j,k,cnt = 0,ans =0,idx = 0;

        vector<vector<bool>> dp(n, vector<bool>(n,0));
        for(i=0;i<n;i++)
        {
            for(k=0,j=i;j<n;j++,k++)
            {
                if(solve(k,j,dp,s))
                {
                    cnt = (j-k) + 1;
                    if(cnt >ans)
                    {
                        ans = cnt;
                        idx = k;
                    }
                }
            }
        }

        return s.substr(idx, ans);
    }
};
