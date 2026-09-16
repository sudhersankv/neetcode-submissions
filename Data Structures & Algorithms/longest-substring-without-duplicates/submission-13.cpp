class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //need a set to check char occurences

        if(s.size() == 0)
        {
            return 0;
        }

        std::unordered_set<char> seen;

        int l = 0;

        int maxLen = 0;

        for(int r = 0; r < s.size(); r++)
        {    
            if(seen.find(s[r]) != seen.end())
            {
                while(seen.find(s[r]) != seen.end())
                {
                    seen.erase(s[l]);
                    l++;
                }
            }
            
            seen.insert(s[r]);
            maxLen = std::max(maxLen, r-l+1);


        }


        return maxLen;
        

        
    }
};
