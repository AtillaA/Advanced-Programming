#include "person.h"
#include <iostream>
#include <string>

using namespace std;
#define always cout << "Name: " << getname() << endl << "ID: " << ID << endl;
#define perscons person(nameinput,idinput)
#define stucons Student(nameinput,idinput,accinput)
#define empcons Employee(nameinput,idinput,depart)
person:: person(string nameinput, int idinput)
	:name(nameinput), ID(idinput)
{
}
string person:: getname()
{
	return name;
}

Student:: Student(string nameinput, int idinput, bool accinput)
	:perscons, accomodation(accinput)
{

}
UnderGraduate:: UnderGraduate(string nameinput,int idinput, bool accinput, int y)
	:stucons,year(y)
{}

int UnderGraduate:: calSalary()
{
	return 0;
}

void UnderGraduate:: displayProfile()
{
	always
	if(accomodation==0)
	cout <<	"Dormitory Accomodation: No" << endl;
	else if(accomodation==1)
	cout <<	"Dormitory Accomodation: Yes" << endl;
	cout << "Year: " << year << endl;
	
}

Graduate:: Graduate(string nameinput, int idinput, bool accinput, int sR, string lvl)
	:stucons, scholarRank(sR), level(lvl)
{}

int Graduate:: calSalary()
{
	int rtr=(scholarRank-1)*1250;
	if(level=="phd")
		rtr+=600;
	else
		rtr+=500;
	return rtr;
}

void Graduate:: displayProfile()
{
	always
	if(accomodation==0)
		cout <<	"Dormitory Accomodation: No" << endl;
	else if(accomodation==1)
		cout <<	"Dormitory Accomodation: Yes" << endl;
	cout << "Scholarship Rank: " << scholarRank << endl;
	cout << "Graduate Level: " << level << endl;
	
}

Employee:: Employee(string nameinput, int idinput,string d)
	:perscons, department(d)
{}

Staff:: Staff(string nameinput,int idinput, string depart, int p, int daysOfw)
	:empcons, position(p), DaysOfWork(daysOfw)
{}

int Staff:: calSalary()
{
	return 40 * DaysOfWork * position ;
}
void Staff:: displayProfile()
{
	always
	cout << "Department: " << department << endl;
	cout << "Position:" << position << endl;
	cout << "Days of work: " << DaysOfWork << endl;
	
}

FacultyMember:: FacultyMember(string nameinput, int idinput, string depart, int classest, int offinput, int rankinput)
	:empcons,classestaught(classest),officehours(offinput), rank(rankinput)
{}
int FacultyMember:: calSalary()
{
	return (classestaught * 2000)+ (officehours * 100)+ (rank * 1000) ;
}

void FacultyMember:: displayProfile()
{
	always
	cout << "Department: " << department << endl;
	cout << "Office Hours: " << officehours << endl;
	cout << "# of classes taught: "<< classestaught << endl;
	cout << "Rank: " << rank << endl;
}