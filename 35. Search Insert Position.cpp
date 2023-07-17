class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r = n-1,ans = n;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(target <= nums[mid])
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};
