class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;

        for(auto u : s)
        {
            mp[u]++;
        }

        vector<pair<int,char>> v;

        for(auto u : mp)
        {
            v.push_back({u.second,u.first});
        }

        sort(v.rbegin(),v.rend());

        string ans = "";

        for(int i =0 ;i<v.size();i++)
        {
            int sz = v[i].first;
            char ch = v[i].second;

            for(int j=0;j<sz;j++) ans += ch;
        }

        return ans;
    }
};



// 2nd Solution with less Space

class Solution {
public:

    string frequencySort(string s) {

        string t=s;
        map<char,int> mp;

        for(auto u : s)
        {
            mp[u]++;
        }

        auto compare = [&](char a,char b)
        {
            if(mp[a] == mp[b])
            {
                return a<b;
            }
            return mp[a]>mp[b];
        };

        sort(t.begin(),t.end(), compare);

        return t;

    }
};
