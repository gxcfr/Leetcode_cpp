class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string word : strs) {
            string key(26, '0');

            for (char c : word) {
                key[c - 'a']++;
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto& p : mp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};