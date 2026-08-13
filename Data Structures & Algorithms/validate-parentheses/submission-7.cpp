class Solution {
public:
    bool isValid(string s) {

        std::stack<char> st;


        if(s[0] == ')' or s[0] == ']' or s[0] == '}')
        {
            return false;
        }

        for(char c : s)
        {
            if(c == '(' or c == '[' or c == '{')
            {
                st.push(c);
            }

            else if(!st.empty() and ((c ==')' and st.top() == '(') or (c == ']' and st.top() == '[') or (c == '}' and st.top() == '{')))
            {
                st.pop();
            }

            else
            {
                return false;
            }


        }

        return st.empty();
        
    }
};
