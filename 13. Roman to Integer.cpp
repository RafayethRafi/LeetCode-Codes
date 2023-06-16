// First Solution

class Solution {
public:
    int romanToInt(string s) {
        string t = s;

        int ans = 0; 
        for(int i=0;i<t.size();i++)
        {
            if( (t[i] == 'I' && t[i+1]=='V') && i<(t.size()-1)) ans += 4,i++;
            else if( (t[i] == 'I' && t[i+1]=='X') && i<(t.size()-1)) ans += 9,i++;
            else if( (t[i] == 'X' && t[i+1]=='L') && i<(t.size()-1)) ans += 40,i++;
            else if( (t[i] == 'X' && t[i+1]=='C') && i<(t.size()-1)) ans += 90,i++;
            else if( (t[i] == 'C' && t[i+1]=='D') && i<(t.size()-1)) ans += 400,i++;
            else if( (t[i] == 'C' && t[i+1]=='M') && i<(t.size()-1)) ans += 900,i++;
            else if(t[i]== 'I') ans++;
            else if(t[i]=='V') ans += 5;
            else if(t[i] == 'X') ans += 10;
            else if(t[i]=='L') ans += 50;
            else if(t[i]=='C') ans += 100;
            else if(t[i]=='D') ans += 500;
            else if(t[i]=='M') ans += 1000;

        }

        return ans;
    }
};


//2nd Solution

class Solution {
public:
    int romanToInt(string s) {
        string t = s;

        int ans = 0; 
        unordered_map<char,int> mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        for(int i=0;i<t.size();i++)
        {
            if(mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }

        return ans;
    }
};
