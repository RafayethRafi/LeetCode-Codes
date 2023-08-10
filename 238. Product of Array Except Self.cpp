class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),i;
        vector<int> ans;
        int k =1, zero = 0;

        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;

                if(zero>1) break;
            }
            else
                k*= nums[i];
        }

        for(i=0;i<n;i++)
        {
            if(zero>1)
            {
                ans.push_back(0);
            }
            else if(zero == 1)
            {
                if(nums[i]!=0) ans.push_back(0);
                else ans.push_back(k);
            }
            else
            {
                int x = k/nums[i];
                ans.push_back(x);
            }
        }

        return ans;
    }
};
