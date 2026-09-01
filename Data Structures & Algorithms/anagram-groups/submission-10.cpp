class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> anagrams;

        std::vector<std::vector<std::string>> result;

        for(auto& s : strs)
        {
            std::string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            
            anagrams[sorted].push_back(s);
        }

        for(auto item:anagrams)
        {
            result.push_back(item.second);
        }

        return result;
        
    }
};
