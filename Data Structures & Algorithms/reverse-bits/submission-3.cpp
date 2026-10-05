class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            uint32_t bit = n&1;
            result = (result << 1U) | bit;
            n = n >> 1U;
        }
        return result;
    }
};

//    1101 -> 1011
// l  ^
// r     ^


//     i  < 2
// i = 1
// l = 1010 & (1 << 3-1) = 1010 & 0100 = 0000
// r = 1010 & (1 << 1) = 1010 & 0010 = 0010