class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i=0;i<32;i++)
        {
            ans <<= 1;
            bool bit = n&1;

            ans |= bit;

            n >>= 1;
        }

        return ans;
    }
};




// Optimized Approach

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i=0;i<16;i++)
        {
            ans <<= 2;
            int bit = n&3;

            if(bit==2) ans |= 1;
            else if(bit==1) ans |= 2;
            else ans |= bit;
            

            n >>= 2;
        }

        return ans;
    }
};
