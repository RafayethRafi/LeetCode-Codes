class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0||t.size()==0 || s.size()<t.size())
        return "";
        
        vector<int>v(256,0);

        for(int i=0;i<t.size();i++) v[t[i]]++;

        int start = 0, end = 0, window_start = 0;
        int window_length = INT_MAX , cnt = 0;

        while(end<s.size())
        {
            if(v[s[end]] > 0) cnt++;

            v[s[end]]--;

            while(cnt==t.size())
            {
                if(window_length> (end-start +1))
                {
                    window_length = end - start + 1;
                    window_start = start;
                }

                v[s[start]]++;
                if(v[s[start]]>0) cnt--;
                
                start++;

            }

            end++;
        }

        if(window_length==INT_MAX) return "";

        return s.substr(window_start,window_length);

    }
};
