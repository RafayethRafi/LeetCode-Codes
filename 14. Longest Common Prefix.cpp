class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(),i,j;

        string t=strs[0],ans="";

        for(i=0;i<n;i++)
        {
            for(j=0;j<strs[i].size();j++)
            {
                if(t[j] == strs[i][j])
                {
                    ans += strs[i][j];
                }
                else break;
            }
            t = ans;
            ans = "";
        }

        return t;
    }
};
