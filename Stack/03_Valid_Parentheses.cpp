#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(char c : s){
        if (c == '(' || c == '{' || c == '['){
            st.push(c);
            continue;
        }

        if(st.empty()){
            return false;
        }

        char topChar = st.top();

        if((c == ')' && topChar == '(') ||
           (c == '}' && topChar == '{') ||
           (c == ']' && topChar == '[')){
            st.pop();
           }else{
            return false;
           }
    }
    return st.empty();
}

int main(){
    string tests[] = {"()", "()[]{}", "(]", "([)]", "{[]}", "", "(", ")"};

    for(const string& test : tests){
        cout << "\"" << test << "\" -> " << (isValid(test) ? "true" : "false") << endl;
    }
    return 0;
}