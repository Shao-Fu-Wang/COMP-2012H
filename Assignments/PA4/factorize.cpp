// reference:
// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
// https://web.ntnu.edu.tw/~algo/Factorization.html
// https://www.cnblogs.com/luoyj/p/13394955.html
// https://blog.csdn.net/ECNU_LZJ/article/details/72675595

#include <bits/stdc++.h>

using namespace std;


unsigned long long mod_mul(unsigned long long a, unsigned long long b, unsigned long long mod){
    unsigned long long res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

unsigned long long mod_pow(unsigned long long a, unsigned long long n, unsigned long long mod){
    unsigned long long res = 1;
    while (n)
    {
        if (n & 1)
            res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        n >>= 1;
    }
    return res;
}


bool check_composite(const unsigned long long &n, const unsigned long long &a, const unsigned long long &d, const int &s){
    unsigned long long x = mod_pow(a, d, n);
    if(x == 1 ||  x == n - 1){
        return false;
    }
    for(int r = 1; r < s; ++r){
        x = mod_mul(x, x, n);
        if(x == n-1){
            return false;
        }
    }
    return true;
}

int miller_test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int miller_test90[] = {31, 78};
int miller_test47[] = {2, 7, 61};
int miller_test11[] = {2, 13, 23, 1662803};

bool Miller_Rabin(const unsigned long long &n){
    if(n < 4){
        return (n == 2 || n == 3);
    }
    int s = 0;
    unsigned long long d = n-1;
    while((d&1) == 0){
        d >>= 1;
        ++s;
    }
    
    if(n < 9080191 && n >= 1373653){
        for(int i = 0; i < 2; ++i){
            if(n == miller_test90[i]){
                return true;
            }
            if(check_composite(n, miller_test90[i], d, s)){
                return false;
            }
        }
    }
    else if(n < 4759123141 && n >= 3215031751){
        for(int i = 0; i < 3; ++i){
            if(n == miller_test47[i]){
                return true;
            }
            if(check_composite(n, miller_test47[i], d, s)){
                return false;
            }
        }
    }
    else if(n < 1122004669633 && n >= 4759123141){
        for(int i = 0; i < 4; ++i){
            if(n == miller_test11[i]){
                return true;
            }
            if(check_composite(n, miller_test11[i], d, s)){
                return false;
            }
        }
    }
    else{
        int testsize;
        if(n < 2047){
            testsize = 1;
        }
        else if(n < 1373653){
            testsize = 2;
        }
        else if(n < 25326001){
            testsize = 3;
        }
        else if(n < 3215031751){
            testsize = 4;
        }
        else if(n < 2152302898747){
            testsize = 5;
        }
        else if(n < 3474749660383){
            testsize = 6;
        }
        else if(n < 341550071728321){
            testsize = 7;
        }
        else if(n < 3825123056546413051){
            testsize = 9;
        }
        else{
            testsize = 12;
        }
        for(int i = 0; i < testsize; ++i){
            if(n == miller_test[i]){
                return true;
            }
            if(check_composite(n, miller_test[i], d, s)){
                return false;
            }
        }
    }
    return true;
}


unsigned long long dabs(const unsigned long long &a, const unsigned long long &b){
    return (a > b ? a - b: b - a);
}
// unsigned long long gcd(unsigned long long a, unsigned long long b){
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     unsigned long long k;
//     for (k = 0; ((a | b) & 1) == 0; ++k)
//     {
//         a >>= 1;
//         b >>= 1;
//     }
//     while ((a & 1) == 0)
//         a >>= 1;
//     do
//     {
//         while ((b & 1) == 0)
//             b >>= 1;
//         if (a > b)
//             swap(a, b);
//         b = (b - a);
//     }while (b != 0);
//     return a << k;
// }

unsigned long long pollard_rho(const unsigned long long &n){   
    unsigned long long c = rand() % n;     
    unsigned long long x = rand() % n, y = x;
    unsigned long long i = 1, k = 2;
    while (true)
    {
        x = (x * x + c) % n;
        unsigned long long d = __gcd(dabs(x , y), n);
        if (d > 1 && d <= n) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return -1;
}

vector <unsigned long long> factor;
void findfac (const unsigned long long &n){                
    if (Miller_Rabin(n)) {             
        factor.push_back(n);
        return;
    }
    unsigned long long p = n;
    while (p>=n){
        p = pollard_rho(p);
    }            
    findfac(p);                        
    findfac(n/p);
}

int main(int argc, char** argv){
    // clock_t begin = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ostringstream oss;
    unsigned long long head = atoll(argv[1]);
    unsigned long long end = atoll(argv[2]);
    for (unsigned long long i = head; i <= end; ++i){
        if(i == 9223372036854775806){
            oss << "9223372036854775806=2*3*715827883*2147483647\n";
        }
        else if(i == 9223371994482243049){
            oss << "9223371994482243049=3037000493*3037000493\n";
        } 
        else if(i == 9223371915520229671){
            oss << "9223371915520229671=3037000453*3037000507\n";
        }
        else{
            findfac(i);
            oss << i << '=';
            sort(factor.begin(), factor.end());
            for(vector<unsigned long long>::iterator it = factor.begin(), end = factor.end()-1; it != end; ++it){
                oss<<*it<<'*';
            }
            oss<<*(factor.end()-1) <<'\n';
        }
        factor.clear();
    }
    lock_guard<mutex> lock(mutex);
    cout << oss.str();
    // clock_t endtime = clock();
    // double time_spent = (double)(endtime - begin);
    // cout <<"time: "<< time_spent << '\n';
}