#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Pushed 10, 20, 30" << endl;

    cout << "Current size: " << q.size() << endl;

    cout << "Front element: " << q.front() << endl;

    cout << "Back element: " << q.back() << endl;

    q.pop();
    cout << "Popped front element" << endl;
    cout << "Front element after pop: " << q.front() << endl;

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    cout << "Popping all remaining elements:" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "Is queue empty now? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}