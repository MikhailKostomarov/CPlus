#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
using namespace std;


class Card
{
	int number;
	float ballance;
public:
	Card() {}
	Card(int v)
	{
		number = v;
		ballance = 0.0;
	}
	Card(int n, float b) :number(n), ballance(b) {}

	void setnumber(int n)
	{
		number = n;
		ballance = 0.0;
	}

	void cardinput()
	{
		cout << "Enter card number: ";
		cin >> number;
		ballance = 0.0;
	}
	void plus(float s)
	{
		ballance += s;
	}
	void minus(float s)
	{
		if (s > ballance)
			cout << "Not enough on ballance!" << endl;
		else
			ballance -= s;
	}

	float getballance()
	{
		return ballance;
	}

	int getnumber()
	{
		return number;
	}

	virtual void display()
	{
		cout << "Card: " << number << endl;
		cout << "Ballance: " << ballance << endl;
	}
};

class Dcard : public Card
{
public:
	Dcard() {}
	Dcard(int n, float f) :Card(n, f) {}
	void display() override
	{
		cout << "Card: " << getnumber() << endl;
		cout << "Ballance: " << getballance() << endl;
	}
};


class Ccard : public Card
{
	float credit;
public:
	Ccard() {}
	Ccard(int n) :Card(n)
	{
		credit = 0.0;
	}
	Ccard(int n, float f, float c) :Card(n, f), credit(c) {}

	void cardinput()
	{
		int numb;
		cout << "Enter card number: ";
		cin >> numb;
		setnumber(numb);
		credit = 0.0;
	}

	void setcredit(float f)
	{
		credit += f;
	}

	float getcredit()
	{
		return credit;
	}

	void display() override
	{
		cout << "Card: " << getnumber() << endl;
		cout << "Ballance: " << getballance() << endl;
		//cout << "You have credit: " << getcredit() << endl;
	}

	void creditout()
	{
		cout << "You have credit: " << credit << endl;
	}
};

class Wallet
{
	int number;
	float ballance;
public:
	Wallet() {}
	Wallet(int v)
	{
		number = v;
		ballance = 0.0;
	}
	Wallet(int n, float b) :number(n), ballance(b) {}

	void setnumber(int n)
	{
		number = n;
		ballance = 0.0;
	}

	void walletinput()
	{
		cout << "Enter wallet number: ";
		cin >> number;
		ballance = 0.0;
	}
	void plus(float s)
	{
		ballance += s;
	}
	void minus(float s)
	{
		if (s > ballance)
			cout << "Not enough on ballance!" << endl;
		else
			ballance -= s;
	}

	float getballance()
	{
		return ballance;
	}

	int getnumber()
	{
		return number;
	}

	virtual void display()
	{
		cout << "Wallet: " << number << endl;
		cout << "Ballance: " << ballance << endl;
	}
};

class Dwallet : public Wallet
{
public:
	Dwallet() {}
	Dwallet(int n, float f) :Wallet(n, f) {}
	void display() override
	{
		cout << "Wallet: " << getnumber() << endl;
		cout << "Ballance: " << getballance() << endl;
	}
};


class Cwallet : public Wallet
{
	float credit;
public:
	Cwallet() {}
	Cwallet(int n) :Wallet(n)
	{
		credit = 0.0;
	}
	Cwallet(int n, float f, float c) :Wallet(n, f), credit(c) {}

	void walletinput()
	{
		int numb;
		cout << "Enter wallet number: ";
		cin >> numb;
		setnumber(numb);
		credit = 0.0;
	}

	void setcredit(float f)
	{
		credit += f;
	}

	float getcredit()
	{
		return credit;
	}

	void display() override
	{
		cout << "Wallet: " << getnumber() << endl;
		cout << "Ballance: " << getballance() << endl;
		//cout << "You have credit: " << getcredit() << endl;
	}

	void creditout()
	{
		cout << "You have credit: " << credit << endl;
	}
};

