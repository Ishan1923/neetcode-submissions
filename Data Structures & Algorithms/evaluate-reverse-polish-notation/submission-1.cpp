class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        auto string2num = [](const string& s){
            bool flag = s[0] == '-' ? true : false;
            int num = 0;
            for(const int& digit : s){
                if(digit == '-') continue;
                num = num*10 + (digit - '0');
            }
            return flag ? -1 * num : num;
        };

        stack<int> st;

        for(int i = 0; i < n; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int num = string2num(tokens[i]);
                cout << num << endl;
                st.push(num);
            }
            else if(tokens[i] == "+"){
                int num1 = st.top();st.pop();
                int num2 = st.top();st.pop();
                int res = num2 + num1;
                st.push(res);
            }
            else if(tokens[i] == "-"){
                int num1 = st.top();st.pop();
                int num2 = st.top();st.pop();
                int res = num2 - num1;
                st.push(res);
            }
            else if(tokens[i] == "*"){
                int num1 = st.top();st.pop();
                int num2 = st.top();st.pop();
                int res = num2 * num1;
                st.push(res);
            }
            else if(tokens[i] == "/"){
                int num1 = st.top();st.pop();
                int num2 = st.top();st.pop();
                int res = num2 / num1;
                st.push(res);
            }
        }
        return st.top();
    }
};
