class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>ans(2);

        for(int i=0;i<nums.size();i++)
        {
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end())
            {
                ans[0] = mp[rem];
                ans[1] = i;
                break;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
