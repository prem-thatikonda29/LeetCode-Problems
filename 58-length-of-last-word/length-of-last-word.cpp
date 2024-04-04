class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<string> st;
        string word="";
        for(char c : s){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                word+=c;
            }
            else if(c==' '){
                if(!word.empty()){
                    st.push(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            st.push(word);
        }
        if (st.empty()) {
            return 0;
        }
        return st.top().length();
    }
};