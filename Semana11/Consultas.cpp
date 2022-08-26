#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//#define int long long
#define pb push_back
#define F first
#define S second

const ll inf = 1LL<<62;
const ll md = 1000000007;

pair<ll,ll> seg[1000005];
ll mark[1000005];

void push(ll k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}

void update(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    ll h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].F += h*v;
    ll d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}

ll assign(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1; 
        return seg[k].F;
    }
    push(k); 
    ll d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;

}

ll sum(ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    push(k); 
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    ll d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}

int main(){
	ll n,q; cin>>n>>q;
    ll nn =n;
    n = 1<<(ll)ceil(log2(n));
    for (ll i = 0; i< nn; i++) {
        ll x; cin>>x;
        update(x,i,i,1,0,n-1);
    }
    while (q--) {
        ll z;
        cin>>z;
        if (z == 1) {
            ll a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            update(x,a,b,1,0,n-1);
        }
        else if (z == 2) {
            ll a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            assign(x,a,b,1,0,n-1);
        }
        else {
            ll a,b;
            cin>>a>>b; a--, b--;
            cout<<sum(a,b,1,0,n-1)<<'\n';
        }
    }
}