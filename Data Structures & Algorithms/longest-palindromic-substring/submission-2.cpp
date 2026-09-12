class Solution {
public:
    string longestPalindrome(string s) {

        // idea is from every point, i will be searching either side to see it it's a palindrome, if yes, store that as the longest. ( better store just the indices), later we can construct the substring.

        // let the final indices we need be, a,b
        int a = 0;
        int b = 0;

        int maxlen = 0;
        


        // let's loop through the string once

        for(int i = 0; i < s.size(); i++)
        {   

            int l = i;
            int r = l;

            while(l >= 0 && r < s.size())
            {
                if(s[l] == s[r])
                {
                    if(r-l+1 > maxlen)
                    {
                        maxlen = r-l+1;
                        a = l;
                        b = r;
                    }
                    r++;
                    l--;
                }
                else
                {
                    break;
                }
            }





            l = i;
            r = l+1;

            while(l >= 0 && r < s.size())
            {
                if(s[l] == s[r])
                {
                    if(r-l+1 > maxlen)
                    {
                        maxlen = r-l+1;
                        a = l;
                        b = r;
                    }
                    r++;
                    l--;
                }
                else
                {
                    break;
                }
            }

        }


        std::string output;
        output = s.substr(a, b-a+1);

        return output;
        
    }
};
