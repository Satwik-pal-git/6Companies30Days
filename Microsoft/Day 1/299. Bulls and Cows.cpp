#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0;
        int i = 0;
        map<int, int> s, g;
        // map<int, int> incorrects, g;
        while (i < secret.size())
        {
            s[secret[i]]++;
            g[guess[i]]++;
            i++;
        }
        int b = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                a++;
                g[secret[i]]--;
            }
        }
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] != guess[i] && g[secret[i]] > 0)
            {
                b++;
                g[secret[i]]--;
            }
        }
        string str = to_string(a) + "A" + to_string(b) + "B";
        return str;
    }
};