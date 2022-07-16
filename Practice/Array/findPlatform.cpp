//Minimum Number of Platforms Required for a Railway/Bus Station

#include <iostream>
#include <algorithm>

using namespace std;

int findPlatform(int arv[], int dep[], int n)
{
    sort(arv, arv+5);
    sort(dep, dep+5);
    
    int i = 1, j = 0;
    int platformNeeded = 1, result = 1;
    
    while(i < n && j < n){
        if(arv[i] <= dep[j]) {
            platformNeeded++;
            i++;
        }
        else if(arv[i] > dep[j])
        {
            platformNeeded--;
            j++;
        }
        if(platformNeeded > result)
            result = platformNeeded;
    }
    return result;
}

int main()
{
    cout<<"Hello World ";

    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findPlatform(arr, dep, 6);
    return 0;
}
