class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size(), i , j ,k;

        if(n==0) return ans;
        sort(nums.begin(),nums.end());

        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                long long target2 = target*1LL - nums[i] - nums[j];
                int lo = j+1;
                int hi = n-1;

                while(lo<hi)
                {
                    long long x = nums[lo]*1LL + nums[hi];

                    if(x > target2)
                    {
                        hi--;
                    }
                    else if(x<target2)
                    {
                        lo++;
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);

                        ans.push_back(temp);

                        while(lo<hi && nums[lo]== temp[2]) lo++;
                        while(lo<hi && nums[hi]== temp[3]) hi--;
                    }
                }
                while(j+1<n-1 && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n-2 && nums[i]==nums[i+1]) i++;
        }

        return ans;
    }
};
