class Solution {
public:
    string s = "";
    string encode(vector<string>& strs) {
        for(int i = 0; i < strs.size(); i++) {
            s += strs[i];
            s += "\n";
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            string sub = ""; 
            while(i < s.size() && s[i] != '\n') {
                sub += s[i];
                i++;
            }
            ans.push_back(sub);
        }

        return ans;
    }
};