class Date
{
	int dy;
	int mnth;
	int yr;
	int crd;
	float sm;
	int exp;
public:
	Date() {}
	Date(int d, int m, int y, int c, float s, int xp)
	{
		if (m > 12 || m < 1)
			throw 1.1;
		if (y % 4 == 0 && (m == 2 && d > 29 || d < 1))
			throw 'a';
		else if (y % 4 != 0 && (m == 2 && d > 28 || d < 1))
			throw 'a';
		else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 31 || d < 1))
			throw 'a';
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30 || d < 1))
			throw 'a';
		else if (xp < 1 || xp>3)
			throw 100;
		else
		{
			dy = d;
			mnth = m;
			yr = y;
			crd = c;
			sm = s;
			exp = xp;
		}

	}

	float getsm()
	{
		return sm;
	}

	int getday()
	{
		return dy;
	}

	int getmonth()
	{
		return mnth;
	}

	int getyear()
	{
		return yr;
	}

	int getexp()
	{
		return exp;
	}

	int getcard()
	{
		return crd;
	}

	void out()
	{
		cout << "Date: " << dy << "." << mnth << "." << yr << endl;
		cout << "Card numb: " << crd << endl;
		cout << "Summ: " << sm << endl;
		if (exp == 1)
			cout << "Internet payment\n---------------------------------" << endl;
		else if (exp == 2)
			cout << "Shop payment\n---------------------------------" << endl;
		else if (exp == 3)
			cout << "Transference\n---------------------------------" << endl;
	}
};


class PFCS 
{
	vector<Wallet*>vecwal;
	vector<Card*>veccard;
	vector<Date>vecdate;
public:
	PFCS() {}
	void addcard()
	{
		
		int ch;
		cout << "Select card type you want to add: 1 - debid\t2 - credit" << endl;
		cin >> ch;
		while (ch != 1 && ch != 2)
		{
			cout << "Error! please press '1' or '2' to create card" << endl;
			cin >> ch;
		}
			
		switch (ch)
		{
		case 1:
		{
			Card* crd = new Dcard;
			bool stt=true;
			crd->cardinput();
			for (vector<Card*>::iterator it = veccard.begin(); it != veccard.end(); ++it)
			{
				if ((*it)->getnumber() == crd->getnumber())
					stt = false;
			}
			if (stt == false)
			{
				cout << "This card is exist!" << endl;
			}
			else
			{
				veccard.push_back(crd);
			}
			
			break;
		}

		case 2:
		{
			Ccard* ccrd=new Ccard;
			bool stt = true;
			ccrd->cardinput();
			Card* crd = ccrd;
			for (vector<Card*>::iterator it = veccard.begin(); it != veccard.end(); ++it)
			{
				if ((*it)->getnumber() == crd->getnumber())
					stt = false;
			}
			if (stt == false)
			{
				cout << "This card is exist!" << endl;
			}
			else
			{
				veccard.push_back(crd);
			}

			break;
		}

		}
		
	}

	void addball()
	{
		int ch;
		cout << "Enter card number to add ballance" << endl;
		cin >> ch;
		float sum;
		cout << "Enter summ" << endl;
		cin >> sum;
		for (auto crd : veccard)
		{
			if (crd->getnumber() == ch)
				crd->plus(sum);
		}

	}

	void addcredit()
	{
		bool stt = true;
		int ch;
		cout << "Enter card number to take credit" << endl;
		cin >> ch;
		for (vector<Card*>::iterator it = veccard.begin(); it != veccard.end(); ++it)
		{
			if ((*it)->getnumber() == ch)
			{
				stt = false;
				float sum;
				cout << "Enter summ" << endl;
				cin >> sum;
				while (sum < 0)
				{
					cout << "Summ should be greater 0" << endl;
					cin >> sum;
				}
				Ccard* crds = dynamic_cast<Ccard*>(*it);
				if (crds)
				{
					crds->setcredit(sum);
				}
				
			}
				
		}
		if (stt == true)
		{
			cout << "This card does not exist!" << endl;
		}
		
	}

