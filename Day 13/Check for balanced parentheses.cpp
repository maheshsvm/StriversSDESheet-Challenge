class Solution {
private:
    bool isOpening(char ch){
        return (ch == '(' || ch == '{' || ch == '[');
    }
    
    bool match(char ch1 , char ch2){
        return ((ch1 == '{' && ch2 == '}') || (ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') );
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(isOpening(ch)){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    if(match(st.top() , ch)){
                    st.pop();
                    }
                    else{
                     return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.empty()){
            return true;
        }
        return false;
    }
};