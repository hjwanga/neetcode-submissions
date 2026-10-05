class Solution {
public:
    int hammingWeight(uint32_t n) {
        return popcount(n);
    }
};

//a      =  ???1000
//a-1    =  ???0111
//a&(a-1)=  ???0000
