#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> v;
    long long prod=1;

    for(int i=1;i<N;i++){
     if(__gcd(i,N)==1){
      v.push_back(i);
      prod=(prod*i)%N;
     }
    }

    if(prod==1) cout<<v.size();
    else cout<<v.size()-1;
    
    return 0;
}
