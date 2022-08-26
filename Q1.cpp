#include <bits/stdc++.h>
using namespace std;

// function to find the length of longest
// subarray having sum k
int lenOfSubarr(int arr[],
                    int n,
                    int k)
{

    
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    
    for (int i = 0; i < n; i++)
    {

        
        sum += arr[i];

        
        if (sum == k)
            maxLen = i + 1;

        
        if (um.find(sum) == um.end())
            um[sum] = i;

        
        if (um.find(sum - k) != um.end())
        {

            
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    return maxLen;
}


int main()
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;
    int res;

    try
    {
        res = lenOfSubarr(arr, n, k);
        if (!res)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "Length = " << res;
    return 0;
}
