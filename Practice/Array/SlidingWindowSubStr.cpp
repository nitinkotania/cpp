#include <iostream>
#include<string>
#include<climits>
#include<unordered_map>

using namespace std;

string minString(string s, string t)
{
    if(t.length() > s.length()) return "";
    cout << s << " " << t << endl;
    unordered_map <char, int> map;
    for(int i = 0; i  < t.length(); i++)
    {
        ++map[t[i]];
    }
    cout << s << " 1 " << t << endl;
    int left=0, right=0, head=INT_MIN, len=INT_MAX, count=map.size();
    
    while(right < s.length()){
        
        char rightChar = s[right];
        if(map.find(rightChar) != map.end())
        {
            if(--map[rightChar]==0) count--;
        }
        right++;
        cout << s << " 2 " <<  t << "count " << count << endl;
        while(count==0)
        {
             cout << s << " 3 " << t << endl;
            if(right-left < len){
                head = left;
                len = right-left;
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
