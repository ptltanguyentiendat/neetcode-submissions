class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If we get a closing bracket but the stack is empty, it's invalid
                if(st.empty()) return false;
                
                // If it doesn't match the top of the stack, it's invalid
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                
                // If it matched, pop the open bracket from the stack
                st.pop();
            }
        }
        return st.empty();
    }
};