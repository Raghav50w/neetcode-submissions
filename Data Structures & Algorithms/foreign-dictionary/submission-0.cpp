class Solution {
public:
    string ans;

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, bool> visit;

        for(string& word: words) {
            for(char ch: word) {
                adj[ch];
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLength = min(w1.size(), w2.size());

            if(w1.size() > w2.size() && w1.substr(0, minLength) == w2.substr(0, minLength))
                return "";

            for(int j = 0; j < minLength; j++) {
                if(w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for(auto& curr: adj) {
            if(dfs(curr.first, adj, visit)) return "";
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool dfs(char ch, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, bool>& visit) {
        if(visit.find(ch) != visit.end()) return visit[ch];
        visit[ch] = true;

        for(char next: adj[ch]) {
            if(dfs(next, adj, visit)) return true;
        }

        visit[ch] = false;
        ans.push_back(ch);

        return false;

    }
};
