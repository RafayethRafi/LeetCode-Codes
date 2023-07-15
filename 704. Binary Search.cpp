class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int low = 0, high = n-1;

        while(low+1<high)
        {
            int mid= low + (high-low)/2;
            if(target == nums[mid]) return mid;
            if(target< nums[mid]) high = mid-1;
            else low = mid+1;
        }

        if(nums[low]==target) return low;
        else if(nums[high]==target) return high;
        else return -1;
    }
};
