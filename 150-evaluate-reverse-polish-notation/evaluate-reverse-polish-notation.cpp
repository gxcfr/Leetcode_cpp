class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string token : tokens) {

            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = s.top(); //important as operands like / and - need them to be in order
                s.pop();

                int a = s.top(); // or simply b/a can be done lol
                s.pop();

                if (token == "+")
                    s.push(a + b);
                else if (token == "-")
                    s.push(a - b);
                else if (token == "*")
                    s.push(a * b);
                else
                    s.push(a / b);
            }
            else {
                s.push(stoi(token)); // push if number hai, stoi= string to int
            }
        }

        return s.top();
    }
};