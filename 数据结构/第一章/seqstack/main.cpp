#include <iostream>
#include <cstring>
#include "seqstack.h"
using namespace std;



/*bool precedence(const char &a,const char &b)//优先级比较
{
    if(a=='*'||a=='/'||b=='(')return 1;
     else if(b=='*'||b=='/')return 0;
     else return 1;
}

char *getdata(char *str)//将一个计算过程转换为波兰式
{
    seqstack <char> w;
    char *data;
    data=new char[strlen(str)+1];

    char x;
    x='#';
    w.push(x);

    while(*str)
    {
        if(*str>='0'&&*str<='9')
        {
            *data=*str;
            data++;
        }
        else
        {
            switch(*str)
            {
                case '(': x='(';w.push(x);break;

                case ')': while(w.top()==')')
                          {
                              *data=w.top();
                              w.pop();
                              data++;
                          }
                          w.pop();
                          break;

                default : while (!precedence(*str,w.top()))
                              {
                                  *data=w.top();
                                  w.pop();
                                  data++;
                              }
                              x=*str;
                              w.push(x);
                              break;
            }
        }
        str++;
    }

    while(!w.isempty())
    {
        *data=w.top();
        w.pop();
        data++;
    }
    *data='\0';

    return data;
}

int calculate(char*str)//利用波兰式后缀计算
{
    seqstack <int> s;
    int x=0;
    int op1=0,op2=0;
    while(*str)
    {
        if(*str>='0'&&*str<='9')
        {
            x=*str-'0';
            s.push(x);
        }
        else
        {
            op1=s.top()-'0';s.pop();
            op2=s.top()-'0';s.pop();
            switch(*str)
            {
                case '*':x=op2*op1;break;
                case '/':x=op2/op1;break;
                case '+':x=op2+op1;break;
                case '-':x=op2-op1;break;
                default :return 0;
            }
            s.push(x);
        }
        str++;
    }
    return x;
}

int main()
{
    char ch[80];
    char *newch;
    newch=new char[81];
    cin.getline(ch,80);
    newch=getdata(ch);
    int x=calculate(newch);
    cout<<endl<<x;
    return 0;

}
*/
struct person
{
    int per;
    int dir;
    person(int p=0,int d=0):per(p),dir(d){}
};
int main()
{
    seqstack<person >s;
    person *data;
    data=new person[500000];
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>data[i].per>>data[i].dir;
    }
    person d;
    s.push(data[0]);
    s.push(data[1]);
    for(int i=1;i<N;i++)
    {   d=s.pop();
        person f;
        f=s.top();
        while(!(f.dir==d.dir||(f.dir==0&&d.dir==1)))

        {if(data[i].dir==d.dir||(data[i].dir==1&&d.dir==0))
        {
           s.push(d); s.push(data[i]);
        }
            else if(data[i].per>d.per)
                s.push(data[i]);
                else s.push(d);
            d=s.pop();
        }
    }
    int a=0;
    person h;
    while(!s.isempty())
    {
        h=s.pop();
        a++;
    }
    cout<<a;
    return 0;
}
