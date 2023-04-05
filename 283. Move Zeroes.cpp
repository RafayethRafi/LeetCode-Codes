class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=-1, n = nums.size();

        for(i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                j=i;
                break;
            }
        }

        if(j!= -1)
        {
            for(i=j+1;i<n;i++)
            {
                if(nums[i]!= 0)
                {
                    swap(nums[i],nums[j]);
                    j++;
                }
            }
        }
    }
};
