class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r= n-1;

        while(l+1<r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] <= nums[r])
            r = mid;
            else if(nums[l] <= nums[mid])
            l = mid;
        }

        return min(nums[l],nums[r]);
    }
};
