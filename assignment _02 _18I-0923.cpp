//Abdul Rehman
//18I-0923
//Section: A
//Assignment 02
//Dated 16-Feb-20
#include <iostream>
#include <fstream>
#include<cstring>
#include<string>
#include<string.h>
#include <algorithm>
using namespace std;
struct database  
{
    string fname;
    string lname;
    string cnic;
    string accountid;
    string balance;

};
void output()
{
    ifstream fin;
    ofstream fout;
    database p[100];
    string r ;
    fin.open("Ass02-Customer-and-Account.txt");
    fout.open("Ass02-Customer-and-Account_output.txt");
    for(int i=0; i<100; i++)
    {
        fin>>p[i].fname>>p[i].lname>>p[i].cnic>>p[i].accountid>>p[i].balance;

        cout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" " <<p[i].balance<<endl;
        fout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" "<< p[i].balance<<endl;
    }
}
void sorting_by_firstname()
{
    database p[100];
    database temp;
    ifstream fin;
    ofstream fout;
    fin.open("Ass02-Customer-and-Account.txt");
    fout.open("Ass02-Customer-and-Account_sortFirstName_output.txt");
    cout<<"Sorting array using bubble sort technique...\n";
    for(int i=0; i<100; i++)
    {
        fin>>p[i].fname>>p[i].lname>>p[i].cnic>>p[i].accountid>>p[i].balance;
    }
    for(int i=0; i<100; i++)
    {
        for(int j=i+1; j<100; j++)
        {
            if(p[i].fname>p[j].fname)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    for(int i=0; i<100; i++)
    {

        fout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" "<< p[i].balance<<endl;
    }

    cout<<"Sorted and stored to file!!!\n";

}
void searching()
{
    fstream fin;
    fstream fout;
    fin.open("Ass02-Customer-and-Account.txt",ios::in);
    fout.open("Ass02-Customer-and-Account_output.txt");
    database p[100]; // Declaring a struct variable
    string r ;
    cout<<"enter first name to search: ";
    cin >> r;

    for(int i=0; i<100; ++i)
    {
    	           fin>>p[i].fname>>p[i].lname>>p[i].cnic>>p[i].accountid>>p[i].balance;
        if (r==p[i].fname)
        {
            cout<<"searching by first name and its information is: ";
            cout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" " <<p[i].balance<<endl;
            break;
        }
    }
}
void sorting_by_accountid()
{
	database p[100];
    database temp;
    ifstream fin;
    ofstream fout;
    fin.open("Ass02-Customer-and-Account.txt");
    fout.open("Ass02-Customer-and-Account_sortAccID_output.txt");
    cout<<"Sorting array using bubble sort technique...\n";
    for(int i=0; i<100; i++)
    {
        fin>>p[i].fname>>p[i].lname>>p[i].cnic>>p[i].accountid>>p[i].balance;
    }
    for(int i=0; i<100; i++)
    {
        for(int j=i+1; j<100; j++)
        {
            if(p[i].accountid>p[j].accountid)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(int i=0; i<100; i++)
    {
        fout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" "<< p[i].balance<<endl;
    }
    cout<<"Sorted and stored to file!!!\n";
}
void sorting_by_balance()
{
    database p[100];
    database temp;
    ifstream fin;
    ofstream fout;
    fin.open("Ass02-Customer-and-Account.txt");
    fout.open("Ass02-Customer-and-Account_sortBalance_output.txt");
    cout<<"Sorting array using bubble sort technique...\n";
    for(int i=0; i<100; i++)
    {
        fin>>p[i].fname>>p[i].lname>>p[i].cnic>>p[i].accountid>>p[i].balance;
    }
    for(int i=0; i<100; i++)
    {
        for(int j=i+1; j<100; j++)
        {
            int a,b;
            a = atoi(p[i].balance.c_str());
            b = atoi(p[j].balance.c_str());
            if(a>b)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(int i=0; i<100; i++)
    {
        fout << p[i].fname<<" " << p[i].lname << " "<<p[i].cnic <<" " << p[i].accountid<<" "<< p[i].balance<<endl;
    }
    cout<<"Sorted and stored to file!!!\n";
}
void addRecord()
{
	fstream fout;
	fout.open("Ass02-Customer-and-Account_output.txt",ios :: app);
	database p;
	cout<<"enter first name: ";
	cin>>p.fname;
	cout<<"enter last name: ";
	cin>>p.lname;
	cout<<"enter cnic name: ";
	cin>>p.cnic;
	cout<<"enter  account id: ";
	cin>>p.accountid;
	cout<<"enter balance: ";
	cin>>p.balance;
	fout<< p.fname<<" " << p.lname << " "<<p.cnic <<" " << p.accountid<<" "<< p.balance<<endl;	
}
int main()
{
    database d;
    int choice;
    cout<<"***Acount Information System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Display output of file";
        cout<<"\n\t2-->Show search by first Name from file";
        cout<<"\n\t3-->sort by first Name from file";
        cout<<"\n\t4-->Sort customers data on basis of Account ID";
        cout<<"\n\t5-->Sort customers data on basis of Balance.";
        cout<<"\n\t6-->Add Record";
        cout<<"\n\t7-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            output();
            break;
                    case 2:
            searching();
            break;
                    case 3:
            sorting_by_firstname();
            break;
        case 4:
            sorting_by_accountid();
            break;
        case 5:
            sorting_by_balance();
            break;
        case 6:
            addRecord();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";
            return 0;
        }
    }
}
