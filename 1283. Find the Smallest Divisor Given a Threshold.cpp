class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long n = nums.size(),i;
        int l = 1, r = *max_element(nums.begin(),nums.end());

        while(l<=r)
        {
            long long mid = l + (r-l)/2;

            long long sum = 0;

            for(i=0;i<n;i++)
            {
                sum += ceil((double)nums[i]/(double)mid);
            }

            if(sum>threshold) l = mid+1;
            else r = mid-1;
        }

        return l;
    }
};
