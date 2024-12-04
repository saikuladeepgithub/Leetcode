class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
            const int srcLen = str1.size(), tgtLen = str2.size();
            char targetChar = str2[0];
            
            int srcIdx, tgtIdx;
            for(srcIdx = 0, tgtIdx = 0; srcIdx < srcLen && tgtIdx < tgtLen; srcIdx++) {
                char srcChar = str1[srcIdx];
                
                if (srcChar == targetChar || 
                    srcChar + 1 == targetChar || 
                    (srcChar == 'z' && targetChar == 'a')) {
                    targetChar = str2[++tgtIdx];
                }
            }
            
            return tgtIdx == tgtLen;

    }
};