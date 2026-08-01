class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        int len = strs.size();

        encoded_string += (to_string(len) + ",");

        for(const auto& str : strs){
            int s  = str.size();
            encoded_string += (to_string(s) + ",");
        }

        for(const auto& str : strs){
            encoded_string += str;
        }

        return encoded_string;

    }

    vector<string> decode(string s) {

        int len = 0;
        int i = 0;
        while(s[i] != ','){
            len = len * 10 + (s[i] - '0');
            i++;
        }
        if(len == 0) return {};
        int count = 0;
        vector<int> sizes(len, 0);
        int j = 0;
        i++;
        while(count < len){
            if(s[i] == ','){
                j++;
                i++;
                count++;
                continue;
            }
            sizes[j] = sizes[j]*10 + (s[i] - '0');
            i++;
        }

        vector<string> decoded_string(len, "");

        for(int j = 0; j < len; j++){
            for(int k = 0; k < sizes[j]; k++){
                decoded_string[j] += s[i++];
            }
        }

        return decoded_string;

    }
};
