class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        std::unordered_set<char> seen;
        int maxLen = 0;
        int count;

        for(int i = 0; i < s.size(); i++)
        {   
            while(seen.find(s[i]) != seen.end())
            {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[i]);
            count = i-l+1;

            maxLen = std::max(count, maxLen);
            
        }
        
        return maxLen;
    }
};
