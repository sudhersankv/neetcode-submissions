class Solution {
public:
    int countSubstrings(string s) {

    // from examples we can know that, each individual char can be a palindrome, so there will be atleast s.size() substrings that are palindromic

    if(s.empty())
    {
        return 0;
    }

    int count = 0;

    //we can start from each index, and move left and right from it to find palindromes, first move left, if palindrome, count++, then check right, if palindrome, count ++, then start moving both sides until not palindrome.

    // there can be an issue when we check both left and right, we can count same 2 char palindrome from either pos, so let's stick to only check left, then check both


    for(int i = 0; i < s.size(); i++)
    {
        // if(i > 0 && s[i] == s[i-1])
        // {
        //     count++;
        // }

        int l = i;
        int r = i;


        while(l>=0 && r < s.size())
        {
            if(s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }


        l = i;
        r = i+1;
        

        while(l>=0 && r < s.size())
        {
            if(s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }

        
    }

    return count;
        
    }
};
