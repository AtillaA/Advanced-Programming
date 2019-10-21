#include <iostream>
#include <string>
#include "person.h"
 using namespace std;

#define MENU  cout << "Choose an option (1,2,3, or 4):" << endl <<"1. undergraduate student" << endl << "2. graduate student" << endl << "3. staff" << endl<< "4. faculty member" << endl;

 person* getPerson()
 {
	
	 MENU
	 int option;
	 cin >> option;
	 person *p=nullptr;
	 string name, department,level;
	 int id, year, scholarrank,position,daysofwork,classestaught,officehours, rank;
	 bool acc;
	  UnderGraduate*  undergrad ;
	  Graduate *grad;
	  FacultyMember * facultymem;
	  Staff * staff ;
	 switch(option)
	 {
	 case 1:
		
		 cout << "You chose undergraduate. Give person's name, id, accommodation status (1 for yes and 0 for no), and year:" << endl;
		 cin >> name >> id >> acc >> year ;
		 undergrad =new UnderGraduate(name,id,acc,year);
		 p=undergrad;
		 break;
	 case 2:
		
		 cout << "You chose graduate. Give person's name, id, accommodation status (1 for yes and 0 for no),scholar Rank(btw 1 and 3) and level(phd or master):" << endl;
		 cin >> name >> id >> acc >> scholarrank >> level ;
		 grad=new Graduate(name,id,acc,scholarrank,level);	 
		 p=grad ;
		 break;
	 case 3:
		 
		 cout << "You chose staff. Give person's name, id, department, position(btw 1 and 4) and Days of work:" << endl;
		 cin >> name >> id >> department >> position >> daysofwork ;
		 staff= new Staff(name,id,department,position,daysofwork); 
		 p=staff;
		 break;
	 case 4:
		 
		 cout << "You chose faculty member. Give person's name, id, department, number of classes taught,officehours, and rank(btw 1 and 4):" << endl;
		 cin >> name>>id >>department >>classestaught >>officehours >>rank ;
		 facultymem=new FacultyMember(name,id,department,classestaught,officehours,rank) ;
		 p=facultymem;
		 break;

	 }

	 return p;
 }

int main()
{
	cout<<"WELCOME TO THE PERSON PROGRAM"<<endl;
	cout<<"FOR EXITIING PRESS Y/y, OTHERWISE PRESS ANY KEY"<<endl;
	person *person_1; /* define person_1 of the class person.*/
	char c;
	while (tolower(c = getchar())!='y')
	{
		cout<<"Getting person "<<endl;
		person_1 = getPerson();
		cout<<"********************************************************************"<<endl<<endl;
	    cout<<"The profile of a person:"<<endl;
		if(person_1!=nullptr)
		{
			person_1->displayProfile();
			cout<<"Salary: "<<person_1->calSalary()<<endl;
		}
		else 
		{
			cout << "No such option is found!" << endl;
		}
		cout<<"********************************************************************"<<endl;
		cout<<"FOR EXITIING PRESS Y/y, OTHERWISE, FOR ANOTHER COMPARISON PRESS ANY KEY"<<endl<<endl;
      cin.ignore();//flushing the buffer for remaining character(s), in order getchar() to work
	}
	cout<<"PROGRAM EXITING. THANKS FOR USING IT."<<endl;
    system("pause");
    return 0;
}