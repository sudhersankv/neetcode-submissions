class Solution {
public:
    int characterReplacement(string s, int k) {

        std::unordered_map<char, int> freq;


        int l = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++)
        {   
            freq[s[r]]++;
            maxFreq = std::max(maxFreq, freq[s[r]]);

            // window length - maxFreq <= k

            while((r-l+1) - maxFreq > k)
            {
                freq[s[l]]--;
                l++;
            }

            maxLen = std::max((r-l+1), maxLen);

        }

        return maxLen;
        
    }
};
