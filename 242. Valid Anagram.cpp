class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;

        return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};

        for(int i=0;i<s.size();i++)
        {
            int x = s[i] - 'a';
            cnt[x]++;
        }

        for(int i=0;i<t.size();i++)
        {
            int x = t[i] - 'a';
            cnt[x]--;
        }

        for(int i=0;i<26;i++)
        {
            if(cnt[i] != 0) return false;
        }

        return true;

    }
};
