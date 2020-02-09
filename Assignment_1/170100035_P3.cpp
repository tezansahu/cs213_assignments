#include<bits/stdc++.h>

using namespace std;

int findMaxRevenue(int* selling_price, int n){
    int maxRevenue = 0;

    int partition[n];
    partition[0] = n;
    int lastElement = 0;
    

    while(true){
        int revenue = 0;
        for(int i = 0; i <= lastElement; i++){
            revenue += selling_price[partition[i]-1];
        }
        if (revenue > maxRevenue) maxRevenue = revenue;

        int numOnes = 0;
        while(lastElement >= 0 && partition[lastElement] == 1){
            numOnes++;
            lastElement--;
        }

        if(lastElement < 0) break;

        partition[lastElement]--;
        numOnes++;

        while(numOnes > partition[lastElement]){
            partition[lastElement + 1] = partition[lastElement];
            numOnes -= partition[lastElement];
            lastElement++;
        }

        partition[++lastElement] = numOnes;
    }

    return maxRevenue;
}


int main(int argc, char* argv[]){
    int n;
    cin>>n;
    int selling_price[n];
    for(int i = 0; i < n; i++) {
        cin>>selling_price[i];
    }

    int max_rev = findMaxRevenue(selling_price, n);
    cout<<max_rev<<endl;

}