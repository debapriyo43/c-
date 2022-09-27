#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n,int k){
    deque<int> maxi;
    deque<int> mini;
    for (int i = 0; i < k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()]>= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    // for (int i = 0; i < k; i++)
    // {

    //     while (!maxi.empty() && arr[maxi.back()] <= arr[i])
    //         maxi.pop_back();

    //     while (!mini.empty() && arr[mini.back()] >= arr[i])
    //         mini.pop_back();

    //     maxi.push_back(i);
    //     mini.push_back(i);
    // }
    int ans = maxi.front()+mini.front();
    for (int i = k; i < n;i++){
        //removal of the before k size windows
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }
        //adding of element indexes
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans += maxi.front() + mini.front();
    }
    return ans;
    // for (int i = k; i < n; i++)
    // {

    //     // next window

    //     // removal
    //     while (!maxi.empty() && i - maxi.front() >= k)
    //     {
    //         maxi.pop_front();
    //     }

    //     while (!mini.empty() && i - mini.front() >= k)
    //     {
    //         mini.pop_front();
    //     }

    //     // addition

    //     while (!maxi.empty() && arr[maxi.back()] <= arr[i])
    //         maxi.pop_back();

    //     while (!mini.empty() && arr[mini.back()] >= arr[i])
    //         mini.pop_back();

    //     maxi.push_back(i);
    //     mini.push_back(i);

    //     ans += arr[maxi.front()] + arr[mini.front()];
    // }
    // return ans;
}
int main(){
    int arr[10] = {1,2,-2,5,7,-10,14,-17,18,20};
    int k = 3;
    cout << solve(arr, 10, k);
    return 0;
}