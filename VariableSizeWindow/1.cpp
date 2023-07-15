// Given an array containing N positive integers and an integer K. 
// Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

// For Input:
// 1
// 7 5
// 4 1 1 1 2 3 5
// your output is: 
// 4 

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int ans = INT_MIN;
    int N;
    cout<<"Enter size : ";cin>>N;
    int arr[N];
    for(int i = 0;i < N; i++){
        cin>>arr[i];
    }
    int K;
    cout<<"Enter the sum : ";cin>>K;

    int sum = 0;
    int i = 0, j = 0;

    while(j < N){
        sum += arr[j];
        if(sum == K){
            if(ans < (j-i+1))
                ans = (j-i+1);

            j++;
        }else if(sum > K){
            while(sum > K){
                sum -= arr[i];
                i++;
            }
            j++;
        }else if(sum < K){
            
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}