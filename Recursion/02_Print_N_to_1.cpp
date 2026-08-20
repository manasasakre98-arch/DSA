#include<iostream>
using namespace std;

void printNTo1(int n)
{
    if (n==0) return;
    cout<<n<<"";
    printNTo1(n-1);
}
int main(){
    printNTo1(4);
    return 0;
}