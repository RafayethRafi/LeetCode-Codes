class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        
      int left = 0, right = 0;
      int n = s.size();
      int ans = 0;
        
        vector<int> v(256,-1);

        while(right<n){
            if(v[s[right]] != -1)
                {left = max(v[s[right]] + 1,left );}

            v[s[right]] = right;

            ans = max(ans, right-left+1);
            right++;
            
        }

        return ans;
    }
};
