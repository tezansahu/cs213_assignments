#include<bits/stdc++.h>

using namespace std;

// Function to merge 2 sorted arrays, each of size n1 & n2 respectively. Complexity = O(n1 + n2)
void mergeSortedArrays(int* a, int* b, int* c, int n1, int n2){
    int a_i = 0, b_i = 0;
    for (int c_i = 0; c_i < n1 + n2; c_i++){
        if(a_i == n1) c[c_i] = b[b_i++];
        else if(b_i == n2) c[c_i] = a[a_i++];
        else if(a[a_i] > b[b_i]) c[c_i] = b[b_i++];
        else c[c_i] = a[a_i++];
    }
}

int main(int argc, char* argv[]){
    int n1, n2;
    int n;
    int arr[n];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(i>0 && arr[i]<arr[i-1]){
            n1 = i;
            n2 = n-n1;
        }
    }
    // cin>>n1>>n2;
    int a[n1], b[n2];

    // // Take 2 sorted arrays of size n as inputs
    for(int i = 0; i < n1; i++){
        a[i] = arr[i];
    }
    
    for(int i = 0; i < n2; i++){
        b[i] = arr[i+n1];
    }
    
    int c[n1 + n2];
    mergeSortedArrays(a, b, c, n1, n2); 

    for(int i = 0; i < n1 + n2; i++){
        cout<< c[i] << " ";
    }
    cout<<"\n";
}