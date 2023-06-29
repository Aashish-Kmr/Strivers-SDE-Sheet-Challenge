bool isValidParenthesis(string e)
{
    std::stack<char> s1;
    s1.push('a'); // Add a sentinel value to handle the case of an empty string

    for (int i = 0; i < e.size(); i++) {
        if (e[i] == '(' || e[i] == '[' || e[i] == '{') {
            s1.push(e[i]);
        } else if (e[i] == ')' || e[i] == ']' || e[i] == '}') {
            char t = s1.top();
            if ((t == '(' && e[i] == ')') ||
                (t == '[' && e[i] == ']') ||
                (t == '{' && e[i] == '}')) {
                s1.pop();
            } else {
                s1.push(e[i]);
            }
        }
    }

    if (s1.size() == 1) {
        return true;  // Stack should contain only the sentinel value if parentheses are valid
    } else {
        return false;
    }
}