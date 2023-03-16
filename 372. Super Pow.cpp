#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int binExpo(int a,int b,int m)
{
    a %= m;
    int ans =1;
    while(b>0)
    {
        if(b&1) ans = (ans*1LL*a)%m;

        a = (a*1LL*a)%m;
        b>>=1;
    }

    return ans;
}
int superPow(int a, vector<int>& b) {
        // etf(1337) = 1337 * (1- 1/7) * (1 - 1/191) = 1140

        int num =0;
        for(auto u:b)
        {
            num = (num*10 + u) % 1140;
        }

        int ans = binExpo(a,num, 1337);

        return ans;
    }


int main()
{
    optimize();
    
    int a;
    vector<int>b(6);
    cin>>a;
    for(int i=0;i<6;i++) cin>>b[i];

    int ans = superPow(a,b);

    cout<<ans<<endl;
    

    return 0;
}
