//////////////////////header files////////////////
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<string>
using namespace std;
//////////////////////////////////////////////////
///////////used consts////////////////
#define HASH_MAX 23
const int Max=20;
unsigned const int usec = 2000000;
unsigned const int usec1=usec/5;
double const KNUTHVAL = (sqrt(5)-1)/2;
////////////////////////////////////////

////////student structure//////////
struct student
{
   char name[Max];
   int id;
   student *next;	
};
//////////////////////////////////

//////////////hash key generator///////////
int inthash(int key)
{
	/////according to knuth statement//////

	return(floor((HASH_MAX)*fmod((key*KNUTHVAL),1))); 
}

//////////////////////////////////////////////

/////////////node creator with values//////////
student *createnode(char *name,int id)
{
	if(name != NULL)
	{
		
		
		student *temp = new student;
		strcpy(temp->name,name);
		temp->id = id;
		temp->next= NULL;
	    return temp;	
	}
	else
	{
		cout<<"Please supply the initial values to proceed"<<endl;
		return NULL;
	}
	
}
//////////////////////////////insert function according to key //////////////////////////////
 void insertstart(student **arr,student *newaddr,int hashkey)
{
    student *temp = NULL;
    if(arr[hashkey] == NULL)
    {
        arr[hashkey] = newaddr;
    }
    else
    {
        bool flag  = false;
        temp = arr[hashkey];
        ////check to see whether the id exist in the table or not/////
        while(temp != NULL)
        {
            if(newaddr->id == temp->id)
            {
                flag = true;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        
        if(flag == true)
        {
            std::cout << "The Given Id Is Already Existing In The Table" << std::endl;
            std::cout << "Can't Insert" << std::endl;
            
        }
        else
        {
            temp = arr[hashkey]  ;
            arr[hashkey] = newaddr;
            newaddr->next = temp;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

//////////////function to print the results of the search/////////////////////////////////////

void printresult(student **arr,int hashkey,int id)
{
    if(arr[hashkey] == NULL)
    {
        std::cout << "The Given Id Doesn't Belongs To The Table " << std::endl;
        std::cout << "No Record To Print " << std::endl;
    }
    else
    {
        
        student *temp = arr[hashkey];
        if(temp->id == id)
        {
            std::cout << "Student Name Is ---> "<<temp->name << std::endl;
            std::cout <<"Student Id Is ---> "<<temp->id << std::endl;
        }
        else
        {   
            bool flag = false ;
            while(temp != NULL)
            {
                if(temp->id == id)
                {
                    flag = true;
                    std::cout << "Student Name Is ---> "<<temp->name << std::endl;
                    std::cout <<"Student Id Is ---> "<<temp->id << std::endl;
                    break;
                }  
                temp = temp->next;
            }
            if(flag == false)
            {
                std::cout << "The Given Id Doesn't Belongs To The Table " << std::endl;
                std::cout << "No Record To Print " << std::endl;
                
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////function to delete an item /////////////////////////////////////

void deletelist(student **arr,int hashkey,int id)
{
     if(arr[hashkey] == NULL)
     {
                   cout<<"The Table Doesn't Contains The Given Id"<<endl;
                   std::cout << "Can't Delete" << std::endl;
                    
    }
       
    else
    {
        student *temp = arr[hashkey] ;
        int count = 0;
        while(temp !=NULL)
        {
            count +=1;
            temp = temp->next;
        }
        if(count == 1)
        {
            temp = arr[hashkey];
            if(temp->id == id)
            {
                arr[hashkey] = NULL;
                delete temp;
            }
            else
            {
                cout<<"The Table Doesn't Contains The Given Id"<<endl;
                std::cout << "Can't Delete" << std::endl;
            }
        }
        else
        {
            bool flag  = false;
            int count1=0;
            temp = arr[hashkey];
            while(temp != NULL)
            {
                if(temp->id == id)
                {
                    flag = true;
                    break;
                    
                }
                else
                {
                    count1 +=1;
                    temp = temp->next;
                }
            }
            if(flag == true)
            {
                student *temp1 = arr[hashkey];
                for(int i=1;i<count1;i++)
                {
                    temp1 = temp1->next;
                }
                
                if(temp->next == NULL)
                {
                    temp1->next = NULL;
                    delete temp;
                }
                else
                {
                    temp1->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    
                }
            }
            else
            {
                cout<<"The Table Doesn't Contains The Given Id"<<endl;
                std::cout << "Can't Delete" << std::endl;
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////MAIN/////////////////////////////////////////////////
int main()
{
	/////////use chaining method////////
	
	
	/*create an lookup table of size 23 an prime no*/
	student *Hasharray[HASH_MAX];
    
    //////////making the array pointer point to null positions////////
    for(int i=0;i<HASH_MAX;i++)
    {
    	Hasharray[i] = NULL;
	}
	
	//////used vars for my loop/////
	char choice;
	int intchoice;
	char name[Max];
	int key;
	int id;
	//////////////////////////////
    
	do
	{
		    usleep(usec1*3); 
            cout<<"Enter 1 For Creating  A Student Record"<<endl;
            usleep(usec1);
            cout<<"Enter 2 For Searching A Student Record"<<endl;
            usleep(usec1);
            cout<<"Enter 3 For Deleting  A Student Record"<<endl;
            usleep(usec1);
            
        /////////////choice entering state///////
            cin>>intchoice;
        ////////////////////////////////////////
///////////////////////////////////////////////switch/////////////////////////////////////////        
switch(intchoice)
{
    case 1:
        {
            char ch;
            std::cout << "OK:" << std::endl; 
            std::cout << "Enter The Id Of The Student" << std::endl;
            std::cin >> id;
            std::cout << "Enter The Name Of The Student" << std::endl;
            cin.get(ch);
            cin.get(name,Max);
            key = inthash(id);
            
            student *temp = createnode(name,id);
            insertstart(Hasharray,temp,key);
            usleep(usec1);
            std::cout << "successfully Inserted :)" << std::endl;
            break;
        }
        
    case 2:
       {
            std::cout << "OK:" << std::endl;
            usleep(usec1);
            std::cout << "Enter The Id Of The Student" << std::endl;
            std::cin >> id;
            key = inthash(id);
            printresult(Hasharray,key,id);
            break;
       }
	
	case 3:
	  {
	       std::cout << "OK : " << std::endl;
           usleep(usec1);
           char c;
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
                cout << "Enter The Id Of The Student" <<endl;
                cin >> id;
                key = inthash(id);
                deletelist(Hasharray,key, id);
                cout<<"Deleted Successfully : "<<endl;
            }    
	    break;
	  }
		
	default:
	   {
	       cout<<"Wrong Choice Entered Please Enter A Valid Choice Thanks"<<endl;
	       break;
	   }
		
}	
///////////////////////////switch ends here//////////////////////////////////////////////	
		
		
		
		
		
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
     
	return 0;
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////