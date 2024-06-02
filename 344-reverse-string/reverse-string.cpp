class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        int temp;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};