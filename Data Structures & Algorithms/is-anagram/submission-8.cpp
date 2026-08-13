class Solution {
public:
    bool isAnagram(string s, string t) {



        std::unordered_map<char, int> count;


        if(s.size() != t.size())
        {
            return false;
        }

        for(char c : s)
        {
            count[c]++;
        }

        for(char c : t)
        {
            count[c]--;
        }   

        for(const auto& pair : count)
        {
            if(pair.second !=0)
            {return false;}

        }
        return true;
        
    }
};
