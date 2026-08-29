class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> warmer_days(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                auto top = st.top();
                st.pop();
                int diff = i - top;
                warmer_days[top] = diff;
            }
            st.push(i);
        }
        return warmer_days;
    }
};
