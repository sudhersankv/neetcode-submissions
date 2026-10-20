class Solution {
public:
    string longestPalindrome(string s) {

        // read from first charater and check either sides of it and see how long it goes as a palindrome, using a two pointer approach.

        int l = 0;

        int bestL = 0;
        int bestR = 0;
        

        for(int i = 0; i < s.size(); i++)
        {
            int l = i;
            int r = l;

            while(l >= 0 && r < s.size() && s[l]==s[r])
            {
                l--;
                r++;
            }

            if(r-l-1 > bestR-bestL-1)
            {
                bestL = l;
                bestR = r;
            }
        }


        for(int i = 0; i < s.size(); i++)
        {
            int l = i;
            int r = l+1;

            while(l >= 0 && r < s.size() && s[l]==s[r])
            {
                l--;
                r++;
            }

            if(r-l-1 > bestR-bestL-1)
            {
                bestL = l;
                bestR = r;
            }
        }


        string result = s.substr(bestL+1, bestR-bestL-1);

        // cout<<"bestL:"<<bestL<<'BestR:'<<bestR;


        return result;
        

    }
};
