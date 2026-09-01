class Solution {
public:
    string longestPalindrome(string s) {

        // idea is to start from every position and then expand outward to check for palindromes, store the longest substring

        // to keep the space complexity low, can just store the indices and later construct the string

        std::pair<int,std::pair<int,int>> meta;
        meta = {0, {0,0}};

        for(int i = 0; i < s.size(); i++)
        {
            int l = i;
            int r = i;

            while(l>=0 && r < s.size())
            {
                if(s[l] == s[r])
                {
                    if(meta.first < r-l)
                    {
                        meta.first = r-l;
                        meta.second ={l,r};
                    }
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
                    if(meta.first < r-l)
                    {
                        meta.first = r-l;
                        meta.second ={l,r};
                    }
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }


        }
        

        int start = meta.second.first;
        int end = meta.second.second;

        std::string result;

        result = s.substr(start,end-start+1);

        return result;
        
    }
};
