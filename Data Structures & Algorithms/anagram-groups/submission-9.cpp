class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //use hashmap to count freq of each, for each string that would O(strlen x n.of strs x n)

        // count freq of char for each str

        // compare each hashmap with rest, if it matches, add them both

        //optimal approach is

        //sort each string alphametically, that would give us teh same sorted order for all anagrams, then use that as a key like a append each of them in there, like bucketing.


        //hashmap str key, value is array of strs

        std::unordered_map<std::string, std::vector<std::string>> anagrams;

        for(const auto& x: strs)
        {
            auto sorted = x;
            std::sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(x);            
        }

        std::vector<std::vector<std::string>> result;

        for(const auto& item : anagrams)
        {
            result.push_back(item.second);
        }

        return result;


        
    }
};
