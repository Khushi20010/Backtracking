#include<iostream>
#include<vector>
using namespace   std;
void generateBinaryStrings(int n , int index , vector<int>&current){
    if(index == n){
        for(int bit:current){
            cout<<bit;
        }
        cout<<endl;
        return;
    }
    current[index] = 0;
    generateBinaryStrings(n ,  index+1 , current);
    current[index] =1;
    generateBinaryStrings(n , index+1 , current);
}
int main(){
    int n;
    cout<<"Enter n :  ";
    cin>>n;
    vector<int>current(n);
    generateBinaryStrings(n , 0 , current);
    return 0;
}