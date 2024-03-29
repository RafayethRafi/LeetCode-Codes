class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int xor1=0, xor2=0 ,i;

        for(i=0;i<n;i++)
        {
            xor1 = xor1^nums[i];
            xor2 = xor2^i;
        }
        xor2 ^= n;

        return (xor1^xor2);
    }
};
