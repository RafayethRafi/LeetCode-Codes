class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(),i;

        string t="",ans="";

        for(i=n-1;i>=0;i--)
        {
            if(s[i]==' ' && t.size()==0) continue;
            
            if(s[i]==' ')
            {
                reverse(t.begin(),t.end());
                ans+= t;
                ans += ' ';
                t="";
            }

            else t+= s[i];
        }

        reverse(t.begin(),t.end());
        ans+= t;

        if(ans[ans.size()-1]==' ') ans.pop_back();

        return ans;
    }
};
