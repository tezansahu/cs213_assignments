#include<bits/stdc++.h>

using namespace std;

pair<int, int> getMaxProfit(int* stock_prices, int n){
    int buy_day = 0, max_profit_till_now = INT16_MIN, min_index_till_now = 0;

    for(int i = 1; i < n; i++){
        if(stock_prices[i] < stock_prices[min_index_till_now]) min_index_till_now = i;

        int profit = stock_prices[i] - stock_prices[buy_day];
        if(profit > max_profit_till_now) max_profit_till_now = profit;

        if(stock_prices[i] - stock_prices[min_index_till_now] > max_profit_till_now && min_index_till_now!=i){
            buy_day = min_index_till_now;
            max_profit_till_now = stock_prices[i] - stock_prices[buy_day];
        }
    }

    pair<int, int> profit_details = {max_profit_till_now, buy_day+1};

    return profit_details;

}

int main(int argc, char* argv[]){

    int n;
    int stock_prices[n];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>stock_prices[i];

    pair<int, int> max_profit = getMaxProfit(stock_prices, n);
    cout<<max_profit.first<<"\n"<<max_profit.second<<"\n";
}