#include<bits/stdc++.h>

using namespace std;

struct chocolatePackets{
    int numChocolates;
    float price;
};

void sortPackets(chocolatePackets* packets, int n){  
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (packets[j].price < packets[j+1].price){
                chocolatePackets temp = packets[j];
                packets[j] = packets[j+1];
                packets[j+1] = temp; 
            } 
        }       
    }            
}


float findMaxRevenue(chocolatePackets* packets, int n){
    sortPackets(packets, n);
    int chocRem = n;
    float maxRevenue = 0;
    for(int i = 0; i < n; i++){
        int numPackets = chocRem / packets[i].numChocolates;
        maxRevenue += numPackets * packets[i].price;
        chocRem = chocRem % packets[i].numChocolates;
        if (chocRem == 0) break;
    }
    return maxRevenue;
}

int main(int argc, char* argv[]){
    int n;
    cin>>n;
    chocolatePackets packets[n];
    for(int i = 0; i < n; i++) {
        packets[i].numChocolates = i+1;
        cin>>packets[i].price;
    }
    float revenueMax = findMaxRevenue(packets, n);
    cout<<revenueMax;

}