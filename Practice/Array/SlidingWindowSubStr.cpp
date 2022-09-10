//Sliding Window Problem
//Problem to find min sub string

#include <iostream>
#include<string>
#include<climits>
#include<unordered_map>

using namespace std;

string minString(string s, string t)
{
    if(t.length() > s.length()) return "";
    cout << s << " " << t << endl;
    
    //first store target string frequency in a map.
    unordered_map <char, int> map;
    for(int i = 0; i  < t.length(); i++)
    {
        ++map[t[i]];
    }
    cout << s << " 1 " << t << endl;
    int left=0, right=0, head=INT_MIN, len=INT_MAX, count=map.size();
    //second we match the string
    while(right < s.length()){
        
        char rightChar = s[right];
        //find the main string char with the target string map we created at step 1 & decrement frequescy by 1 of matching char
        // also reduce the map size by one if frequecy of the current char equas to 0
        if(map.find(rightChar) != map.end())
        {
            if(--map[rightChar]==0) count--;
        }
        right++;  // increment the main string index by 1
        cout << s << " 2 " <<  t << "count " << count << endl;
        // if we have already get all char , it means count is 0
        while(count==0)
        {
             cout << s << " 3 " << t << endl;
            if(right-left < len){    // this check pass only we have a new min substring
                head = left;         // to keep the head of the min sub string 
                len = right-left;    //to track the min sub string length 
            }
             cout << s << " 4 " << t << endl;
            char leftChar = s[left];
            if(map.find(leftChar) != map.end())
            {
                if(++map[leftChar] > 0) count++;
            }
            left++;
            cout << s << " 5 " << t << endl;
        }
    }    
        if(len == INT_MAX) return "";
        cout << s.substr(head, len) << endl;
        return s.substr(head, len);   
}

int main()
{
    cout<<"Hello World";
    string source = "ADOBECODEBANC";
    string target = "ABC";
    cout << minString(source, target) << endl;

    return 0;
}
