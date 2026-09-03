#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Pushed 10,20, 30 " << endl;

    cout << "Current size: " << st.size() << endl;

    cout << "Top element: " << st.top() << endl;

    st.pop();
    cout << "Popped one element" << endl;
    cout << "Top element after pop: " << st.top() << endl;

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    cout << "Popping all remaining elements: " << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    cout << "Is stack empty now? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}