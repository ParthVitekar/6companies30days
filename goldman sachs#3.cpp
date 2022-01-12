/*Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.*/

 #include <bits/stdc++.h>

using namespace std;

int countSubArray(vector<int>& a, int n, int k) {
         int i=0,j=0,ans=0;
        long long prod = 1;
        while(j < n){
            prod *= a[j];
            if(prod >= k){
                while(i <= j and prod >= k){
                    prod /= a[i];
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }

int main(){
    int n,i;
    cin>>n;
    int k;
    cin>>k;

    vector<int>arr(n);
    for(i=0 ; i<n ; i++)
        cin>>arr[i];

    int result = countSubArray(arr , n , k);

    cout<<result<<endl;

    return 0;
}
