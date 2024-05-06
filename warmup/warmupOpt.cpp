#include<iostream>
using namespace std;
void making(int* arr,int N){
    for(int i=0;i<N;i++){
        arr[i]=i+1;
    }
}
void add(int *arr,int n){
    // int sum =0;
    // for(int i=0;i<n;i++){
    //     sum+=arr[i];
    // }
    cout<<(n*(n+1))/2<<endl;
    // cout<<sum<<endl;
}

int main(){
    const int N=1000;
    int arr[N];
    making(arr,N);
    add(arr,N);

    return 0;
}