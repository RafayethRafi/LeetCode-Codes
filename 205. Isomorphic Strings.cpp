class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.size() != t.size()) return false;

       map<char,char> mp,mp1;

       for(int i=0;i<s.size();i++)
       {
           if(mp.find(s[i]) != mp.end())
           {
               if(mp[s[i]] != t[i]) return false;
           }
           else if(mp1.find(t[i]) != mp1.end())
           {
               if(mp1[t[i]] != s[i]) return false;
           }
           else
           {
               mp[s[i]] = t[i];
               mp1[t[i]] = s[i];
           }
       }

       return true;
    }
};
