/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<string>

using namespace std;

int minCost(string str, std::vector<int> & cost)
{
    cout << str << endl;
    int minCost=0, sum=0, max=0;
    for(int i=0; i < str.length(); i++)
    {
      if(i > 0 && str.at(i) != str.at(i-1))
      {
          minCost += sum -max;
          max = 0;
          sum = 0;
      }
      sum+= cost[i];
      max = std::max(max, cost[i]);

      cout << minCost << "---" << sum << "---" << max << "---" << str[i] << "---" << str[i+1] << endl;
    }
    minCost += sum-max;
    return minCost;
}


int main()
{
    cout<<"Hello World";
    string str = "aaabbbabbbb";
    std::vector<int> cost {3,5,10,7,5,3,5,5,4,8,1} ;
    cout << minCost(str, cost ) << endl;
    return 0;
}
