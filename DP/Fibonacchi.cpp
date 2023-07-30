#include <bits/stdc++.h>
using namespace std;

// Tabulation(BOTTOM-UP APPROACH)
// TC = O(N)
// SC = O(N)
int TabFibo1(int n, vector<int> &arr){
    if(n <= 1) return n;
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2;i<n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

// Tabulation(BOTTOM-UP APPROACH) Upgraded
// TC = O(N)
// SC = O(i)
int TabFibo2(int n){
    if(n <= 1) return n;
    int prev2 = 0;
    int prev = 1;
    int x = 0;
    for(int i = 2;i<n+1;i++){
        x = prev2 + prev;
        prev2 = prev;
        prev = x;
    }
    return prev;
}

// TOP-DOWN APPROACH
// TC = O(N)
// SC = O(N)
int Fibo(int n,vector<int> &arr){
    if(n <= 1) return n;
    if(arr[n] != -1) return arr[n];

    return arr[n] = Fibo(n-1,arr) + Fibo(n-2,arr);
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the index : ";
    cin>>n;
    vector<int> arr(n+1,-1);
    cout<<Fibo(n, arr)<<endl;
    cout<<TabFibo1(n, arr)<<endl;
    cout<<TabFibo2(n)<<endl;
    return 0;
}