	string spendtype(int n)
	{
		if (n == 1)
			return "Internet payment\n---------------------------------\n";
		else if (n == 2)
			return "Shop payment\n---------------------------------\n";
		else if (n == 3)
			return "Transference\n---------------------------------\n";
	}


	void spending()
	{
		int ch;
		bool stt = true;
		cout << "Enter card number to spending: " << endl;
		cin >> ch;
		for (vector<Card*>::iterator it = veccard.begin(); it != veccard.end(); ++it)
		{
			if ((*it)->getnumber() == ch)
				stt = false;
		}
		if (stt == false)
		{
			float sum;
			cout << "Enter summ to spend: " << endl;
			cin >> sum;
			for (auto crd : veccard)
			{
				if (crd->getnumber() == ch)
					crd->minus(sum);

			}
			int d;
			int m;
			int y;
			int cat;
			cout << "Enter day of tranzaction: " << endl;
			cin >> d;
			cout << "Enter month of tranzaction: " << endl;
			cin >> m;
			cout << "Enter year of tranzaction: " << endl;
			cin >> y;
			cout << "Enter category of spending: 1 - Internet shopping, 2 - Shopping, 3 - Payment" << endl;
			cin >> cat;
			while (cat != 1 && cat != 2 && cat != 3)
			{
				cout << "Error! enter 1 - 3 number to make choice." << endl;
				cin >> cat;
			}
			Date dt(d, m, y, ch, sum, cat);
			vecdate.push_back(dt);
		}
		else
		{
			cout << "Error card number! This card is not exist." << endl;
		}
		

	}

	void dayspend()
	{
		vector<Date> vm;
		int d;
		int m;
		int y;
		cout << "Enter day of report: " << endl;
		cin >> d;
		cout << "Enter month of report: " << endl;
		cin >> m;
		cout << "Enter year of report: " << endl;
		cin >> y;
		cout << "Dayly report: " << endl;
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if ((d == (*it).getday()) && (m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				vm.push_back((*it));
				(*it).out();
			}

		}
		int sv;
		cout << "Do you want save report to file? 1 - yes  2 - no" << endl;
		cin >> sv;
		while ((sv != 1) && (sv != 2))
		{
			cout << "Please selec shoice '1' or '2'" << endl;
			cin >> sv;
		}
		switch (sv)
		{
		case 1:
		{

			ofstream file("dayspend.txt", ofstream::app);
			if (file.is_open())
			{

				for (vector<Date>::iterator it = vm.begin(); it != vm.end(); ++it)
				{
					string f = spendtype((*it).getexp());
					file << "Date: " << (*it).getday() << "." << (*it).getmonth() << "." << (*it).getyear() << endl
						<< "Card numb: " << (*it).getcard() << endl
						<< "Summ: " << (*it).getsm() << endl << f;
				}
				file.close();
				cout << "File saved" << endl;
			}
			else
			{
				cout << "Error\n";
			}
			break;
		}
		case 2:
			break;
		}
	}

	void weekspend()
	{
		vector<Date> vm;
		int d;
		int m;
		int y;
		cout << "Enter start day of weekly report: " << endl;
		cin >> d;
		cout << "Enter month of report: " << endl;
		cin >> m;
		cout << "Enter year of report: " << endl;
		cin >> y;
		cout << "Weekly report: " << endl;
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if (((d == (*it).getday())|| ((*it).getday()<=(d+7))) && (m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				vm.push_back((*it));
				(*it).out();
			}
		}
		int sv;
		cout << "Do you want save report to file? 1 - yes  2 - no" << endl;
		cin >> sv;
		while ((sv != 1) && (sv != 2))
		{
			cout << "Please selec shoice '1' or '2'" << endl;
			cin >> sv;
		}
		switch (sv)
		{
		case 1:
		{

			ofstream file("weekspend.txt", ofstream::app);
			if (file.is_open())
			{
				
				for (vector<Date>::iterator it = vm.begin(); it != vm.end(); ++it)
				{
					string f = spendtype((*it).getexp());
					file << "Date: " << (*it).getday() << "." << (*it).getmonth() << "." << (*it).getyear() << endl
						<< "Card numb: " << (*it).getcard() << endl
						<< "Summ: " << (*it).getsm() << endl << f;
				}
				file.close();
				cout << "File saved" << endl;
			}
			else
			{
				cout << "Error\n";
			}
			break;
		}
		case 2:
			break;
		}
	}

