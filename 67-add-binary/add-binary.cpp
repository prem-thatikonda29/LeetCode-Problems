class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int sum = 0;

        while(i >= 0 || j >= 0 || sum){
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            ans = char(sum % 2 + '0') + ans;
            sum /= 2; 
        }

        return ans;
    }
};