//Normal Approach:

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return (n==0)? 0 :( n & 1)+ hammingWeight(n>>1);  
    }
};


// Optimized Approach ;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans =0;

        for(int i=0;i<16;i++)
        {
            if( (n&3) == 3 ) ans +=2;
            else if( ((n&3)==1) || ((n&3) == 2)) ans++;

            n >>= 2;
        }
        return ans;
    }
};
