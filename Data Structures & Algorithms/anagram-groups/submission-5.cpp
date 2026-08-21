class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<string, std::vector<string>> anagram;
        std::vector<vector<string>> result;

        for(std::string x:strs)
        {
                std::string sorted_x = x;
                std:sort(sorted_x.begin(), sorted_x.end());

                anagram[sorted_x].push_back(x);
        }

        for(auto p : anagram)
        {
            result.push_back(p.second);
        }
        return result;
    }
};
