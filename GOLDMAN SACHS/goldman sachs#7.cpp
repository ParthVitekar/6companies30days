/*M items are to be delivered in a circle of size N.
Find the position where the M-th item will be delivered if we start from a given position K.
Note that items are distributed at adjacent positions starting from K.*/

#include <bits/stdc++.h>

using namespace std;

int findPosition(int N , int M , int K) {
        // code here
        if((M+K-1) <= N)
            return M+K-1;
        if((M+K-1)%N ==0)
        return N;
        else
        return (M+K-1)%N;
    }

int main(){
int N,M,K;
cin>> N >> M >>K;

int res = findPosition(N ,M ,K);

cout<<res<<endl;

}
