#include <iostream>
#include <cstdio>
using namespace std;
const int BASE=500010;
class Hashtable
{
private:
    int key,value;
public:
    Hashtable(int k){key=k;value=1;}
    bool compare(int k){return (key==k);}
    int csgo(){return value;}
    void add(){++value;}
};
int pot(int n)
{
    return (n>=0)?n:-n;
}
int n;
Hashtable* Hash[BASE];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int *A=new int[n],*B=new int[n],*C=new int[n],*D=new int[n];
    int i,j,k,t,res=0;
    for (i=0;i<n;++i)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for (i=0;i<BASE;++i) Hash[i]=NULL;
    for (i=0;i<n;++i) for (j=0;j<n;++j)
    {
        t=pot(A[i]+B[j]);k=0;
        while (Hash[(t+k*k)%BASE]!=NULL && !(Hash[(t+k*k)%BASE]->compare(A[i]+B[j]))) ++k;
        if (Hash[(t+k*k)%BASE]==NULL)
        {
            Hash[(t+k*k)%BASE]=new Hashtable(A[i]+B[j]);
        }
        else
        {
            Hash[(t+k*k)%BASE]->add();
        }
    }
    for (i=0;i<n;++i) for (j=0;j<n;++j)
    {
        t=pot(-C[i]-D[j]);k=0;
        while (Hash[(t+k*k)%BASE]!=NULL && !(Hash[(t+k*k)%BASE]->compare(-C[i]-D[j]))) ++k;
        if (Hash[(t+k*k)%BASE]!=NULL) res+=Hash[(t+k*k)%BASE]->csgo();
    }
    cout<<res;
    return 0;
}
