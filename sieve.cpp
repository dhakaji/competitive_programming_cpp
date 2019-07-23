#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// #define NP 15485900
#define NP 13300000
#define pb push_back
bool isPrime[NP] ;
vector<int> prime(NP) ; // Contains all primes upto n
vector<int> lpf(NP) ; // lpf(least prime factor) Contains least prime factor of all primes

void sieve(){
    int i,j,n = NP ;
    isPrime[2] = true ;
    for(i = 3 ;i<n;i+=2){
        isPrime[i] = true ;
        lpf[i-1] = 2 ;
        lpf[i] = i ;
    }
    lpf[1] = 1 ; 
    for(i = 3 ; i*i <= n ;i+=2){
        if(isPrime[i]){
            for(j=i*i;j<n;j+=i){
                isPrime[j] = false ;
                if(lpf[j] == j) lpf[j] = i ;
            }
        }
    }
    prime[0] = 2 ; // Contains all primes upto n 
    int cnt = 1 ; // Total number of primes upto n 
    for(i=3;i<n;i+=2){
        if(isPrime[i])  prime[cnt++] = i ;
    }
    prime.resize(cnt) ;
    // return cnt ; // if want to know total number of primes
}


int main() {
	cout << prime.size() << endl;
	sieve() ;
	cout << prime.size() ;
	return 0;
}
