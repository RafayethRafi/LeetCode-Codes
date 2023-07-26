class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size(),i;

        int l = 1,r = *max_element(piles.begin(),piles.end());

        while(l<=r)
        {
            long long mid = l + (r-l)/2;

            long long sum = 0;
            for(i=0;i<n;i++)
            {
                long long x = piles[i]/mid;
                if(x*mid != piles[i]) x++;
                sum+=x;
            }

            if(sum<=h) r = mid-1;
            else l = mid+1;
        }

        return l;

    }
};
