class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string& str : strs) {
            // Use to_string to handle lengths >= 10 properly
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            int num = stoi(s.substr(i, j - i));
            
            string str = s.substr(j + 1, num);
            ans.push_back(str);
            
            i = j + 1 + num;
        }
        
        return ans;
    }
};
