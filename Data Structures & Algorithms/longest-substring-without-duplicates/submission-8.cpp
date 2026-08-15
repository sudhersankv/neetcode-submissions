class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    int count = 0;
    std::unordered_set<char> seen;

    int l = 0;

    for(int r = 0; r < s.size(); r++)
    {
        while(seen.find(s[r]) != seen.end())
        {
            seen.erase(s[l]);
            l++;
        }
        seen.insert(s[r]);
        if((r-l+1) > count)
        {
            count = r - l + 1;
        }
    }

    return count;

        
    }
};
