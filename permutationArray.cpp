#include<iostream>
#include<vector>
using namespace std;
void permute(vector<int>&arr , int l , int r){
    if(l == r){
        for(int num: arr) cout<<num<<" ";
         cout<<endl;
    return ;
        
    }
   

    for(int i=l;i<=r;i++){
        swap(arr[l] , arr[i]);
        permute(arr , l+1 , r);
        swap(arr[l] , arr[i]);
    }
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    permute(arr , 0 , arr.size()-1);
    return 0 ;
}