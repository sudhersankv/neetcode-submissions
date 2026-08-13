class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char, int> countS;
        std::unordered_map<char, int> countT;

        for(char c : s)
        {
            
            if(countS.find(c) != countS.end())
            {
                countS[c]++;
            }
            else
            {
                countS[c] = 1;
            }
        }

        for(char c : t)
        {
            if(countT.find(c) != countT.end())
            {
                countT[c]++;
            }

            else
            {
                countT[c] = 1;
            }}
        if(countS == countT)
        {return true;}

        return false;
        }
};
