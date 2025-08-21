#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row , int col , int n , vector<string>&board){
    for(int i =row-1 , j=col-1; i>= 0 && j>=0; i--  , j--){
        if(board[i][j] == 'Q') return false;
    }
    for(int j=col-1; j>=0; j-- ){
        if(board[row][j] == 'Q' ) return false;
    }
    for(int i=row+1 , j =col-1; i<n&&j>=0; i++ ,j--){
        if(board[i][j] == 'Q') return false;
    }
   return true;
   
    
}

 void solve(int col ,vector<string>&board , int n , vector<vector<string>>&solution){
 if(col == n){
        solution.push_back(board);
        return;
    }
for(int row = 0  ; row<n; row++){
    if(isSafe(row , col ,n ,  board )){
        board[row][col] = 'Q';
        solve(col +1 , board , n , solution);
        board[row][col] = '.';
    }
}



}

vector<vector<string>>solveNqueens(int n){
    vector<vector<string>>solution;
    vector<string>board(n , string(n , '.'));
    solve(0 , board, n , solution);
    return solution;
}
int main(){
    int n;
    cout<<"Enter the size of chess:  ";
    cin>>n;
    vector<vector<string>>solution = solveNqueens(n);
    cout<<"Number of solutions:  "<<solution.size()<<endl;
    for(auto&sol:solution){
        for(auto&row:sol){
            cout<<row<<endl;
        }
        cout<<endl;
    }
    return 0;
}
