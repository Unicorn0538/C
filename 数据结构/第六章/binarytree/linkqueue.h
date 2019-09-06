#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED
class ERROR {};

template<class elemtype>
class linkqueue
{
private:
	struct node
	{
		elemtype data;
		node *next;
		node(const elemtype&x, node *ne = NULL)
		{
			data = x;
			next = ne;
		}
		node() :next(NULL) {}
		~node() {}

	};

	node *Front, *Rear;

public:
	linkqueue();
	~linkqueue();
	bool isempty()const;
	void enqueue(const elemtype&x);
	elemtype dequeue();
	elemtype gethead()const;
};

template <class elemtype>
linkqueue<elemtype>::linkqueue()
{
	Front = Rear = NULL;
}

template<class elemtype>
linkqueue<elemtype>::~linkqueue()
{
	node *tmp;
	while (Front)
	{
		tmp = Front;
		Front = Front->next;
		delete tmp;
	}
}

template<class elemtype>
bool linkqueue<elemtype>::isempty()const
{
	return Front == NULL;
}

template <class elemtype>
void linkqueue<elemtype>::enqueue(const elemtype &x)
{
	if (isempty())Rear = Front = new node(x);
	else
	{
		Rear->next = new node(x);
		Rear = Rear->next;
	}
}

template<class elemtype>
elemtype linkqueue<elemtype>::dequeue()
{
	if (isempty())throw ERROR();
	node *tmp = Front;
	elemtype Tmp = Front->data;
	Front = Front->next;
	if (Front == NULL)Rear = NULL;
	delete tmp;
	return Tmp;
}

template <class elemtype>
elemtype linkqueue<elemtype>::gethead()const
{
	if (isempty())throw ERROR();
	return Front->data;
}




#endif // LINKQUEUE_H_INCLUDED
