class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size(),i;

        long long x = 1LL*m*k;
        if(x > n) return -1;

        int low = 1 , high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high)
        {
            long long  mid = low + (high - low)/2;

            long long sum =0,cnt = 0;

            for(i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid) cnt++;
                else
                {
                    sum += (cnt/k);
                    cnt = 0;
                }
            }

            sum += (cnt/k);

            if(sum>=m) high = mid-1;
            else low =mid+1;
        }

        return low;
    }
};
