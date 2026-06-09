class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for ( char c : s){
            c=  tolower(c);
            if (isalnum(c)){
                t += c;
            }
        }

        int i =0; int j = t.length()-1;

        while (i<j){
            if (t[i] == t[j]){
                i++;
                j--;
            }
            else return false;
        }

        return true;

        

    }
};