// Given an array of integers A.  There is a sliding window of size B which 

// is moving from the very left of the array to the very right. 

// You can only see the w numbers in the window. Each time the sliding window moves 

// rightwards by one position. You have to find the maximum for each window. 

// The following example will give you more clarity.

// The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

// Window position	            Max
// ———————————---------     ————————-
// [1  3  -1] -3  5  3  6  7	3
// 1 [3  -1  -3] 5  3  6  7	    3
// 1  3 [-1  -3  5] 3  6  7	    5
// 1  3  -1 [-3  5  3] 6  7	    5
// 1  3  -1  -3 [5  3  6] 7	    6
// 1  3  -1  -3  5 [3  6  7]	7
// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
    int N;
    cout<<"Enter size : ";cin>>N;
    int arr[N];
    for(int i = 0;i < N; i++){
        cin>>arr[i];
    }
    int K;
    cout<<"Enter the size of subarray : ";cin>>K;

    int i=0, j=0, k=0;
    int ans[N-K+1];
    list<int> l1;

    bool isComp

    while(j < N){
        if((j - i + 1) < K){
            while(l1.size() > 0 && l1.back() < arr[j]){
                l1.pop_back();
            }
            l1.push_back(arr[j]);
            j++;

        }else if((j - i + 1) == K){
            ans[k] = l1.front();
            k++;

            if(l1.front() == arr[i]){
                l1.pop_front();
            }
            i++;
        }
    }

    for(int i = 0;i < N-K+1; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}