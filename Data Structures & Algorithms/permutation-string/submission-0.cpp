class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size())
        {
            return false;
        }

        int window = s1.size();

        std::unordered_map<char,int> s1freq;
        std::unordered_map<char,int> s2freq;

        for(char c : s1)
        {
            s1freq[c]++;
        }


        for(size_t i = 0; i < window; i++)
        {
            s2freq[s2[i]]++;
        }
        
        if(s1freq == s2freq){return true;}

        for(size_t i = window; i < s2.size(); i++)
        {
            s2freq[s2[i]]++;

            if(--s2freq[s2[i-window]] == 0)
            {
                s2freq.erase(s2[i-window]);
            }

            if(s1freq == s2freq){return true;}
        }

        return false;




        



        // for(const auto& pair : freq)
        // {
        // std::cout<<' '<<pair.first<<':'<<pair.second;
        // }
        // return true;
    }
};
