#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


void heapify(vector<int> & input, int n, int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;
    if(left < n && input[left] > input[largest])
        largest = left;
    if(right < n && input[right] > input[largest])
        largest = right;
        
    if(i != largest)
    {
        std::swap(input[i], input[largest]);
        heapify(input, n, largest);
    }
}

void heapSort(vector<int> & input, int k)

{
    int size = input.size();
    for(int i = size/2 -1; i >=0; i--)
    {
        heapify(input, size, i);
    }
    for(int i = size-1; i >0; i--)
    {
        //to print the smallest/largest k elements, this one will print largest elements
        if(k)
        {
            cout << input[0] << " ";
            k--;
        }
        
        std::swap(input[0], input[i]);
        
        heapify(input, i, 0);
    }
    
}

int main()
{
    int k = 3;
    vector<int> input {9,5,1,23,5};
   
    
    heapSort(input,k);
    cout << endl;    
    for(int i = 0; i < 5; i++)
        cout << input[i] << " " ;
    
	return 0;
}
