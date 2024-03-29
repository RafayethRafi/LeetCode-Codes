class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(),i;

        int num1= INT_MIN,num2 = INT_MIN,cnt1= 0, cnt2=0;

        for(i=0;i<n;i++)
        {
            
            if(nums[i] == num1)
            {
                cnt1++;
            }
            else if(nums[i] == num2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                num1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                num2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ans;

        cnt1 = 0, cnt2 =0;
        for(i=0;i<n;i++)
        {
            if(num1 == nums[i])
            {
                cnt1++;
            }
            if(num2 == nums[i])
            {
                cnt2++;
            }
        }

        if(cnt1> (n/3)) ans.push_back(num1);
        if(cnt2> (n/3)) ans.push_back(num2);

        return ans;
    }
};
