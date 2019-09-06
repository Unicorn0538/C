#include<iostream>

 using namespace std;
 int main()
 {
     int n;
     int a[1001][1001];
     int b[1001][1001];
     cin>>n;
     for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                cin>>a[i][j];
               b[i][j]=a[i][j];
            }
        }
     for(int i=n-1; i>=1; i--)
    {
        for(int j=n-1; j>=1; j--)
            {
                b[i][j] += max(b[i+1][j],b[i+1][j+1]);
            }
    }
    int k=1,j=0;
    for(int i=1; i<=n; i++)
        {
            j=j+a[i][k];
           if(a[i][k]+b[i+1][k]<a[i][k]+b[i+1][k+1])
            {	k=k+1;	}
        }
        cout<<j;
     return 0;
}

