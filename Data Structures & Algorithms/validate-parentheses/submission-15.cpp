class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        // unordered_set<char> open{'{', '(', '['};
        

        for(char a: s)
        {
            if(a == '{' or a == '(' or a == '[')
            {
                st.push(a);
            }
            else if(!st.empty() && ((a == '}' && st.top() == '{') or (a == ']' && st.top() == '[') or (a == ')' && st.top() == '(')))
            {
                st.pop();
            }
            else{
                return false;
            }
        }

        if(st.empty())
        {
            return true;
        }

        return false;
        
    }
};
