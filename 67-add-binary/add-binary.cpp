class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;

        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int bit_sum = carry;
            
            if (i >= 0) {
                bit_sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                bit_sum += b[j] - '0';
                j--;
            }

            result = to_string(bit_sum % 2) + result;
            carry = bit_sum / 2;
        }
        
        return result;
    }
};