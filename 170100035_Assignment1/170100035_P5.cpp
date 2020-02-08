#include<bits/stdc++.h>

using namespace std;

const int SIZE = 100000;

// Function to merge 2 sorted arrays, each of size n1 & n2 respectively. 
// Complexity = O(n1 + n2) [From P4]
void mergeSortedArrays(int* a, int* b, int* c, int n1, int n2){
    int a_i = 0, b_i = 0;
    for (int c_i = 0; c_i < n1 + n2; c_i++){
        if(a_i == n1) c[c_i] = b[b_i++];
        else if(b_i == n2) c[c_i] = a[a_i++];
        else if(a[a_i] > b[b_i]) c[c_i] = b[b_i++];
        else c[c_i] = a[a_i++];
    }
}

// This function uses the approach in P4 recursively
// Complexity = O(n * k^2)
void kWaySort1(int kArr[][SIZE], int k, int n, int* finalArr){

    for(int i = 0; i < n; i++){
        finalArr[i] = kArr[0][i];
    }

    for(int i = 1; i < k; i++){
        int newArr[n * (i + 1)];
        mergeSortedArrays(finalArr, kArr[i], newArr, i*n, n);
        for(int i = 0; i < n * (i+1); i++){
            finalArr[i] = newArr[i];
        }
    }

}

int main(int argc, char* argv[]){
    int n, k;
    cin>>n>>k;
    int arr[k][SIZE];  // To store the k arrays each of n elements

    int sortedFinal[k*n];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    kWaySort1(arr, k, n, sortedFinal);

    for(int i = 0; i < k*n; i++){
        cout<<sortedFinal[i]<<" ";
    }
    cout<<"\n";
}