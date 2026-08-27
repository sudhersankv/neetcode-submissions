class Solution {
public:
    int characterReplacement(string s, int k) {
        //AABBSSKKSKLS
        //k

        //brute force

        // for a sub set to be valid, we effectively want len subset - freq of most freq char <= k.

        std::unordered_map<char,int> freq;

        int l = 0;
        int maxfreq = 0;
        int maxlen = 0;
        
        for(int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;           //A:4 B:1 
            maxfreq = std::max(maxfreq,freq[s[r]]);

            while((r-l+1) - maxfreq > k)
            {
                freq[s[l]]--;
                l++;
            }
            
            maxlen = std::max(maxlen, r-l+1);
            



        }

        return maxlen;
        
    }
};
