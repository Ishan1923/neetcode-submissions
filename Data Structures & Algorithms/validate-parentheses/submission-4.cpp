class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto& c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(st.empty() && (c == ')' || c =='}' || c == ']')) return false;
            else if((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '[') ){
                st.pop();
            }
            else return false;
        }

        return st.empty();

    }
};
