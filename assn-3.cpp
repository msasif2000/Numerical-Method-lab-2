#include<bits/stdc++.h>
#define lli long long int
#define dl double
#define pi 2*acos(0.0)
#define Min 10000000
#define Max -10000000
using namespace std;

float value_of_u(float u, int n)
{
    float temp=u;
    for(int i=1; i<n;i++)
    {
        temp=temp*(u+i);
    }
    return temp;
}

int factorial(int n)
{
    int fact=1;
    for(int i=2; i<=n;i++)
    {
        fact*=i;
    }
    return fact;
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

    for(int j=1;j<n;j++)
    {
        for(int i=n-1;i>=j;i--)
        {
            y[i][j]= y[i][j-1] -y[i-1][j-1];
        }
    }
    cout<<endl<<"The difference table is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setprecision(4)<<x[i]<<"\t";
        for(int j=0;j<=i; j++)
        {
           cout<<setprecision(4)<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    float X;
    cout<<"Enter the value of X: ";
    cin>>X;

    float sum = y[n-1][0];
    float u=(X-x[n-1])/(x[1]-x[0]);

    for(int i=1;i<n;i++)
    {
        sum = sum+(value_of_u(u,i) * y[n-1][i])/factorial(i);
    }

    cout<<endl<<"Value for " <<X<< " = "<<sum<<endl;
return 0;
}
