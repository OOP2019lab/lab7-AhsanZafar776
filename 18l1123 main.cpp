#include "bankAccount.h"
#include<fstream>
#include<string>
//
bankAccount** readFile(string path,int &count); 
void printAccounts(bankAccount**b,int size);
////bool makeTransaction(....);
////void deleteAccounts(....);
//
void main()
{
	//	/********************************TASK 0*************************************
	//	Take a look at class bankAccount header file and implememtion
	//	***************************************************************************/
	//	
	//	/* 
	//	Syntax to declare a pointer of object is 
	//	<classname> * ptrIdentifier;
	//	Syntax to allocate a new object to pointer is 
	//	ptrIdentifier= new constructor_of_class(argument's list);
	//	declareing and initializebn can be done at same time using following syntax
	//	<classname> * ptrIdentifier= new constructor_of_class(argument's list);
	//	*/
	//
	//	/********************************TASK 1*************************************
	//	Create a pointer to a bank account with name b1
	//	/allocate an object of type bankAccount this the pointer, the ID=10, balance=13000 and balanceLimit=15000 using appropriate constructor
	//	*/
	bankAccount * b1;
	b1= new bankAccount(10,13000,15000);
	//
	//
	//	//***************************END OF TASK 1**********************************
	//	
	//	
	//	
	//	/*
	//	Syntax to access members of object using its pointer is 
	//	ptrIdentifier->memberFunction(argument's list);
	//	ptrIdentifier->memberVariable;
	//	*/
	//	
	//	/********************************TASK 2*************************************
	//	Write a code to 
	//	print b1 created in task 1

	//	deposit 1000 is  b1
	//	deposit 3000 in b1
	//	withdraw 10000 from b1
	//	withdraw 6000 from b1
	//	print b1 again
	//	/*Write your code here for task 2, ~6 lines*/
	//	
	b1->print();
	b1->deposit(1000);
	b1->deposit(3000);
	b1->withdraw(10000);
	b1->withdraw(6000);
	b1->print();
	//
	//
	//	//***************************END OF TASK 2**********************************
	//	
	//
	//	/*Static array of pointers to objects is created using following syntax
	//	<className> *arrayIdentifier[n]
	//	where n is constant integer
	//
	//	Objects have to be allocate to these pointers one by one. Use following syntax to allocate  new object to ith pointer in array
	//	arrayIdentifier[i]= new constructor_of_class(argument's list);
	//	*/
	//
	//	/********************************TASK 3*************************************
	//	Declare an array of pointers to bankAccounts  of size 2, ~1 line code
	//	Assign a new object to 1st pointer in array with ID= 30, balance=2000, transactions=[3000,5000,60000] balanceLimit should default value ~2 lines
	//	Assign a new object to 1st pointer in array with ID= 40, balance=255000, balanceLimit=400000 ~1 line
	//	print both the objects ~ 2 line
	//	*/
	//	//*****Write your code here

	float transactions[3]={3000,5000,60000};


	bankAccount *b2[2];
	b2[0]=new bankAccount(30,2000,transactions,3);
	b2[1]=new bankAccount(40,255000,40000);
	b2[0]->print();
	b2[1]->print();

	//
	//
	//
	//
	//
	//	//***************************END OF TASK 3**********************************
	//	
	//	/*Dynamic array of ptr to objects is create using following syntax
	//	<className> **dyarrayIdentifier= new className*[size];
	//	to assign object to array use
	//	dyarrayIdentifier[i]= new constructor(args);
	//	*/
	//
	//	/********************************TASK 4*************************************
	//	//Create a dynamic array of pointers to bankAccount objects of size 2 ~1 line code
	//	//Assign a new object to 1st pointer in array with ID= 50, balance=2000, transactions=[-5000,5000] balanceLimit should default value ~2 lines
	//	//Assign a new object to 1st pointer in array with ID= 60, balance=6000, balanceLimit=400000 ~1 line
	//	//withDraw amount of 1000 from account with ID 50 (ie first one in array) ~1line
	//	//print both the objects ~ 2 line
	//	//*****Write your code here

	float transactions1[2]={-5000,5000};
	bankAccount **b3=new bankAccount *[2];
	b3[0]=new bankAccount (50,2000,transactions,2);
	b3[1]=new bankAccount (60,6000,400000);
	b3[0]->withdraw(1000);
	b3[0]->print();
	b3[1]->print();

	//	//***************************END OF TASK 4**********************************
	//	
	//

	//	To delete the memory dynamically allocate to a pointer using the following
	//	delete ptrIdentifier
	//	if pointers were in array delete memory allocate to all pointer using  index 
	//	delete arrayIdentifier[i]	
	//	doing so will automatically invoke the destructor of the object
	//	if the array was dynamic it should also be deleted after deleting all the pointers to objects
	//	*/
	//
	//	/********************************TASK 5*************************************
	//	Delete any dynamic memory you have allocate so far


	delete b1;
	delete b2[0];
	delete b2[1];

	for( int i=0;i<2;i++)
		delete  b3[i];
	delete []b3;

	//	//***************************END OF TASK 5**********************************
	//	
	//	/*Return array of pointer to objects from function
	//	To return any array of pointer of object from function return type should be 
	//	<className> **
	//	See the example given in https://drive.google.com/drive/u/0/folders/12EbjlE4s-VwTH1FLLCS83h4QYTHJhksS
	//	*/
	//	
	//	/********************************TASK 6*************************************
	//	Write a function that takes a file name as input and reads the information of bank accounts from files, also get the size of returned array from the function
	//	data is given in file  data.txt
	//	1st line in this file contains the number of accounts in file
	//	Each subsequent line constain information of a bankAccount if following format
	//	ID balance limit noOfTransactions transactions1 transaction 2 ..... transactionN
	//	where N=noOfTransactions
	//	NOTE: You can only read file once in function. You cannot read file outside the function. 
	//    **** Complete the prototype of function in line 3 and body after main() function in given space (you cannot change the name of function)
	//	Call this function for data.txt file
	int size;
	bankAccount **b4;
	b4=readFile("data.txt",size);
	//
	//	/********************************TASK 7*************************************
	//	Write a function the takes array of pointers to objects, of bankAccunt type, as input and prints all the bankAccounts
	//	**** Complete the prototype of function in line 4 and body after main() function in given space
	//	(you cannot change the name and return typeof function)

	printAccounts(b4,size);
	//
	//	/********************************TASK 8*************************************
	//	Write a function that takes array of pointers to objects, of bankAccount type, ID, amount and transaction type as input
	//	The function should find the account with  ID in the array and perform the transaction on that account 
	//	if the transaction was successful  it should return 1 else 0
	//    if account with given ID does not exists should print that "Account not found"
	//
	//	**** Complete the prototype of function in line 5 and body after main() function in given space (you cannot change the name and return type of function)
	//	
	//	Invoke this function for array create in step 5, ID=5 and amount=6000 and type= withdraw
	//	*/
	//
	//
	//	/********************************TASK 9*************************************
	//	//Write a function that takes an array of pointers to object as input and 
	//	//deletes all the accounts from input array with balance=0 and noOfTransactions=0
	//	//**** Complete the prototype of function in line 6 and body after main() function in given space (you cannot change the name and return type of function)
	//	
	//	//Invoke this function for array created in step 5
	//	*/
	//
	//	/********************************TASK 10*************************************
	//	delete all the memory you have allocate anywhere in your code using only delete or delete[] operations
	//	*/
	//
	//
	//
	//
	//
	//
	//
	//
	//	system("PAUSE");
}
//
//
bankAccount** readFile(string path,int& count)
{
	ifstream fin(path);
	int id,noOftransaction;
	float balancelimit,balance;
	count=0;
	string temp;
	fin>>count;
	bankAccount **b4 = new bankAccount *[count];
	for(int j=0;j<count;j++)
	{

		getline(fin,temp,' ');
		id=stoi(temp);
		getline(fin,temp,' ' );
		balance=stof(temp);
		getline(fin,temp,' ');
		balancelimit=stof(temp);
		getline(fin,temp,' ');
		noOftransaction=stoi(temp);
		float *transaction = new float [noOftransaction];
		for(int i=0;i<noOftransaction;i++)
		{
			getline(fin,temp,' ');
			transaction[i]=stof(temp);
		}

		b4[j] = new bankAccount (id,balance,transaction,noOftransaction,balancelimit);
	}
	return *b4;

}









void printAccounts(bankAccount ** b,int size)
{
	for(int i =0;i<size;i++)
		b[i]->print();
}
////bool makeTransaction(....){}
////void deleteAccounts(....){}