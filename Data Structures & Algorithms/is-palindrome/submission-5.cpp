class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.size() - 1;

        for(char& c:s)
        {
            c = std::tolower(c);
        }

        while(l<r)
        {


            if(!std::isalnum(s[l]))
            {
                l++;
                continue;
            }
            if(!std::isalnum(s[r]))
            {
                r--;
                continue;
            }
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }

        }
        return true;
        
    }
};
