//
// Created by hans on 2024/1/18.
//

#include "fib.hpp"
#include <iostream>

using namespace std;

int fib_dp(int n){

    if(n==1 || n ==2){
        return n;
    }
    int dp_i_1 = 1, dp_i_2=0;

    for(int i=2; i <= n; i++){
        // dp[i] = dp[i-1] + dp[i-2]
        int dpi = dp_i_1 + dp_i_2;
        dp_i_2 = dp_i_1;
        dp_i_1 = i;
    }
    return dp_i_1;
}

int main(){

    int sol = fib_dp(20);

    cout<<  << endl;
}