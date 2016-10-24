#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
/////////better version////////////////
using namespace std;
struct Employee
{
    int EmpId;
    string EmpName;
    string EmpQualification;
    string EmpDesignation;
    int EmpSalary;
};
void getdata(Employee &E)
{
    char ch;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Enter The Id Of The Employee (<:should be unique:>) : ";
    cin>>E.EmpId;
    cout<<endl;
    cout<<"Enter The Employee Name : ";
    cin.get(ch);
    getline(cin,E.EmpName);
    //  cout<<endl;
    cout<<"Enter The Employee Qualification : ";
   cin.get(ch);
    getline(cin,E.EmpQualification);
    cout<<"Enter The Employee Designation : ";
   cin.get(ch);
    getline(cin,E.EmpDesignation);
    cout<<"Enter The Employee Salary : Rs.";
    cin>>E.EmpSalary;
    cout<<"---------------------------------------------------------"<<endl;
}
void showdata(Employee &E)
{
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"The Id Of The Employee Is : "<<E.EmpId<<endl;
    //usleep(40000);
    cout<<" The Employee Name Is: "<<E.EmpName<<endl;
    //usleep(40000);
    cout<<"The Employee Qualification Is : "<<E.EmpQualification<<endl;
    //usleep(40000);
    cout<<" The Employee Designation Is : "<<E.EmpDesignation<<endl;
    //usleep(40000);
    cout<<"The Employee Salary Is : Rs."<<E.EmpSalary<<endl;
    //usleep(40000);
    cout<<"---------------------------------------------------------"<<endl;
}
int main()
{
    Employee E;
    unsigned const int usec = 2000000;
    usleep(usec);
    cout <<"HELLO WELCOME HERE YOU CAN INTERACTIVALY ADD,MODIFY,DELETE,SEARCH EMPLOYEE INFORMATION"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
       
  
        char choice;
        int intchoice;
        unsigned int usec1 = usec/5;
    /////////variable to use for employee///////
        int id;
        /*string name;
        string desig;
        int salary;
    /////////////////////////////////////////////    
        string quali;*/
     do{
            usleep(usec1*3); 
            cout<<"Enter 1 For Creating  A Employee Record"<<endl;
            usleep(usec1);
            cout<<"Enter 2 For Modifying A Employee Record"<<endl;
            usleep(usec1);
            cout<<"Enter 3 For Searching A Employee Record"<<endl;
            usleep(usec1);
            cout<<"Enter 4 For Deleting  A Employee Record"<<endl;
            usleep(usec1);
            cout<<"Enter 5 For Printing Employees Records"<<endl;
            usleep(usec1);
        /////////////choice entering state///////
            cin>>intchoice;
        ////////////////////////////////////////
switch(intchoice)
{
    case 1:
        {
            
            fstream fout;
            fout.open("file6.dat",ios::app|ios::binary);
            if(!fout)
            {
                cerr<<"There Was An Error In Opening The File"<<endl;
                return 1;
            }
            usleep(usec1);
            cout<<"OK :"<<endl;
            getdata(E);
            fout.write((char*) &E,sizeof(Employee));
            cout<<endl;
            fout.close();
            break;
        }
            
    case 2:
        {
            char ch;
            cout<<"Ok Are You Sure To Change the Student Record Enter Y To Confirm Or N To Stop : "<<endl;
            cin>>ch;
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            
            Employee E;
            if(ch != 'n' || ch !='N')
            {
                usleep(usec1);
                cout<<"Enter The Id Of The Employee To Modify : ";
                cin>>id;
                fstream modify;
                
                modify.open("file6.dat",ios::in|ios::out|ios::binary);
                if(!modify)
                {
                    cerr<<"There Was An Error In Opening File "<<endl;
                    return 2;
                }
            modify.seekg(0,ios::beg);
            bool flag = false; 
            unsigned long int i;
            while(!modify.eof())
            {
                i = modify.tellg();
                modify.read((char*) &E,sizeof(Employee));
                if(E.EmpId == id)
                {
                    cout<<"Enter The Modified Information Of The Employee"<<endl;
                    getdata(E);
                    flag = true;
                    modify.seekg(i);
                    modify.write((char*) &E,sizeof(Employee));
                    break;
                }
            
            }
            if(flag == true)
            {
                
                cout<<"Sucessfully Modified"<<endl;
                modify.seekg(0,ios::beg);
                
                cout<<"The Contents In The File After Modifying Are : "<<endl;
                cout<<"----------------------------------------------------------"<<endl;
                char ch;
                while(!modify.eof())
                   {
                       cin.get(ch);
                       modify.read((char*) &E,sizeof(Employee));
                       
                       showdata(E);
                       cout<<endl;
                   }
                   modify.close();
              }
            else
            {
                cout<<"Record Not Found"<<endl;
                modify.close();
                
            }
            }
            else
            {
                break;
            }
                        
                        
                        
                        
        break;
        }
    
    case 3:
        { 
            Employee E;
            fstream search;
            search.open("file6.dat",ios::in|ios::binary);
            if(!search)
            {
                cerr<<"There Was An Error In Opening The File"<<endl;
                return 3;
            }
            usleep(usec1);
            cout<<"Enter The Id of The Employee To Be Searched For : ";
            cin>>id;
            usleep(usec1);
            cout<<"---------------------------------------------------------"<<endl;
            search.seekg(0,ios::beg); //to placethe file pointer in the begining of the file...
            bool flag = false; 
            while(!search.eof())
            {
                search.read((char*) &E,sizeof(Employee));
                if(E.EmpId == id)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == true)
            {
                cout<<"Your Given Id Is Sucessfully Found In The Database"<<endl;
                cout<<"---------------------------------------------------------"<<endl;
                usleep(usec1);
                unsigned long int i = search.tellg();
                search.seekg(i - sizeof(E));
                showdata(E);
                cout<<"----------------------------------------------------------"<<endl;
                search.close();
            }
            else
            {
                std::cout << "The Given Id Was Not Found In The Database" << std::endl;
                search.close();
            }
          break;
        }
    
    case 4:
        {
            char c;
            
            usleep(usec1);
            cout<<"Are You Really Sure To Delete Data From The Database Enter n or N for Neglect Else Any Key To Proceed"<<endl;
            cin>>c;
            cout<<endl;
            usleep(usec1/2);
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            if(c == 'n' || c == 'N')
            {
                break;
            }
            else
            {
                fstream Delete;
                Delete.open("file6.dat",ios::in|ios::binary);
                
                if(!Delete)
                {
                    cerr<<"There Was An Error In Opening The File"<<endl;
                    return 4;                    
                }
                fstream Del;
                Del.open("file7.dat",ios::out|ios::binary);
                if(!Del)
                {
                    cerr<<"There Was An Error In Opening The File"<<endl;
                    return 5;
                }
                Del.seekp(0,ios::beg);
                
                usleep(usec1);
                cout << "Enter The Id of The Employee To Be Deleted : ";
                cin>>id;
                cout<<"-------------------------------------------------------"<<endl;
                Delete.seekg(0,ios::beg);
                bool flag = false;
                
                while(!Delete.eof())
                {
                    Delete.read((char*) &E,sizeof(Employee));
                    if(E.EmpId == id)
                    {
                        cout<<"The Deleted Record Is : "<<endl;
                        usleep(usec1);
                        showdata(E);
                        flag = true;
                        
                    }
                    else{
                    Del.write((char*) &E,sizeof(E));
                    }
                }
               if(flag == false)
               {
                   std::cout << "The Given Id Was Not Found In The Database" << std::endl;
                   Delete.close();
                   Del.close();
                   remove("file7.dat");
               }
               else
               {
                   
                   Delete.close();
                   Del.close();
                   remove("file6.dat");
                   rename("file7.dat","file6.dat");
                   cout<<"The Contents In The File After Deleting "<<endl;
                   cout<<"----------------------------------------------------------"<<endl;
                   usleep(usec);
                   Delete.open("file6.dat",ios::in|ios::binary);
                   if(!Delete)
                   {
                    cerr<<"There Was An Error In Opening The File"<<endl;
                    return 6;
                   }
                   
                   Delete.seekg(0,ios::beg);
                   while(!Delete.eof())
                   {
                       Delete.read((char*) &E,sizeof(E));
                       showdata(E);
                       cout<<endl;
                   }
                   Delete.close();
                   
               }
            }
            
            
            
            break;
        }
        
        case 5:
           {
              
               fstream fin;
               fin.open("file6.dat",ios::in|ios::binary);
                   
                   if(!fin)
                   {
                    cerr<<"There Was An Error In Opening The File"<<endl;
                    return 7;
                   }
                   
                   //fin.seekg(0,ios::beg);
                   cout<<"The Contents In The File Are : "<<endl;
                   cout<<"----------------------------------------------------------"<<endl;
                   while(!fin.eof())
                   {
                       fin.read((char*) &E,sizeof(Employee));
                       showdata(E);
                       cout<<endl;
                   }
                   fin.close();
              break;     
              }
        
    default :
       {
            cout<<"Wrong Choice Entered Please Enter A Valid Choice Thanks"<<endl;
            break;
       }
    
    
        
                    
        }
        
       usleep(usec1*2); 
       cout<<"WANT TO PERFORM MORE OPERATION ENTER y OR Y TO PROCEED ELSE N OR n TO STOP :"<<endl;
       cin>>choice;
       if(choice == 'n' || choice == 'N')
       {
           usleep(usec1*2);
           cout<<"Thanks For Visiting : Exiting"<<endl;
           usleep(usec1*3);
       }
     }while(choice =='Y' || choice =='y');
     
     
     
     
    
     
     
     
     
     
     
     
     
        
        
    
    return 0 ;
}