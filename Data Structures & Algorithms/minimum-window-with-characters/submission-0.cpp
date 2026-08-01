class Solution {
public:

    bool validWindow(const unordered_map<char, int>& win_elements ,const unordered_map<char, int>& t_elements){

        for(const auto& it : t_elements){
            char c = it.first;
            int freq = it.second;
            auto found = win_elements.find(c);
            if(found == win_elements.end() || found->second < freq){
                return false;
            }
        }
        return true;
    }

    string minWindow(const string& s, const string& t) {
        
        int n_s = s.size();
        int n_t = t.size();

        unordered_map<char, int> t_elements;
        for(const auto& c : t){
            t_elements[c]++;
        }

        int l = 0;
        int r = 0;

        unordered_map<char, int> window_elements;

        int mn_len = INT_MAX;
        int mn_r = 0, mn_l = 0;

        while(r < n_s){
            window_elements[s[r]]++;

            while(validWindow(window_elements, t_elements)){
                if(mn_len > r - l + 1){
                    mn_len = r - l + 1;
                    mn_r = r;
                    mn_l = l;
                }
                window_elements[s[l]]--;
                if(window_elements[s[l]] == 0){
                    window_elements.erase(s[l]);
                }
                l++;
            }

            r++;

        }

        if(mn_len == INT_MAX) return "";

        string ans = "";

        for(int i = mn_l; i <= mn_r; i++){
            ans += s[i];
        }

        return ans;

    }
};
