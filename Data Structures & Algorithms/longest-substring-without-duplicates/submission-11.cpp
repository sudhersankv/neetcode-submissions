class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // we have a string s, and want to iterate thrugh it and find the longest valid substring
        // a substring is valid if it has no repeating characters\
        // we do not want what the longest substring contains

        // a brute force would be to start from each char and iterate until we find a duplicate.

        // that would be O(n^2)

        // we want something that is more optimal, like in a single pass
        
        // i am thinking of having a moving window that tracks character occurences.

        int l = 0;

        // we would also need a global variable to track the max len of a valid substring

        // to check occurences, we need an imporant data structure that would let us do membership checks at O(1) time

        std::unordered_set<char> seen;

        int max = 0;

        for(int r = 0; r < s.size(); r++)
        {
            if(seen.find(s[r]) != seen.end())
            {
                while(l!=r)
                {
                    if(s[l] == s[r])
                    {
                        seen.erase(s[l]);
                        l++;
                        break;
                    }
                    seen.erase(s[l]);
                    l++;
                }
            }
            seen.insert(s[r]);
            max = std::max((r-l+1), max);
        }


        return max;


        
    }
};
