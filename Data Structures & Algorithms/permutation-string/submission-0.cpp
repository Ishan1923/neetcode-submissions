class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        int l = 0, r = 0;

        unordered_map<char, int> freq1;

        for(const char& c : s1) freq1[c]++;

        unordered_map<char, int> freq2;

        while(r < n2){
            freq2[s2[r]]++;

            int len = r - l + 1;
            if(len == n1){
                bool found = true;
                for(const auto& it : freq1){
                    if(freq2[it.first] != it.second){
                        found = false;
                        break;
                    }
                }

                if(found == true) return true;

                freq2[s2[l]]--;

                if(freq2[s2[l]] == 0){
                    freq2.erase(s2[l]);
                }

                l++;
                r++;
            }
            else if(len < n1){
                r++;
            }
            else{
                freq2[s2[l]]--;

                if(freq2[s2[l]] == 0){
                    freq2.erase(s2[l]);
                }

                l++;
            }

        }

        return false;

    }
};
