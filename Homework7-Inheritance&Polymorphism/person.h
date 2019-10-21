#ifndef _PERSON_H
#define _PERSON_H

#include <string>
using namespace std;


class person
{
public:
	person(string nameinput, int idinput);
	virtual int calSalary()=0;
	virtual void displayProfile()=0;
	string getname();
protected:
	int ID;
private:
	string name;
};

class Student: public person
{
public:
	Student(string nameinput, int idinput, bool acc);
	virtual int calSalary()=0;
	virtual void displayProfile()=0;

protected:
	bool accomodation;

};
class UnderGraduate:public Student
{
public:
	UnderGraduate(string nameinput, int idinput, bool acc, int year);
	int calSalary();
	void displayProfile();

private:
	int year;
};
class Graduate: public Student
{
public:
	Graduate(string nameinput,int idinput,bool acc, int scholarrankinput,string levelinput);
	int calSalary();
	void displayProfile();
private:
	int scholarRank;
	string level;
};

class Employee: public person
{
public:
	Employee(string nameinput, int idinput, string departmentinput);
	virtual int calSalary()=0;
	virtual void displayProfile()=0;
	

protected:
	string department;
};
class Staff:public Employee
{
public:
	Staff(string nameinput, int idinput, string departmentinput, int positioninput, int daysinput);
	int calSalary();
	void displayProfile();

private:
	int position;
	int DaysOfWork;
};
class FacultyMember:public Employee
{
public:
	FacultyMember(string nameinput, int idinput ,string departinput, int classestaughtinput, int offinput, int rankinput);
	int calSalary();
	void displayProfile();

private:
	int classestaught;
	int officehours;
	int rank;
};

#endif