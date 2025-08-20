#include<iostream>
#include<vector>
using namespace std;
void printSubsets(int arr[] , int n , int index , vector<int>& current){
    if(index == n){
      cout<<"{";
     for( int num:current){
        cout<<num<<" ";
     }
     cout<<"}";
        return ;
    }
    current.push_back(arr[index]);
    printSubsets(arr , n , index+1 , current );
    current.pop_back();
     printSubsets(arr , n , index+1 , current );

}
int  main(){
    int arr []= {12,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>current;
    printSubsets(arr , n , 0 ,current );
}