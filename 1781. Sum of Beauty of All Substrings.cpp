class Solution {
public:
    int beautySum(string s) {
        int ans = 0,i,j;
        int n = s.size();

        

        for(i=0;i<n;i++)
        {
            map<char,int> mp;

            for(j=i;j<n;j++)
            {
                mp[s[j]]++;
                
                int mn = INT_MAX;
                int mx = INT_MIN;

                for(auto u:mp)
                {
                    if(u.second>mx) mx = u.second;

                    if(u.second<mn) mn = u.second;
                }

                ans += (mx - mn);
            }
        }

        return ans;
    }
};
