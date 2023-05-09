#include<iostream>
#include <cstring>
#define DATE 3
using namespace std;

struct Store
{
	char* name;						//имя товара
	char* manufacture;				//производитель
	char* group;					//группа товара
	int* arrival;					//дата поставки
	int* expiry;					//срок годности
	int price;						//цена

};

Store input();
void output(Store*);
Store searchName(Store*,int,char*);
int searchProdInd(Store*, int, char*);
void deleteprod(Store*, int, int);
void updtProdname(Store&, char*);
void updtProdmanf(Store&, char*);
void updtProdgrp(Store&, char*);
void updtProdarrv(Store&, int*);
void updtProdexpr(Store&, int*);
void updtProdprc(Store&, int );
Store srchNm(Store*,int,char*);
Store srchMnf(Store*, int, char*);
Store srchGrp(Store*, int, char*);
Store srchArrd(Store*, int, int*);
Store srchExprd(Store*, int, int*);
Store srchPrc(Store*, int, int);
void bubbleSort(Store*, int);


int main()
{
	int size = 2;
	Store* product = new Store[size];
	int choice;
	for (int i = 0; i < size; i++)
	{
		product[i] = input();
		cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		output(&product[i]);
	}
	cout << endl;
	int b;
	cout << "Enter digit to start\n";
	cin >> b;
	while (b)
	{
		cout << "Select action:\n1 - add product\n2 - delete product\n3 - edit product\n4 - find product\n5 - show product\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			size++;
			Store* newprod = new Store[size];
			newprod = product;
			Store* product = new Store[size];
			product = newprod;
			product[size - 1] = input();
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				output(&product[i]);
			}
			cout << endl;
			break;
		}
		case 2:
		{
			int proddelete;
			char searchprod[20];
			cout << "Enter product name: ";
			cin >> searchprod;
			Store findProd = searchName(product, size, searchprod);
			output(&findProd);
			int id = searchProdInd(product, size, searchprod);
			cout << "\nDo you want to delete?\n1 - yes\n2 - no\n";
			cin >> proddelete;
			if (proddelete == 1)
			{
				deleteprod(product, id, size);
			}
			else if (proddelete != 1)
			{
				break;
			}
			break;
		}
		case 3:
		{
			int proddelete;
			char searchprod[20];
			cout << "Enter product name: ";
			cin >> searchprod;
			Store findProd = searchName(product, size, searchprod);
			output(&findProd);
			int searchway;
			cout << "Choose category to edit:\n1 - name\n2 - manufacture\n3 - group\n4 - arrival date\n5 - expiry date\n6 - price\n";
			cin >> searchway;
			switch (searchway)
			{
			case 1:
				char nm[20];
				cout << "Enter name: ";
				cin >> nm;
				updtProdname(findProd, nm);
				output(&findProd);
				break;
			case 2:
				char mnf[20];
				cout << "Enter manufacture: ";
				cin >> mnf;
				updtProdmanf(findProd, mnf);
				output(&findProd);
				break;
			case 3:
				char grp[20];
				cout << "Enter group: ";
				cin >> grp;
				updtProdgrp(findProd, grp);
				output(&findProd);
				break;
			case 4:
				int arrv[DATE];
				cout << "Enter arrival day: ";
				cin >> arrv[0];
				cout << "Enter arrival month: ";
				cin >> arrv[1];
				cout << "Enter arrival year: ";
				cin >> arrv[2];
				updtProdarrv(findProd, arrv);
				output(&findProd);
				break;
			case 5:
				int expr[DATE];
				cout << "Enter expiry day: ";
				cin >> expr[0];
				cout << "Enter expiry month: ";
				cin >> expr[1];
				cout << "Enter expiry year: ";
				cin >> expr[2];
				updtProdexpr(findProd, expr);
				output(&findProd);
				break;
			case 6:
				int prc;
				cout << "Enter price: ";
				cin >> prc;
				updtProdprc(findProd, prc);
				output(&findProd);
				break;
			default:
				break;
			}

		}
		case 4:
			int srchp;
			cout << "Search by:\n1 - name\n2 - manufacture\n3 - group\n4 - arrival date\n5 - expiry date\n6 - price\n";
			cin >> srchp;
			switch (srchp)
			{
			case 1:
				char nmsrch[20];
				cout << "Enter name: ";
				cin >> nmsrch;
				Store findProd = srchNm(product, size, nmsrch);
				output(&findProd);
				break;
			case 2:
				char mnfsrch[20];
				cout << "Enter manufacture: ";
				cin >> nmsrch;
				findProd = srchMnf(product, size, mnfsrch);
				output(&findProd);
				break;
			case 3:
				char grpsrch[20];
				cout << "Enter group: ";
				findProd = srchGrp(product, size, grpsrch);
				output(&findProd);
				break;
			case 4:
				int arrdsrch[DATE];
				cout << "Enter day ";
				cin >> arrdsrch[0];
				cout << "Enter month ";
				cin >> arrdsrch[1];
				cout << "Enter year ";
				cin >> arrdsrch[2];
				findProd = srchArrd(product, size, arrdsrch);
				output(&findProd);
				break;
			case 5:
				int expdsrch[DATE];
				cout << "Enter day ";
				cin >> expdsrch[0];
				cout << "Enter month ";
				cin >> expdsrch[1];
				cout << "Enter year ";
				cin >> expdsrch[2];
				findProd = srchExprd(product, size, expdsrch);
				output(&findProd);
				break;
			case 6:
				int prcpr;
				cout << "Enter price: ";
				cin >> prcpr;
				findProd = srchPrc(product, size, prcpr);
				output(&findProd);
				break;
			default:
				break;
			}
			break;
		case 5:
			bubbleSort(product, size);
			for (int i = 0; i < size; i++)
			{
				output(&product[i]);
			}
			cout << endl;
			break;
		default:
			break;
		}
		cout << "\nEnter digit to continue, char to exit: ";
		cin >> b;
	}
	
	delete[]product;
	product = nullptr;
	return 0;
}

