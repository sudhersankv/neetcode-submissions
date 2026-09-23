class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 

        auto sorted = strs;
        unordered_map<string, vector<string>> anagrams;

        for(auto &x : sorted)
        {
            std::sort(x.begin(), x.end());
        }

        for(int i = 0; i < sorted.size(); i++)
        {
            anagrams[sorted[i]].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto x: anagrams)
        {
            result.push_back(x.second);
        }

        return result;
        
    }
};
