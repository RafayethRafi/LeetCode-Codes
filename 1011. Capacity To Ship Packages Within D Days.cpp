class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(),i;

        long long l = *max_element(weights.begin(),weights.end());
        long long r = accumulate(weights.begin(),weights.end(),0);

        while(l<=r)
        {
            long long mid = l + (r-l)/2;

            long long sum =0,cnt=1;

            for(i=0;i<n;i++)
            {
                if((sum+weights[i]) > mid)
                {
                    cnt++;
                    sum = weights[i];
                }
                else sum += weights[i];
            }
            
            if(cnt>days) l = mid+1;
            else r = mid-1;

        } 

        return l;
    }
};