	void monthspend()
	{
		vector<Date> vm;
		int m;
		int y;
		cout << "Enter month of monthly report: " << endl;
		cin >> m;
		cout << "Enter year of report: " << endl;
		cin >> y;
		cout << "Monthly report: " << endl;
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if ((m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				vm.push_back((*it));
				(*it).out();
			}
			
		}
		int sv;
		cout << "Do you want save report to file? 1 - yes  2 - no" << endl;
		cin >> sv;
		while ((sv != 1) && (sv != 2))
		{
			cout << "Please selec shoice '1' or '2'" << endl;
			cin >> sv;
		}
		switch (sv)
		{
		case 1:
		{
			
			ofstream file("monthspend.txt", ofstream::app);
			if (file.is_open())
			{
				
				for (vector<Date>::iterator it = vm.begin(); it != vm.end(); ++it)
				{
					string f = spendtype((*it).getexp());
					file << "Date: " << (*it).getday() << "." << (*it).getmonth() << "." << (*it).getyear() << endl
						<< "Card numb: " << (*it).getcard() << endl
						<< "Summ: " << (*it).getsm()<< endl << f;
				}
				file.close();
				cout << "File saved" << endl;
			}
			else
			{
				cout << "Error\n";
			}
			break;
		}
		case 2:
			break;
		}
	}

	void top3weekly()
	{
		float fst=0;
		int fstcat;
		float snd=0;
		int sndcat;
		float thrd=0;
		int thrdcat;
		int d;
		int m;
		int y;
		cout << "Enter start day of weekly top3 report: " << endl;
		cin >> d;
		cout << "Enter month of report: " << endl;
		cin >> m;
		cout << "Enter year of report: " << endl;
		cin >> y;
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if (((d == (*it).getday()) || ((*it).getday() <= (d + 7))) && (m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if (((*it).getsm()) > fst)
				{
					fst = (*it).getsm();
					fstcat = (*it).getexp();
				}
					
			}
				
		}
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if (((d == (*it).getday()) || ((*it).getday() <= (d + 7))) && (m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if ((((*it).getsm()) < fst) && ((*it).getsm() > snd))
				{
					snd = (*it).getsm();
					sndcat= (*it).getexp();
				}
					
			}

		}
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if (((d == (*it).getday()) || ((*it).getday() <= (d + 7))) && (m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if ((((*it).getsm()) < snd) && ((*it).getsm() > thrd))
				{
					thrd = (*it).getsm();
					thrdcat= (*it).getexp();
				}
					
			}

		}
		cout << "Top3 weekly sum and category:\n" << endl;
		cout << "1 " << fst << " "<<spendtype(fstcat);
		cout << "2 " << snd << " " << spendtype(sndcat);
		cout << "3 " << thrd << " " << spendtype(thrdcat);
		int sv;
		cout << "Do you want save report to file? 1 - yes  2 - no" << endl;
		cin >> sv;
		while ((sv != 1) && (sv != 2))
		{
			cout << "Please selec shoice '1' or '2'" << endl;
			cin >> sv;
		}
		switch (sv)
		{
		case 1:
		{
			string f = spendtype(fstcat);
			string s = spendtype(sndcat);
			string t = spendtype(thrdcat);
			ofstream file("top3week.txt", ofstream::app);
			if (file.is_open())
			{
				file << "Top3 weekly sum and category:\n" << endl
					<< "1 " << fst << " " << f << endl
					<< "2 " << snd << " " << s << endl
					<< "3 " << thrd << " " << t << endl;
				file.close();
				cout << "File saved" << endl;
			}
			else
			{
				cout << "Error\n";
			}
			break;
		}
		case 2:
			break;
		}
	}

