/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maxSum(std::vector<int> & vec, int k)
{
    
    int maxSoFar = INT_MIN, runningMax= 0;
    for(int i =0; i < vec.size(); i++)
    {
        runningMax += vec[i]; // adding for every iteration
        if(i >= k -1)         //condition to update maxSoFar only after k indexs        
        {
            maxSoFar = std::max(maxSoFar,runningMax);
            runningMax -= vec[i - (k -1)];   // subtracting after k index for every iteration
        }
    }
    return maxSoFar;
}

int main()
{
    cout<<"Hello World";
    std::vector<int> vec {4,2,1,7,8,1,2,8,1,0} ;
    int k = 3;
    cout << maxSum(vec, k) << endl;

    return 0;
}
