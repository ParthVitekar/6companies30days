/*Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int result = INT_MAX;

    int left = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];

        while (sum >= target)
        {
            result = min(result, (i + 1 - left));

            sum -= nums[left];

            left++;
        }
    }

    if (result == INT_MAX)
        return 0;

    return result;
}

int main()
{
    cout << "array size : ";
    int n;
    cin >> n;

    cout << "array :";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Target : ";
    cin >> target;

    int res = minSubArrayLen(target, nums);

    cout << res << endl;

    return 0;
}
