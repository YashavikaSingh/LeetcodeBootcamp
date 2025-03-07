#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


#define largepos 2147483647;
#define largeneg -2147483648;
class Solution {
public:

    string removedwhitespace(string s)
    {
        while(s[0]==' ')
        {
            s = s.substr(1, s.length()-1);
        }    
        return s;
    }


    bool sign(string &s)
    {
        if(s[0]=='-')
        {
            s = s.substr(1, s.length()-1);
            return true;
        }
        else if(s[0]=='+')
        {
            s = s.substr(1, s.length()-1);
        }
        

        return false;
    }


    vector<int> extractdigs(string s)
    {   
        vector<int> ans;
        int i = 0;
        while(isdigit(s[i]))
        {
            ans.push_back(s[i]-'0');
            i++;
        }
        return ans;
    }


    int myAtoi(string s) {
        string w = removedwhitespace(s);
        bool negative = sign(w);
        vector<int> digits;
        digits = extractdigs(w);

        while (!digits.empty() && digits[0] == 0) 
        digits.erase(digits.begin());


        long long p = digits.size();
        if(p>10 and !negative)
        return largepos;

        if(p>10 and negative)
        return largeneg;


        long long ans = 0;
        p = p-1;

        for(int i = 0;  i<digits.size(); i++)
        {
            
            if(ans>2147483647)
            break;

            if(p>10)
            break;

            long long t= pow(10, p);
            ans+=digits[i]*t;
            p--;
        }

        if(negative and ans>2147483647)
        return -2147483648;

        if(ans>2147483647)
        return 2147483647;

        if(negative)
        {
            ans = 0 - ans;
        }

        return ans;

    }
};