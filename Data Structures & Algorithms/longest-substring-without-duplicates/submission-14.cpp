class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;

        int maxLen = 0;

        int l = 0;

        for(int r = 0; r < s.size(); r++)
        {
            if(seen.find(s[r]) == seen.end())
            {
                seen.insert(s[r]);
                
            }
            else{
            
            while(seen.find(s[r]) != seen.end())
            {
                seen.erase(s[l]);

                l++;
            }
            seen.insert(s[r]);
            }

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
        
    }
};
