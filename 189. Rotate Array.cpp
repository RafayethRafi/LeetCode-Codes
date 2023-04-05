class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        
        if(k>0)
        {
            int tmp[k],i;
            for(i=0;i<k;i++)
        {
            tmp[i] = nums[(n-k)+i];
        }

        for(i=n-k-1;i>=0;i--)
        {
            nums[i+k] = nums[i];
        }

        for(i=0;i<k;i++)
        {
            nums[i] = tmp[i];
        }
        }
    }
};