	void top3monthly()
	{
		float fst = 0;
		int fstcat;
		float snd = 0;
		int sndcat;
		float thrd = 0;
		int thrdcat;
		int m;
		int y;
		cout << "Enter month of monthly top3 report: " << endl;
		cin >> m;
		cout << "Enter year of report: " << endl;
		cin >> y;
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if ((m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if (((*it).getsm()) > fst)
				{
					fst = (*it).getsm();
					fstcat = (*it).getexp();
				}

			}

		}
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if ((m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if ((((*it).getsm()) < fst)&&((*it).getsm()>snd))
				{
					snd = (*it).getsm();
					sndcat = (*it).getexp();
				}

			}

		}
		for (vector<Date>::iterator it = vecdate.begin(); it != vecdate.end(); ++it)
		{
			if ((m == (*it).getmonth()) && (y == (*it).getyear()))
			{
				if ((((*it).getsm()) < snd) && ((*it).getsm() > thrd))
				{
					thrd = (*it).getsm();
					thrdcat = (*it).getexp();
				}

			}

		}
		cout << "Top3 monthly sum and category:\n" << endl;
		cout << "1 " << fst << " " << spendtype(fstcat);
		cout << "2 " << snd << " " << spendtype(sndcat);
		cout << "3 " << thrd << " " << spendtype(thrdcat);
		int sv;
		cout << "Do you want save report to file? 1 - yes  2 - no" << endl;
		cin >> sv;
		while ((sv != 1) && (sv != 2))
		{
			cout << "Please selec shoice '1' or '2'" << endl;
			cin >> sv;
		}
		switch (sv)
		{
		case 1:
		{
			string f = spendtype(fstcat);
			string s = spendtype(sndcat);
			string t = spendtype(thrdcat);
			ofstream file("top3month.txt", ofstream::app);
			if (file.is_open())
			{
				file << "Top3 monthly sum and category:\n" << endl
					<< "1 " << fst << " " << f << endl
					<< "2 " << snd << " " << s << endl
					<< "3 " << thrd << " " << t << endl;
				file.close();
				cout << "File saved" << endl;
			}
			else
			{
				cout << "Error\n";
			}
			break;
		}
		case 2:
			break;
		}
	}

	void displ()
	{
		for (auto crd : veccard)
		{
			
			Ccard* crds = dynamic_cast<Ccard*>(crd);
			if (crds)
			{
				cout << "--------------------------------" << endl;
				crds->display();
				crds->creditout();
				cout << "--------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------" << endl;
				crd->display();
				cout << "--------------------------------" << endl;
			}
		}
	}

	void addwallet()
	{
		
		int ch;
		cout << "Select wallet type you want to add: 1 - debid\t2 - credit" << endl;
		cin >> ch;
		while (ch != 1 && ch != 2)
		{
			cout << "Error! please press '1' or '2' to create wallet" << endl;
			cin >> ch;
		}

		switch (ch)
		{
		case 1:
		{
			Wallet* wlt = new Dwallet;
			wlt->walletinput();
			bool stt = true;
			for (vector<Wallet*>::iterator it = vecwal.begin(); it != vecwal.end(); ++it)
			{
				if ((*it)->getnumber() == wlt->getnumber())
					stt = false;
			}
			if (stt == false)
			{
				cout << "This card is exist!" << endl;
			}
			else
			{
				vecwal.push_back(wlt);
			}
			break;
		}

		case 2:
		{
			Cwallet* cwlt = new Cwallet;
			cwlt->walletinput();
			bool stt = true;
			Wallet* wlt = cwlt;
			for (vector<Wallet*>::iterator it = vecwal.begin(); it != vecwal.end(); ++it)
			{
				if ((*it)->getnumber() == wlt->getnumber())
					stt = false;
			}
			if (stt == false)
			{
				cout << "This card is exist!" << endl;
			}
			else
			{
				vecwal.push_back(wlt);
			}
			break;
		}

		}

	}

