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
