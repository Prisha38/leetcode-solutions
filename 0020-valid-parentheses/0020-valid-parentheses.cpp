

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing bracket
            else {
                if (st.empty())
                    return false;

                char top = st.top();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};