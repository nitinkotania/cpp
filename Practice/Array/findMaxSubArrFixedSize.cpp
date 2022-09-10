//Program to find Max Sub Array for Fixed Size sub array.

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
