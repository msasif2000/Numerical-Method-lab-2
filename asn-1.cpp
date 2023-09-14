#include<bits/stdc++.h>
#define lli long long int
#define dl double
#define pi 2*acos(0.0)
#define Min 10000000
#define Max -10000000
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n];
    int y[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>y[i];
    int diffTable[n][n];
    for(int i=0;i<n;i++)
        diffTable[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            diffTable[i][j]= diffTable[i+1][j-1] - diffTable[i][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
        for(int j=0;j<n-i; j++)
        {
           cout<< diffTable[i][j]<<"\t";
        }
        cout<<endl;
    }
return 0;
}
