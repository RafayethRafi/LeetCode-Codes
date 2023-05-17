class Solution {
public:
    string largestOddNumber(string num) {
        string s =num;
        int n = num.size();

        while(1)
        {
            if(s.size()==0) break;
            int x = s.back()-'0';
            if(x&1) break;
            else s.pop_back();
        }

        return s;
    }
};
