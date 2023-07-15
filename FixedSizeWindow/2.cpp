// Given an array A[] of size N and a positive integer K, 
// find the first negative integer for each and every window(contiguous subarray) of size K.

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int max = INT_MIN;
    int N;
    cout<<"Enter size : ";cin>>N;
    int arr[N];
    for(int i = 0;i < N; i++){
        cin>>arr[i];
    }
    int K;
    cout<<"Enter the size of subarray : ";cin>>K;

    int i = 0, j = 0;
    list<int> l1;
    while(j < N){
        if((j-i+1) < K){

            if(arr[j] < 0)
                l1.push_back(arr[j]);
            
            j++;
        
        }else if((j-i+1) == K){
            if(!l1.empty())
                cout<<l1.front()<<" ";
            else
                cout<<"0"<<" ";
            
            if(l1.front() == arr[i])
                l1.pop_front();
            i++;
        }
    }

    return 0;
}