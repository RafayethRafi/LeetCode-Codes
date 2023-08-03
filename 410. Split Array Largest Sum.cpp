class Solution {
public:

    int count(vector<int>& nums, int n, int mid)
    {
        int cnt = 1;
        long long sum =0;

        for(int i=0;i<n;i++)
        {
            if(sum + nums[i] > mid)
            {
                cnt++;
                sum = nums[i];
            }
            else sum += nums[i];
        }

        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        long long n = nums.size();

        long long l = *max_element(nums.begin(),nums.end());
        long long r = accumulate(nums.begin(),nums.end(),0);

        while(l<=r)
        {
            long long mid = l + (r-l)/2;

            int cnt = count(nums,n,mid);

            if(cnt > k) l = mid+1;
            else r = mid-1;
        }

        return l;
    }
};
