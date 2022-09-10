#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> findPair(vector<int> & input, int target)
{
    unordered_map<int, int> result;
    unordered_map<int, int> hash_map;
    for(int i = 0; i < input.size(); i++)
    {
        int complement = target - input[i];
        auto itr = hash_map.find(complement);
        if(itr != hash_map.end())
        {
            //cout  << itr->second << " " << i << endl;
            //cout  << itr->first << " " << input[i] << endl;
            result.insert({itr->second, i});
            break;
        }
        else
        {
            hash_map.insert({input[i], i});
        }
    }
    return result;
}

int main()
{
    int target = 10;
    vector<int> input {9,5,1,23,5};
    
    auto result = findPair(input, target);
	for(auto itr : result)
	{
	    cout  << itr.first << " " << itr.second << endl;
	}
	
	return 0;
}
