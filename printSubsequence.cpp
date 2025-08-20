#include<iostream>
#include<vector>
using namespace std;
void printSubsequence(int arr[] , int n , int index , vector<int>&current){
    if(index == n){
       cout << "{ ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }
    current.push_back(arr[index]);
    printSubsequence(arr , n ,index+1 , current);
    current.pop_back();
    printSubsequence(arr, n ,index+1 ,current);
}
int main(){
    int arr[] = {45,66,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>current;
    printSubsequence(arr , n , 0  ,current);
    return 0;
}