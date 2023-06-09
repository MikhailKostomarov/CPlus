#include<iostream>
#include <cstring>
#define DATE 3
#define WA 20
using namespace std; 

char* NM = nullptr;
char* MN = nullptr;
char* GR = nullptr;
int* AR = nullptr;
int* EX = nullptr;
struct Store
{
	char* name;						//��� ������
	char* manufacture;				//�������������
	char* group;					//������ ������
	int* arrival;					//���� ��������
	int* expiry;					//���� ��������
	int price;						//����

};

Store input();
void output(Store*);
int searchProdInd(Store*, int, char*);
void deleteprod(Store*, int, int);
void updtProdname(Store&, char*);
void updtProdmanf(Store&, char*);
void updtProdgrp(Store&, char*);
void updtProdarrv(Store&, int*);
void updtProdexpr(Store&, int*);
void updtProdprc(Store&, int);
Store srchNm(Store*, int, char*);
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
			char searchprod[WA];
			cout << "Enter product name: ";
			cin >> searchprod;
			Store findProd = srchNm(product, size, searchprod);
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
			char searchprod[WA];
			cout << "Enter product name: ";
			cin >> searchprod;
			Store findProd = srchNm(product, size, searchprod);
			output(&findProd);
			int id = searchProdInd(product, size, searchprod);
			int searchway;
			cout << "Choose category to edit:\n1 - name\n2 - manufacture\n3 - group\n4 - arrival date\n5 - expiry date\n6 - price\n";
			cin >> searchway;
			switch (searchway)
			{
			case 1:
				char nm[WA];
				cout << "Enter name: ";
				cin >> nm;
				updtProdname(product[id], nm);
				output(&product[id]);
				break;
			case 2:
				char mnf[WA];
				cout << "Enter manufacture: ";
				cin >> mnf;
				updtProdmanf(product[id], mnf);
				output(&product[id]);
				break;
			case 3:
				char grp[WA];
				cout << "Enter group: ";
				cin >> grp;
				updtProdgrp(product[id], grp);
				output(&product[id]);
				break;
			case 4:
				int arrv[DATE];
				cout << "Enter arrival day: ";
				cin >> arrv[0];
				while (arrv[0] > 31 || arrv[0] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> arrv[0];
				}
				cout << "Enter arrival month: ";
				cin >> arrv[1];
				while (arrv[1] > 12 || arrv[1] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> arrv[1];
				}
				cout << "Enter arrival year: ";
				cin >> arrv[2];
				updtProdarrv(product[id], arrv);
				output(&product[id]);
				break;
			case 5:
				int expr[DATE];
				cout << "Enter expiry day: ";
				cin >> expr[0];
				while (expr[0] > 31 || expr[0] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> expr[0];
				}
				cout << "Enter expiry month: ";
				cin >> expr[1];
				while (expr[1] > 12 || expr[1] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> expr[1];
				}
				cout << "Enter expiry year: ";
				cin >> expr[2];
				updtProdexpr(product[id], expr);
				output(&product[id]);
				break;
			case 6:
				int prc;
				cout << "Enter price: ";
				cin >> prc;
				updtProdprc(product[id], prc);
				output(&product[id]);
				break;
			default:
				break;
			}
			break;
		}
		case 4:
			int srchp;
			cout << "Search by:\n1 - name\n2 - manufacture\n3 - group\n4 - arrival date\n5 - expiry date\n6 - price\n";
			cin >> srchp;
			switch (srchp)
			{
			case 1:
				char nmsrch[WA];
				cout << "Enter name: ";
				cin >> nmsrch;
				Store findProd = srchNm(product, size, nmsrch);
				output(&findProd);
				break;
			case 2:
				char mnfsrch[WA];
				cout << "Enter manufacture: ";
				cin >> mnfsrch;
				findProd = srchMnf(product, size, mnfsrch);
				output(&findProd);
				break;
			case 3:
				char grpsrch[WA];
				cout << "Enter group: ";
				cin >> grpsrch;
				findProd = srchGrp(product, size, grpsrch);
				output(&findProd);
				break;
			case 4:
				int arrdsrch[DATE];
				cout << "Enter day ";
				cin >> arrdsrch[0];
				while (arrdsrch[0] > 31 || arrdsrch[0] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> arrdsrch[0];
				}
				cout << "Enter month ";
				cin >> arrdsrch[1];
				while (arrdsrch[1] > 12 || arrdsrch[1] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> arrdsrch[1];
				}
				cout << "Enter year ";
				cin >> arrdsrch[2];
				findProd = srchArrd(product, size, arrdsrch);
				output(&findProd);
				break;
			case 5:
				int expdsrch[DATE];
				cout << "Enter day ";
				cin >> expdsrch[0];
				while (expdsrch[0] > 31 || expdsrch[0] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> expdsrch[0];
				}
				cout << "Enter month ";
				cin >> expdsrch[1];
				while (expdsrch[1] > 12 || expdsrch[1] < 1)
				{
					cout << "\nError value. Try again.\n";
					cin >> expdsrch[1];
				}
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
	delete[]NM;						
	delete[]MN;				
	delete[]GR;					
	delete[]AR;					
	delete[]EX;
	NM= nullptr;
	MN= nullptr;
	GR= nullptr;
	AR= nullptr;
	EX= nullptr;
	return 0;
}