Store input()
{
	char* name = new char[20];
	char* manufacture = new char[20];
	char* group = new char[20];
	int* arrival = new int[DATE];
	int* expiry = new int[DATE];
	int price;
	cout << "Enter product name: ";
	cin >> name;
	cout << "Enter manufacture: ";
	cin >> manufacture;
	cout << "Enter group: ";
	cin >> group;
	cout << "Enter arrival date:\n";
	for (int i = 0; i < DATE; i++)
	{
		if (i == 0)
		{
			cout << "Enter day: ";
			cin >> arrival[i];
		}
		else if (i == 1)
		{
			cout << "Enter month: ";
			cin >> arrival[i];
		}
		else if (i == 2)
		{
			cout << "Enter year: ";
			cin >> arrival[i];
		}
	}
	cout << "Enter expiry date:\n";
	for (int i = 0; i < DATE; i++)
	{
		if (i == 0)
		{
			cout << "Enter day: ";
			cin >> expiry[i];
		}
		else if (i == 1)
		{
			cout << "Enter month: ";
			cin >> expiry[i];
		}
		else if (i == 2)
		{
			cout << "Enter year: ";
			cin >> expiry[i];
		}
	}
	cout << "Enter price: ";
	cin >> price;
	return Store{ name,manufacture,group,arrival,expiry,price };
}

	void output(Store* product)
	{
		cout << "Name: " << product->name <<endl;
		cout << "Manufacture: " << product->manufacture<< endl;
		cout << "Group: "<<product->group<<endl;
		cout << "Arrival date: ";
		for (int i = 0; i < DATE; i++)
		{
			cout << product->arrival[i] << " ";
		}
		cout << endl;
		cout << "Expiry date: ";
		for (int i = 0; i < DATE; i++)
		{
			cout << product->expiry[i] << " ";
		}
		cout << endl;
		cout << "Price: " << product->price<< endl;
	}

	Store searchName(Store* prod, int size, char* name)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (strlen(prod[i].name) == strlen(name))
			{
				for (int j = 0; j < (strlen(name)); j++)
				{
					if(prod[i].name[j]==name[j])
						match++;
				}
				if (match == strlen(name))
					return prod[i];
				match = 0;
			}
			else if((i==size-1)&&match != strlen(name))
				cout << "\nProduct name is absent\n";
		}
	}

	int searchProdInd(Store* prod, int size, char* name)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (strlen(prod[i].name) == strlen(name))
			{
				for (int j = 0; j < (strlen(name)); j++)
				{
					if (prod[i].name[j] == name[j])
						match++;
				}
				if (match == strlen(name))
					return i;

			}
		}
	}

	void deleteprod(Store* prod, int id, int n)
	{
		Store* delprod = new Store[n - 1];
		for (int a = 0, b=0; a < (n-1); a++,b++)
		{
			if (b == (id))
			{
				a--;
				continue;
			}
			else
				delprod[a] = prod[b];
		}
		cout << endl;
		for (int i = 0; i < (n-1); i++)
		{
			output(&delprod[i]);
		}
		cout << endl;
	}

	void updtProdname(Store& prod, char* nm)
	{
		prod.name = nm;
	}

	void updtProdmanf(Store& prod, char* manf)
	{
		prod.manufacture = manf;
	}

	void updtProdgrp(Store& prod, char* grp)
	{
		prod.group = grp;
	}

	void updtProdarrv(Store& prod, int* arrv)
	{
		prod.arrival = arrv;
	}

	void updtProdexpr(Store& prod, int* expr)
	{
		prod.expiry = expr;
	}

	void updtProdprc(Store& prod, int prc)
	{
		prod.price = prc;
	}

	Store srchNm(Store* prod, int size, char* nm)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (strlen(prod[i].name) == strlen(nm))
			{
				for (int j = 0; j < (strlen(nm)); j++)
				{
					if (prod[i].name[j] == nm[j])
						match++;
				}
				if (match == strlen(nm))
					return prod[i];
				match = 0;
			}
			else
				cout << "\nName is absent\n";
		}
	}
	Store srchMnf(Store* prod, int size, char* mnf)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (strlen(prod[i].manufacture) == strlen(mnf))
			{
				for (int j = 0; j < (strlen(mnf)); j++)
				{
					if (prod[i].manufacture[j] == mnf[j])
						match++;
				}
				if (match == strlen(mnf))
					return prod[i];
				match = 0;
			}
			else
				cout << "\nManufacture is absent\n";
		}
	}
	Store srchGrp(Store* prod, int size, char* grp)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (strlen(prod[i].group) == strlen(grp))
			{
				for (int j = 0; j < (strlen(grp)); j++)
				{
					if (prod[i].group[j] == grp[j])
						match++;
				}
				if (match == strlen(grp))
					return prod[i];
				match = 0;
			}
			else
				cout << "\nGroupe is absent\n";
		}
	}
	Store srchArrd(Store* prod, int size, int* arrd)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (prod[i].arrival == arrd)
			{
				return prod[i];
			}
		}
	}
	Store srchExprd(Store* prod, int size, int* axprd)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (prod[i].expiry == axprd)
			{
				return prod[i];
			}
		}
	}
	Store srchPrc(Store* prod, int size, int prc)
	{
		int match = 0;
		for (int i = 0; i < size; i++)
		{
			if (prod[i].price == prc)
			{
				return prod[i];
			}
		}
	}

	void bubbleSort(Store* prod, int n)
	{
		int a;
		cout << "Select sorting type:\n1 - by price\n2 - by group\n";
		cin >> a;
		switch (a)
		{
		case 1:
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n - i - 1; j++)
				{
					if (prod[j].price>prod[j + 1].price)
					{
						swap(prod[j], prod[j + 1]);
					}
				}
			}
			break;
		case 2:
			for (int k = 0; k < n - 1; k++)
			{
				for (int l = 0; l < n - k - 1; l++)
				{
					if (strcmp(prod[l].group, prod[l + 1].group) == 1)
					{
						swap(prod[l], prod[l + 1]);
					}
				}
			}
			break;
		default:
			break;
		}
	}
