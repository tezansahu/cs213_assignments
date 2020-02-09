#include<bits/stdc++.h>

using namespace std;

// [From P4] Function to merge 2 sorted arrays, each of size n1 & n2 respectively. 
// Complexity = O(n1 + n2) 
void mergeSortedArrays(int* a, int* b, int* c, int n1, int n2){
    int a_i = 0, b_i = 0;
    for (int c_i = 0; c_i < n1 + n2; c_i++){
        if(a_i == n1) c[c_i] = b[b_i++];
        else if(b_i == n2) c[c_i] = a[a_i++];
        else if(a[a_i] > b[b_i]) c[c_i] = b[b_i++];
        else c[c_i] = a[a_i++];
    }
}

// Approach 1: Merge 1st 2 arrays, then merge the 3rd with the merged version, & so on
// Complexity = O(nk * k)
void kWaySort1(int arr[], int k, int n, int* finalArr){

    for(int i = 0; i < n; i++){
        finalArr[i] = arr[i];
    }

    for(int i = 1; i < k; i++){
        int newArr[n * (i + 1)];
        int arr2[n];
        for(int j = 0; j < n; j++){
            arr2[j] = arr[n*i + j];
        }
        mergeSortedArrays(finalArr, arr2, newArr, i*n, n);
        for(int j = 0; j < n * (i+1); j++){
            finalArr[j] = newArr[j];
        }
    }
}

// Approach 2: Create the array of size n*k & use bubble sort on the large array
// Complexity = O(nk log(nk))
void kWaySort2(int arr[], int n, int k, int* sortedArr){
    for(int i = 0; i < n*k-1; i++){
        for(int j = 0; j < n*k - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                arr[j] += arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }

    for(int i = 0; i < n*k; i++){
        sortedArr[i] = arr[i];
    }
}
// Approach 3: Merge the first 2 arrays (each of size n), then the next 2, and so on. 
// After the 1st iteration, merge the 1st 2 merged arrays (each of size 2n), and so on.
// Continue until only 1 array is left, which is the sorted array.
// Complexity = O(nk log(k))
void kWaySort3(int arr[], int n, int k, int* sortedArr){
    // Function not implemented
}

int main(int argc, char* argv[]){
    int n, k;
    cin>>n>>k;
    int arr[n*k];

    for(int i = 0; i<n*k; i++){
        cin>>arr[i];
    }

    int sortedFinal[k*n];

    // kWaySort1(arr, k, n, sortedFinal);
    kWaySort2(arr, k, n, sortedFinal);

    for(int i = 0; i < k*n; i++){
        cout<<sortedFinal[i]<<" ";
    }
    cout<<"\n";
}