Store input()
{
	char* name1 = new char[WA];
	char* manufacture1 = new char[WA];
	char* group1 = new char[WA];
	int* arrival1 = new int[DATE];
	int* expiry1 = new int[DATE];
	int price;
	NM = name1;
	MN = manufacture1;
	GR = group1;
	AR = arrival1;
	EX = expiry1;
	cout << "Enter product name: ";
	cin >> name1;
	cout << "Enter manufacture: ";
	cin >> manufacture1;
	cout << "Enter group: ";
	cin >> group1;
	cout << "Enter arrival date:\n";
	for (int i = 0; i < DATE; i++)
	{
		if (i == 0)
		{
			cout << "Enter day: ";
			cin >> arrival1[i];
			while (arrival1[i] > 31 || arrival1[i] < 1)
			{
				cout << "\nError value. Try again.\n";
				cin >> arrival1[i];
			}
		}
		else if (i == 1)
		{
			cout << "Enter month: ";
			cin >> arrival1[i];
			while (arrival1[i] > 12 || arrival1[i] < 1)
			{
				cout << "\nError value. Try again.\n";
				cin >> arrival1[i];
			}
		}
		else if (i == 2)
		{
			cout << "Enter year: ";
			cin >> arrival1[i];
		}
	}
	cout << "Enter expiry date:\n";
	for (int i = 0; i < DATE; i++)
	{
		if (i == 0)
		{
			cout << "Enter day: ";
			cin >> expiry1[i];
			while (expiry1[i] > 31 || expiry1[i] < 1)
			{
				cout << "\nError value. Try again.\n";
				cin >> expiry1[i];
			}
		}
		else if (i == 1)
		{
			cout << "Enter month: ";
			cin >> expiry1[i];
			while (expiry1[i] > 12 || expiry1[i] < 1)
			{
				cout << "\nError value. Try again.\n";
				cin >> expiry1[i];
			}
		}
		else if (i == 2)
		{
			cout << "Enter year: ";
			cin >> expiry1[i];
		}
	}
	cout << "Enter price: ";
	cin >> price;
	return Store{ name1,manufacture1,group1,arrival1,expiry1,price };
}

void output(Store* product)
{
	cout << "Name: " << product->name << endl;
	cout << "Manufacture: " << product->manufacture << endl;
	cout << "Group: " << product->group << endl;
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
	cout << "Price: " << product->price << endl;
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
	for (int a = 0, b = 0; a < (n - 1); a++, b++)
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
	for (int i = 0; i < (n - 1); i++)
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
		else if ((i == size - 1) && match != strlen(nm))
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
		else if ((i == size - 1) && match != strlen(mnf))
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
		else if ((i == size - 1) && match != strlen(grp))
			cout << "\nGroupe is absent\n";
	}
}
Store srchArrd(Store* prod, int size, int* arrd)
{
	
	for (int i = 0; i < size; i++)
	{
		if (prod[i].arrival == arrd)
		{
			return prod[i];
		}
		else if ((i == size - 1) && prod[i].arrival != arrd)
			cout << "\nArrival date is absent\n";
	}
}
Store srchExprd(Store* prod, int size, int* axprd)
{
	
	for (int i = 0; i < size; i++)
	{
		if (prod[i].expiry == axprd)
		{
			return prod[i];
		}
		else if ((i == size - 1) && prod[i].expiry != axprd)
			cout << "\nExpiry date is absent\n";
	}
}
Store srchPrc(Store* prod, int size, int prc)
{
	
	for (int i = 0; i < size; i++)
	{
		if (prod[i].price == prc)
		{
			return prod[i];
		}
		else if ((i == size - 1) && prod[i].price != prc)
			cout << "\nPrice is absent\n";
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
				if (prod[j].price > prod[j + 1].price)
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
