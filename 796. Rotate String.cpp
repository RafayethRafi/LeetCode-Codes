class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s;

        int n = s.size();

        if(s == goal) return true;

        for(int i=0;i<n;i++)
        {
            char tmp = t[0];

            t = t.substr(1,n) + tmp;

            if( t == goal) return true;
        }

        return false;
    }
};


class Solution {
public:
    bool rotateString(string s, string goal) {
        string t;
        t = s+s;

        return ((s.size() == goal.size()) && (t.find(goal) != string::npos));
    }
};
