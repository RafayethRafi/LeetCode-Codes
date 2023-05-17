// MEMOIZATION

class Solution {
public:

    bool solve(int i,int target,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(i<0) return false;
        if(target == 0) return true;
        if(i==0 && nums[i] == target) return true;

        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i-1,target,nums,dp);
        bool take = false;
        if(target>= nums[i]) take = solve(i-1,(target -nums[i]),nums,dp);

        return dp[i][target] = notTake|take;

    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum =0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }

        if(sum%2) return false;

        sum/= 2;

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        return solve(n-1,sum,nums,dp);

    }
};

// TABULATION

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        long long n = nums.size(), sum =0;

        for(long long i=0;i<n;i++)
        {
            sum += nums[i];
        }

        if(sum%2) return false;

        sum/= 2;

        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));

        for(long long i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }


        for(long long i=1;i<n;i++)
        {
            for(long long target = 1;target<=sum;target++)
            {
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= nums[i]) take = dp[i-1][target-nums[i]];

                dp[i][target] = notTake|take;
            }
        }

        return dp[n-1][sum];
        
    }
};



//SPACE OPTIMIZATION

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        long long n = nums.size(), sum =0;

        for(long long i=0;i<n;i++)
        {
            sum += nums[i];
        }

        if(sum%2) return false;

        sum/= 2;

        vector<bool> prev(sum+1,0), cur(sum+1,0);

        prev[0] = cur[0] = 1;        

        for(int i=1;i<n;i++)
        {
            for(int target = 1;target<=sum;target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if(target >= nums[i]) take = prev[target-nums[i]];

                cur[target] = notTake|take;
            }

            prev = cur;
        }

        return prev[sum];
        
    }
};
