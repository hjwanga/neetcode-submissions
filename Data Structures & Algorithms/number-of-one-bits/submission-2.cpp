class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            ++result;
            n = n&(n-1);
        }
        return result;
    }
};

//a      =  ???1000
//a-1    =  ???0111
//a&(a-1)=  ???0000
