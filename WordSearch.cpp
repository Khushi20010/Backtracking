#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool searchWord(vector<vector<char>>&board , int index , string&word , int x , int y){
    int rows = board.size();
     int cols = board[0].size();

     if(index == word.size()) return true;
     if(x<0||y<0||x>=rows||y>=cols||
    board[x][y] != word[index]) return false;

    char temp = board[x][y];
    board[x][y]  = '#'; //visited
    bool found = searchWord(board , index+1 , word , x+1 , y)||
                      searchWord(board , index+1 , word , x-1 , y)||
                       searchWord(board , index+1 , word , x , y+1)||
                        searchWord(board , index+1 , word , x , y-1);
                        board[x][y] = temp;
                        return found;

}
bool exist(vector<vector<char>>&board , string word ){
for(int i=0;i<board.size(); i++)
for(int j=0;j<board[0].size();j++)
if(searchWord(board , 0 , word, i,j )) return true;

return false;
}
int main(){
    vector<vector<char>>board = {
    {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABFCE";
    cout<<(exist(board , word)?"Found" : "Not Found")<<endl;
    return 0;
  
}
