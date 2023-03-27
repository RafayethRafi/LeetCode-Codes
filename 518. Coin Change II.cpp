class Solution {
public:
    int dp[300][10010];

int func1(int idx,int amount , vector<int>& coins)
{
    if(amount==0) return 1;
    if(idx<0) return 0;
    if(dp[idx][amount]!=-1) return dp[idx][amount];

    int ways = 0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+= coins[idx])
    {
        ways += func1(idx-1, (amount- coin_amount),coins);
    }
    return dp[idx][amount] = ways;
}


int change(int amount, vector<int>& coins) {
    memset(dp,-1,sizeof(dp));
    int ans = func1(coins.size()-1,  amount,coins);

    return ans; 
}
};
