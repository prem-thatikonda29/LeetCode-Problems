class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == haystack) return 0;
        if (needle.empty()) return 0;

        int hayLen = haystack.length();
        int neeLen = needle.length();
        
        for(int hayInd = 0; hayInd <= hayLen - neeLen; hayInd++){
            int neePtr = 0;
            while(neePtr < neeLen && haystack[hayInd + neePtr] == needle[neePtr]){
                neePtr++;
            }

            if(neePtr == neeLen) return hayInd;
        }

        return -1;
    }
};