#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isSafe(int x , int y ,int n, vector<vector<int>>&maze , vector<vector<int>>&visited){
return (x>=0&&x<n&&y>=0&&y<n&&maze[x][y] ==1 &&visited[x][y] == 0);
}
void solve(int x , int y ,int n, vector<vector<int>>&maze , vector<vector<int>>&visited , string path , vector<string>&ans){
    if(x == n-1&&y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    //down
    if(isSafe(x+1 , y , n , maze , visited))
    solve(x +1, y , n ,maze , visited , path+"D" , ans);
    //uP
      if(isSafe(x-1 , y , n , maze , visited))
    solve(x-1 , y , n ,maze , visited , path+"D" , ans);
    //left
      if(isSafe(x , y-1 , n , maze , visited))
    solve(x , y-1 , n ,maze , visited , path+"D" , ans);
    //right
      if(isSafe(x, y+1 , n , maze , visited))
    solve(x , y+1 , n ,maze , visited , path+"D" , ans);
       visited[x][y] = 0;

}
int main(){
    int n =4;
    vector<vector<int>>maze = {
        {1,1,1,1}, 
        {1,0,0,1} ,
        {0,1,0,1} ,
        {0,0,1,1} ,
    };
    vector<vector<int>>visited(n ,vector<int>(n ,0));
    vector<string>ans;
    if(maze[0][0] = 1)
    solve(0   ,0 ,n , maze ,visited , " " , ans );
    for(auto&path:ans)
    cout<<path<<endl;
    return 0;

}
