#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    
    int N;
    cin>>N;
    int paper[N+1]={0};
    char ch[6];
    int tmp1,tmp2,maxi=0,maxdata=0;
    while(true)
    {
       scanf("%s",ch);
       if(ch[0]=='a')
       {
           scanf("%d",&tmp1);
           scanf("%d",&tmp2);
           paper[tmp2]++;
           if(paper[tmp2]>maxdata||(paper[tmp2]==maxdata&&tmp2<maxi)){maxdata=paper[tmp2];maxi=tmp2;}
       }
       else if(ch[0]=='q')
       {
         printf("%d %d \n",maxi,maxdata);
        
       }
       else break;
    }
    return 0;

}