// Q.Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
// let arr = [2,5,1,8,2,9,1]
// FInd max sum of subarray of size 3

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int max = INT_MIN;
    int N;
    cout << "Enter size : ";
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int K;
    cout << "Enter the size of subarray : ";
    cin >> K;

    int i = 0, j = 0;
    int sum = arr[j];
    while ((j - i + 1) < K)
    {
        j++;
        sum += arr[j];
    }

    if (sum > max)
        max = sum;

    while (j != N)
    {
        sum = sum - arr[i];
        i++;
        j++;
        sum = sum + arr[j];

        if (sum > max)
            max = sum;
    }

    cout << "Max sum : " << max;

    return 0;
}