#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class outofbound {};

struct node
{
	int num;
	int influ;
	char name[31];
};

class seqstack
{
private:
	int Top;
	node *elem;
	int maxsize;

	void doublespace();

public:
	seqstack(int inisize = 10);
	~seqstack() { delete elem; }
	int top()const;
	int tp()const;
	void push(const node&x);
	void pop();
	bool isempty()const;
};


seqstack::seqstack(int inisize)
{
	maxsize = inisize;
	elem = new node[inisize];
	Top = -1;
}

void seqstack::doublespace()
{
	node *tmp = elem;

	elem = new node[maxsize * 2];

	for (int i = 0; i < maxsize; i++)
	{
		elem[i] = tmp[i];
	}
	delete tmp;
}

void seqstack::push(const node &x)
{
	if (Top == maxsize)doublespace();
	elem[++Top] = x;
}

void seqstack::pop()
{
	if (isempty())throw outofbound();
	Top--;
}

int seqstack::top()const
{
	if (isempty())throw outofbound();
	return elem[Top].influ;
}

int seqstack::tp()const
{
	return elem[Top].influ;
}

bool seqstack::isempty()const
{
	return Top == -1;
}

int main()
{
	seqstack s;
	int N;
	node x;
	char result[500][32];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x.influ;
		cin.get();
		cin.getline(x.name, 30);
		x.num = i;

		if (s.isempty())
		{
			s.push(x);
		}
		else
		{
			while (!s.isempty() && x.influ > s.top())
			{
				strcpy(result[s.tp()], x.name);
				s.pop();
			}
			s.push(x);
		}
	}

	int j = -1;
	for (int i = 0; i < N; i++)
	{
		if (result[i][0] !='\0')puts(result[i]);
		else cout<<j;
		cout << endl;
	}
	return 0;
}
