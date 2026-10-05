class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

//a      =  ???1000
//a-1    =  ???0111
//a&(a-1)=  ???0000
