class Solution {
public:
    int maxDepth(string s) {
        string t = s;

        int cnt = 0,ans =0;

        for(auto u: t)
        {
            if( u == '(')
            {
                cnt++;
                ans = max(ans,cnt);
            }
            if(u == ')') cnt--;
        }

        return ans;
    }
};
