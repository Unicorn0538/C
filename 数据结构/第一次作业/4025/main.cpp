#include <iostream>

using namespace std;

class sLink
	{
		private:
			struct node{
				int year;
				char *name;
				node *next;

				node(const int y, char *n,node *p = NULL) { year = y ; name = n; next = p;}
				node():next(NULL){}
				~node(){}
			};

			node *head;
			int currentLength;

			node *move(int i) const
			{
	            node *p = head;
	            while(i > 0){ p = p->next;i--;}
	            return p;
	        }

		public:
			sLink();
			~sLink(){clear();delete head;}

			void clear();
			void insert(int y,char *n);
			void remove(int i);
			void list(int i);

	};

sLink::sLink()
{
	head = new node;
	currentLength = 0;
}

void sLink::clear()
{
	node *p = head->next,*q;
	head->next = NULL;
	while(p != NULL){
		q = p->next;
		delete p;
		p = q;
	}
	currentLength = 0;

}

void sLink::insert(int y,char *n)
{
	node *p = head->next,*pos;
	int i = 0;
	//if(currentLength == 0) head->next = new node(y,n);
	while(p != NULL && p->year < y) { p = p->next; ++i;}

	if(p != NULL &&(p->year > y || (p->year == y && p->name[0] > n[0]))){
		pos = move(i - 1);
		pos->next = new node(y,n,pos->next);
	}
	else{
		pos = move(i);
		pos->next = new node(y,n,pos->next);
	}
	++currentLength;
}

void sLink::remove(int i)
{
	node *pos,*delp;

	pos = move(i - 1);
	delp = pos->next;
	pos->next = delp->next;
	delete delp;
	--currentLength;
}


void sLink::list(int i)
{
    //int j=i;
    node *p=move(i);
	cout << p->year << ' '<<p->name<<endl; }

int main(int argc, char** argv) {

	sLink Tuling;
	//ifstream fin("1.in");


	int n,i = 0;  cin >> n;cin.get();
	char op[10];
	do{

		cin.getline(op,9,' ');
		++i;
		switch(op[0]){

			case 'i':
				{
				    int Year;  char Name[30];
					cin >> Year;cin.get(); cin.getline(Name,29,'\n');
					Tuling.insert(Year,Name);
					break;
				}

			case 'l':
				{
					int j; cin >>j;
					Tuling.list(j);cin.get();
					break;
				}

			case 'd':
				{
					int j; cin >> j;
					Tuling.remove(j);cin.get();
					break;
				}
		}

	}while(i < n);

	return 0;
}
