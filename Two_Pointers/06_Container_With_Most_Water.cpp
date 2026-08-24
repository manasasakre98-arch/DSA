/*
Problem: Container With Most Water (two pointers)

Algorithm:
1. left =0 , right = n-1
2. While left < right:
   - width = right - left
   - height = min(arr[left], arr[right])
   - area = width * height
   - track maxArea
   - move the pointer ar the SHORTER line inward
     (moving the taller one can only reduce or maintain area, never improve it)

Time Complexity: O(n) - each pointer moves at most n times total
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int maxArea(int height[], int n){
    int left = 0, right = n-1;
    int maxArea = 0;

    while (left < right){
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = width * h;
        maxArea = max(maxArea, area);

        if(height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
int main(){
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
     int n = 9;
     cout << maxArea(height, n);
     return 0;
}