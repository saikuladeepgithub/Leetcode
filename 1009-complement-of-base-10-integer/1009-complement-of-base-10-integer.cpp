class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bitlength=log2(n)+1;
        unsigned int mask=(1u << bitlength)-1;
        return mask^n;
    }
};