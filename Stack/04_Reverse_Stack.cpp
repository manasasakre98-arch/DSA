#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& st, int value){
    if(st.empty()){
        st.push(value);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, value);

    st.push(top);
}

void reverseStack(stack<int>& st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, top);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);

    cout << "Reversed stack (top to bottom as popped):";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}