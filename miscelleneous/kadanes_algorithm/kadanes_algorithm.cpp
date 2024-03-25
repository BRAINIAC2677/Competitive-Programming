#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &arr)
{
    int n = arr.size();
    long long local_max = 0, global_max = INT_MIN;
    for(int i = 0; i< n; i++)
    {
        local_max = max(1LL*arr[i], arr[i] + local_max);
        global_max = max(local_max, global_max);
    }
    return global_max;
}

int main()
{

}