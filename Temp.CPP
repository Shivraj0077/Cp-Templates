#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define vi vector<int> 
#define vc vector<char> 
#define ll long long
#define nl '\n'
#define all(v) v.begin(), v.end()
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define sumv(v) accumulate(all(v), 0LL)
#define rl(i,start,end) for(ll i=start;i<end;i++)
#define rll(i,start,end) for(ll i=start;i<=end;i++)
#define ry(i,start,end) for(ll i=start;i<end;i++)
#define ryy(i,start,end) for(int i=start;i<=end;i++)
#define yr(i,start,end) for(int i=start;i>=end;i--)

const int INF = numeric_limits<int>::max();
const int NINF = numeric_limits<int>::min();

//ceil for x on d is x+d-1/d
//floor for x on d is x/d 

bool even(int num) { return ((num & 1) == 0); }
bool odd(int num)  { return ((num & 1) == 1); }

ll __gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll LCM(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

bool isSet(int num,int bit){
    return (num & (1<<bit))!=0;
}

int setBit(int num,int bit){
    return num | (1<<bit);
}

int clearbit(int num,int bit){
    return num & ~(1<<bit);
}

int toggle(int num,int bit){
    return num^ (1<<bit);
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
        int t;
        cin>>t;
        while(t--){
        
        }
        return 0;
}
