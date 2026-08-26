class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> st;
        stack<int> star;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
            else if (s[i] == '*'){
                star.push(i);
            }
        }   


        while(!st.empty() && !star.empty()){
            int top1 = st.top();
            int top2 = star.top();
            if(top1 > top2) return false;
            st.pop();
            star.pop();
        }

        return st.empty();
    }
};
