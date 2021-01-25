#include<bits/stdc++.h>
using namespace std;
#define fr(iii,frm,fornn)for(int iii=frm; iii<=fornn; iii++)
#define rfr(iii,frm,fornn)for(int iii=frm; iii>=fornn; iii--)
#define E "\n"

typedef vector <float> ve;
typedef vector <bool> vb;

void solve()
{
    int n;
    cin>>n;
    ve weight(n);
    fr(i,0,n-1)cin>>weight[i];

    sort(weight.begin(), weight.end());

    int ans = 0;
    while(weight.size())
    {
        ans++;
        double cur = 3.00;
        rfr(i, weight.size()-1, 0)
        {
            if(weight[i] <= cur)
            {
                cur -= weight[i] ;
                weight.erase(weight.begin()+i);
            }
        }
    }
	cout<<ans<<E;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc,cse=0;
    //cin>>tc;
    //while(tc--)
        solve();
}



