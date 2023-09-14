#include<bits/stdc++.h>
#define lli long long int
#define dl double
#define pi 2*acos(0.0)
#define Min 10000000
#define Max -10000000
using namespace std;

float proTerm(int i, float X, float x[])
{
    float pro=1;
    for(int j=0; j<i; j++)
    {
        pro = pro*(X-x[j]);
    }
    return pro;
}
int main()
{
    int n;
    cout<<"Enter the no of value of x = ";
    cin>>n;
    float x[n];
    float y[n][n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>y[i][0];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i; j++)
        {
           y[j][i]=(y[j][i-1]- y[j+1][i-1]) / (x[j]-x[i+j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<setprecision(4)<<x[i]<<"\t";
        for(int j=0;j<n-i;j++)
        {
            cout<<setprecision(4)<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    float X;
    cout<<"Enter the value of X: ";
    cin>>X;

    float sum = y[0][0];

    for(int i=1;i<n;i++)
    {
        sum = sum+(proTerm(i, X, x)*y[0][i]);
    }


    cout<<endl<<"Value at " <<X<< " = "<<sum<<endl;

return 0;
}

