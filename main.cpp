#include <cstdlib>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class addressType {

	public:
		string street_addr;
		string city;
		string state;
		string pincode;

	public:
		void getaddr();
		void printaddr();
};


void addressType::getaddr() {

	cout<< "Enter the plot no. and street address (Example:25,Indira street): "<<endl;
	getline(cin,street_addr);
	cout<< "Enter the city: "<<endl;
	getline(cin,city);
    cout<<"Enter the state: "<<endl;
	getline(cin,state);
	cout<<"Enter 6-digit pincode: "<<endl;
	cin>>pincode;

}

void addressType::printaddr(){
	cout<<"The address is: "<<endl;
	cout<<street_addr<<endl;
	cout<<city<<endl;
	cout<<state<<endl;
	cout<<pincode<<endl;

}

class PersonType:public addressType {
	public:
		string ptype;
		string name;
		string phone_no;
		string date,month,year;
		friend class addressBookType;

	public:
		void get_pers_det();
		void print_pers_det();
};

void PersonType::get_pers_det(){
    cout<<"Enter the Relation(friend/family member/bussiness asso.):"<<endl;
    cin>>ptype;
    cout<<"Enter the name: "<<endl;
    cin>>name;
    cout<<"Enter the phone number: "<<endl;
    cin>>phone_no;
    cout<<"Enter the date of birth: "<<endl;
    cin>>date>>month>>year;
}

void PersonType::print_pers_det(){
    cout<<"The details of the person are: "<<endl;
    cout<<ptype<<endl;
    cout<<name<<endl;
    cout<<phone_no<<endl;
    cout<<date<<"/"<<month<<"/"<<year<<endl;
}

class addressBookType{
	public:
		PersonType p;
		
	public:
                void load(int m,char**item);
		void InsertPerson(int);
                void displayAddressBook(addressBookType[]);
                void readAddressBook(addressBookType[]);
                void searchintoAddressBook(string, addressBookType[]);
                void searchbyTypeAddressBook(string, addressBookType[]);
               
                void deletefromAddressBook(string, addressBookType[]);
};

void addressBookType::load(int m,char** item){


	cout<<"Serial No: "<<m<<endl;
	int i = (m-1)*10;
	p.name=item[i];
	p.ptype=item[1+i];
	p.phone_no=item[2+i];
	p.date=item[3+i];
	p.month=item[4+i];
	p.year=item[5+i];
	p.street_addr=item[6+i];
	p.city=item[7+i];
	p.state=item[8+i];
	p.pincode=item[9+i];


	cout<<"-------------------------------"<<endl;
	cout<<"Name: "<<p.name<<endl;
	cout<<"Relation: "<<p.ptype<<endl;
	cout<<"Phone No: "<<p.phone_no<<endl;
	cout<<"Date of Birth: "<<p.date<<"/"<<p.month<<"/"<<p.year<<endl;
	cout<<"Address: "<<p.street_addr<<endl;
	cout<<"City: "<<p.city<<endl;
	cout<<"State: "<<p.state<<endl;
	cout<<"Pincode: "<<p.pincode<<endl;

	cout<<"-----------------------------------"<<endl;

}


void addressBookType::InsertPerson(int n){
    fstream f;
    int i;
    f.open("Address_book.txt",ios::out|ios::app);
    if(!f)
        cout<<"unable to open the file \n"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"the detail of p"<<i+1<<endl;
        p.getaddr();
        p.get_pers_det();
        f<<p.name<<";"<<p.ptype<<";"<<p.phone_no<<";"<<p.date<<";"<<p.month<<";"<<p.year<<";"<<p.street_addr<<";"<<p.city<<";"
                <<p.state<<";"<<p.pincode<<";"<<endl;
    }
    f.close();

}

void addressBookType::displayAddressBook(addressBookType AddressBook[]){
    int i,k=0,j=0;
    char* t;
    char line[150];
    char output[100];
    char* item[1000];
    fstream file;
    file.open("Address_book.txt");
    if(!file)
        cout<<"unable to open the file \n"<<endl;
    if(file.is_open()){
		while(!file.eof()){
                    file>>output;
     		t = strtok(output,";");
            while (t != NULL) {
            	item[i] = new char[100];
            	strcpy(item[i],t);
                
                          		i++;
          		t = strtok(NULL,";");
			}
		}

	}

    file.close();

    cout<<"---------------------LOADING FROM FILE-----------------------"<<endl;
    for(i=1;i<4;i++)
            AddressBook[i-1].load(i,item);

}

int main(){
         int  k,j;
	int choice;
        addressBookType AddressBook[10];
        addressBookType P;
       do{

           cout<<"Enter the choices"<<endl;
            cout<<"[0]Enter New Entries"<<endl;
        cout<<"[1] Display the Entries"<<endl;
        cout<<"[2]EXIT"<<endl;
        do{
            cout<<"Enter the choice"<<endl;
            cin>>choice;
        }while(choice!=0&&choice!=1&&choice!=2);
        switch(choice){
            case 0:
            {cout<<"Enter the no. of p you want to enter"<<endl;
                cin>>k;
                P.InsertPerson(k);
            }
            break;
            case 1:
            {
                P.displayAddressBook(AddressBook);
            }
                break;
            case 2: {
			return (1);
		}
        }

        }while(choice!=2);


}