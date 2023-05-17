class Solution {
public:
        string removeOuterParentheses(string s) {
        int n = s.size(),i,j,cnt=1;
        vector<int> v;
        if(n==0) return s;

        v.push_back(0);

        for(i=1;i<n;i++)
        {
            if(s[i] == '(') cnt++;
            else cnt--;

            if(cnt==0)
            {
                v.push_back(i);
            }
            if(cnt==1 && s[i]=='(')
            {
                v.push_back(i);
            }
        }

        string t="";

        for(i=0,j=0;i<n,j<v.size();i++)
        {
            if(i!=v[j]) t+= s[i];
            else j++;
        }

        return t;
    }
};
