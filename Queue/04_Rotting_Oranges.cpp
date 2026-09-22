#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
   int orangeRotting(vector<vector<int>>& grid){
    if(grid.empty() || grid[0].empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    int freshCount = 0;

    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            if(grid[r][c] == 2){
                q.push({r, c});
            } else if(grid[r][c] == 1){
                freshCount ++;
            }
        }
    }

    if(freshCount == 0) return 0;

    int minutes = 0;
    int directions[4][2] = {{-1,0}, {1,0},{0,-1},{0,1}};

    while(!q.empty()){
        int size = q.size();
        bool rottedThisMinute = false;

        for(int i=0; i<size; i++){
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            for(auto& dir: directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if(newRow >= 0 && newRow < rows && 
                   newCol >= 0 && newCol < cols &&
                   grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    freshCount--;
                    q.push({newRow, newCol});
                    rottedThisMinute = true;
                   }
            }
        }
        if(rottedThisMinute) minutes++;
        
    }
    return freshCount == 0 ? minutes : -1;
   }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = sol.orangeRotting(grid);
    cout << "Minutes to rot all oranges: " << result << endl;

    return 0;
}