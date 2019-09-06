#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

class ERROR{};

template<class elemtype>
class linkqueue
{
private:
    struct node
    {
        elemtype data;
        node *next;
        node(const elemtype&x,node *ne=NULL)
        {
            data=x;
            next=ne;
        }
        node():next(NULL){}
        ~node(){}

    };

    node *Front,*Rear;

public:
    linkqueue()
    {
        Front=Rear=NULL;
    }

    ~linkqueue()
    {
        node *tmp;
        while(Front)
        {
          tmp=Front;
          Front=Front->next;
          delete tmp;
         }
    }

    bool isempty()const
    {
        return Front==NULL;
    }

    void enqueue(const elemtype&x)
    {
        if(isempty())Rear=Front=new node(x);
        else
        {
           Rear->next=new node(x);
           Rear=Rear->next;
        }
    }

    elemtype dequeue()
    {
       if(isempty())return 0;
       node *tmp=Front;
       elemtype Tmp=Front->data;
       Front=Front->next;
       if(Front==NULL)Rear=NULL;
       delete tmp;
       return Tmp;
    }

    elemtype gethead()const
    {
        if(isempty())return 0;
        return Front->data;
    }
};

#endif // LINKQUEUE_H_INCLUDED