	void addballwalet()
	{
		int ch;
		cout << "Enter wallet number" << endl;
		cin >> ch;
		float sum;
		cout << "Enter summ" << endl;
		cin >> sum;
		for (auto wlt : vecwal)
		{
			if (wlt->getnumber() == ch)
				wlt->plus(sum);
		}

	}

	void addcreditwallet()
	{
		bool stt = true;
		int ch;
		cout << "Enter wallet number to take credit" << endl;
		cin >> ch;
		for (vector<Wallet*>::iterator it = vecwal.begin(); it != vecwal.end(); ++it)
		{
			if ((*it)->getnumber() == ch)
			{
				stt = false;
				float sum;
				cout << "Enter summ" << endl;
				cin >> sum;
				while (sum < 0)
				{
					cout << "Summ should be greater 0" << endl;
					cin >> sum;
				}
				Cwallet* crds = dynamic_cast<Cwallet*>(*it);
				if (crds)
				{
					crds->setcredit(sum);
				}

			}

		}
		if (stt == true)
		{
			cout << "This wallet does not exist!" << endl;
		}

	}

	void spendingwallet()
	{
		int ch;
		bool stt = true;
		cout << "Enter wallet number: " << endl;
		cin >> ch;
		for (vector<Wallet*>::iterator it = vecwal.begin(); it != vecwal.end(); ++it)
		{
			if ((*it)->getnumber() == ch)
				stt = false;
		}
		if (stt == false)
		{
			float sum;
			cout << "Enter summ to spend: " << endl;
			cin >> sum;
			for (auto wlt : vecwal)
			{
				if (wlt->getnumber() == ch)
					wlt->minus(sum);
			}
			int d;
			int m;
			int y;
			int cat;
			cout << "Enter day of tranzaction: " << endl;
			cin >> d;
			cout << "Enter month of tranzaction: " << endl;
			cin >> m;
			cout << "Enter year of tranzaction: " << endl;
			cin >> y;
			cout << "Enter category of spending: 1 - Internet shopping, 2 - Shopping, 3 - Payment" << endl;
			cin >> cat;
			while (cat != 1 && cat != 2 && cat != 3)
			{
				cout << "Error! enter 1 - 3 number to make choice." << endl;
				cin >> cat;
			}
			Date dt(d, m, y, ch, sum, cat);
			vecdate.push_back(dt);
		}
		else
		{
			cout << "Error wallet number! This wallet is not exist." << endl;
		}

	}

	void displwallet()
	{
		for (auto wlt : vecwal)
		{
			
			Cwallet* wlts = dynamic_cast<Cwallet*>(wlt);
			if (wlts)
			{
				cout << "--------------------------------" << endl;
				wlts->display();
				wlts->creditout();
				cout << "--------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------" << endl;
				wlt->display();
				cout << "--------------------------------" << endl;
			}
		}
	}

};


int main()
{
	
	//Ccard emp(111,0,12000);
	//emp.plus(30000);
	//emp.display();
	//emp.creditout();

	
	PFCS exmpl;
	exmpl.addcard();
	exmpl.addcard();
	exmpl.addcard();
	exmpl.addcard();
	exmpl.displ();
	exmpl.addball();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.spending();
	exmpl.displ();
	exmpl.addcredit();
	exmpl.displ();
	//exmpl.monthspend();
	//exmpl.top3monthly();
	//exmpl.top3weekly();
	//exmpl.weekspend();
	//cout << "Day spending:\n----------------------------------------\n";
	//exmpl.dayspend();
//	exmpl.addwallet();
//	exmpl.addwallet();
//	exmpl.addwallet();
//	exmpl.displwallet();
//	exmpl.addballwalet();
//	exmpl.displwallet();
	
	return 0;
}