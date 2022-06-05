/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxProfitWith2MostTrx(vector<int> & arr)
{
    int n = arr.size();
    int ma = arr[n-1];
    int mi = arr[0];
    
    vector<int> dp (n ,0);
    
    for(int i = n -2; i >=0; i--)
    {
        if(arr[i] > ma)  ma = arr[i];
        dp[i] = max(dp[i+1], ma-arr[i]);
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < mi) mi = arr[i];
        dp[i] = max(dp[i-1], dp[i] + (arr[i]-mi));
    }
    return dp[n-1];
}

int main()
{
    cout<<"Hello World";
    vector<int> arr {10, 22, 5 ,75, 65, 80};
                    
    cout << findMaxProfitWith2MostTrx(arr) << endl;

    return 0;
}
