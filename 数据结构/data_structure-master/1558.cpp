/*#include <iostream>
#define mx 100001
using namespace std;

int cattle[mx],loc[mx],kind[mx];
int new_cattle[mx],state[mx];
int N,K,ans=0;
int divide(int a[],int low,int high){
    int k=a[low];
    do{
        while(low<high&&k<=a[high])--high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&k>=a[low]) ++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
void quickSort(int a[],int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
int main(){
    int i;
    cin>>N>>K;
    for(i=1;i<=N;++i){
        cin>>cattle[i];
        loc[i]=i;
    }
    quickSort(cattle,1,N);
    quickSort(loc,1,N);
    kind[1]=1;
    for(i=2;i<=N;++i){
        if(cattle[i]==cattle[i-1]) kind[i]=kind[i-1];
        else kind[i]=kind[i-1]+1;
    }
    for(i=1;i<=N;++i)new_cattle[loc[i]]=kind[i];
    int num=1;
    int first=1;
    state[1]=1;
    for(i=2;i<=N;++i){
        if(num==K+1&&state[new_cattle[i]]==0){
            while(state[new_cattle[first]]!=1){
                --state[new_cattle[first]];
                ++first;
            }
            --state[new_cattle[first]];
            ++first;
            ++state[new_cattle[i]];
            if(state[new_cattle[i]]>ans)ans=state[new_cattle[i]];
        }
        else{
            if(state[new_cattle[i]]==0)++num;
            ++state[new_cattle[i]];
            if(state[new_cattle[i]]>ans)ans=state[new_cattle[i]];
        }
    }
    cout<<ans;
    return 0;
}*/
#include <iostream>
#define mx 100001
using namespace std;

int cattle[mx],loc[mx],kind[mx];
int new_cattle[mx],state[mx];

int N,K,ans=0;
int divide(int a[],int low,int high){
    int k=a[low];
    do{
        while(low<high&&k<=a[high])--high;
        if(low<high){a[low]=a[high];++low;}
        while(low<high&&k>=a[low]) ++low;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
void quickSort(int a[],int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

int main(){
    int i;
    cin>>N>>K;
    for(i=1;i<=N;++i){
        cin>>cattle[i];
        loc[i]=i;
    }
    quickSort(cattle,1,N);
    quickSort(loc,1,N);
    kind[1]=1;
    for(i=2;i<=N;++i){
        if(cattle[i]==cattle[i-1]) kind[i]=kind[i-1];
        else kind[i]=kind[i-1]+1;
    }
    for(i=1;i<=N;++i)new_cattle[loc[i]]=kind[i];
    state[new_cattle[1]]++;
    int num=1;
    int head=1;
    for(int i=2;i<=N;++i)
    {
        if(num==K+1&&state[new_cattle[i]]==0)//��ǩ��������Ҫɾ��
        {
            while(state[new_cattle[head]]!=1)
            {
                state[new_cattle[head]]--;//������������ɫ��ָ��ָ��������������һ�����Ԫ�ؿ�ǰ��Ԫ�أ�ʹ����������ֻʣ��һ��Ԫ��
                head++;
            }
            state[new_cattle[head]]--;
            head++;
            state[new_cattle[i]]++;
            if(state[new_cattle[i]]>ans) ans=state[new_cattle[i]];
        }
        else//��ǩδ�����������
        {
            if(state[new_cattle[i]]==0) num++;
            state[new_cattle[i]]++;
            if(state[new_cattle[i]]>ans) ans=state[new_cattle[i]];
        }
    }
    cout << ans;
}

