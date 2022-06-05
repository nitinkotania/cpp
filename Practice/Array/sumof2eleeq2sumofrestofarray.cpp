// C++ program to find whether two elements exist
// whose sum is equal to sum of rest of the elements.

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkPair(std::vector <int> vec)
{
	// Find sum of whole array
	int sum = 0;
    for(auto item: vec)
		sum += item;

	// If sum of array is not even than we can not
	// divide it into two part
	if (sum%2 != 0)
		return false;

	sum = sum/2;

	// For each element arr[i], see if there is
	// another element with value sum - arr[i]
	for(auto itr = vec.begin(); itr != vec.end(); itr++)
 	{
		int val = sum - *itr;
		// If element exist than return the pair
		auto itr1 = std::find(itr+1, vec.end(), val);
        if(itr1 != vec.end())
		{
			printf("Pair elements are %d and %d\n",
								*itr1	, *itr);
			return true;
		}
 	}

	return false;
}

// Driver program.
int main()
{
	std::vector <int> vec {2,11,5,1,7,4};
	if (checkPair(vec) == false)
	printf("No pair found");
	return 0;
}

