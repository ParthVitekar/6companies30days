/*A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are an FBI agent. You have to determine the total number of ways that message can be decoded,
as the answer can be large return the answer modulo 10^9 + 7.
Note: An empty digit sequence is considered to have one decoding.
It may be assumed that the input contains valid digits from 0 to 9 and
If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.*/

#include <bits/stdc++.h>

using namespace std;

int CountWays(string str)
{
    int n = str.length();

    int count = 0;
    int dp[n + 1];

    dp[0] = 1;

    if (str[0] == '0')
        return 0;
    if (n == 1)
        return 1;

    for (int i = 1; i < n; i++)
    {

        if (str[i - 1] == '0' and str[i] == '0')
        {
            dp[i] = 0;
        }
        else if (str[i - 1] == '0' and str[i] != '0')
        {
            dp[i] = dp[i - 1];
        }
        else if (str[i - 1] != '0' and str[i] == '0')
        {
            if (str[i - 1] == '1' or str[i - 1] == '2')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else
                dp[i] = 0;
        }
        else
        {

            if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] < '7'))
            {
                dp[i] = (dp[i - 1] + (i >= 2 ? dp[i - 2] : 1)) % 1000000007;
            }
            else
                dp[i] = dp[i - 1];
        }
    }

    return dp[n - 1];
}

int main(){
    string input;
    cin>>input;

    int res = CountWays(input);

    cout<<res<<endl;

    return 0;
}
