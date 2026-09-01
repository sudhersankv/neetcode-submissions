class Solution {
public:
    bool isPalindrome(string s) {

        // first i wanna convert everything to lowercase

        if(s.size() < 2)
        {
            return true;
        }
        
        for(auto& c : s)
        {
            c = std::tolower(c);
        }

        int l = 0;
        int r = s.size() - 1;
        

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

            if(s[l] == s[r])
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
