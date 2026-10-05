class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (uint32_t i = 0; i < 16; ++i) {
            uint32_t l = n & (1U << (31-i));
            uint32_t r = n & (1U << i);
            l = l > 0 ? 1 : 0;
            r = r > 0 ? 1 : 0;
            result |= r << (31-i);
            result |= l << i;
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