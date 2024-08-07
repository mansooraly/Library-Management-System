#include<iostream>
#include<fstream>                        // FILE HANDLING  USED TO SAVE RECORDS 
#include<string>
using namespace std;

// ( Filehandling, FUNC , POINTERS , DYNAMIC MEMORY ALLOCATION USED )

void booksquantity(int*, int*);           // dynamically  saving quantity of books using pointers

void booksdetails(string*);              //POINTERS

void booksibanumber(int*, int*);          // dynamically  saving iban numbers of books using pointers


void issuingbook(int, int, int*, string, string, string, string, string, int*);

void checkbookdetails(int, int*, int*, string*);            //POINTERS PREFFERED OVER ARRAYS  

void returningbook(int, int, string, string, string, string, string, int*, int*);

int main()
{

	ofstream sr;
	ofstream tr;

	sr.open("Student records.txt", ios::app);
	tr.open("Teacher records.txt", ios::app);




	cout << "     ***************************************************************      " << endl;
	cout << "                       LIBRARY MANAGEMENT SYSTEM                          " << endl;
	cout << "     ***************************************************************      " << endl << endl;

	cout << "         BOOKS CAN ONLY BE ISSUED TO STUDENTS OR TEACHERS.                " << endl << endl;

	string ss = "STUDENT", tt = "TEACHER", sss = "student", ttt = "teacher", s;

	cout << " PLEASE TYPE  'STUDENT/ student'  OR  ' TEACHER /teacher' " << endl;
	cout << " ENTER PERSON TYPE : ";
	getline(cin, s);



	while (s != ss && s != sss && s != tt && s != ttt) //STRINGS CONDITIONS CHECK
	{

		cout << endl << " INVALID PERSON TYPE!" << endl;
		cout << " PLEASE RE-TYPE  'STUDENT/ student'  OR  ' TEACHER /teacher' " << endl;
		cout << " RE-ENTER PERSON TYPE : ";
		getline(cin, s);


	}




	int bq[4];                   //4 BOOKS KI  COPIES 4 HAIN SO SAVING 4 AT EVERY BOOKQUANTITY 

	int *q = NULL;

	booksquantity(bq, q);        // this  func saves 4 at EACH index of array of bquantity

	string bok[4];              // ALL 4  BOOKS mh unki details store krne k liye
	booksdetails(bok);          // this is func


	int iban[4];              // SAVING VALUES OF BOOK IBAN NO AT DIFFERENT IBAN INDEXES 

	int *z = NULL;            // IBAN NUMBERS MEANS = IDENTIFICATION OF BOOKS ACCORDING TO NUMBERS 
	booksibanumber(iban, z);



	string gender, name, age;
	string stdname, rolln, stdage;

	if (s == sss || s == ss) // AGAR STUDENT/student type kre
	{
		cout << endl << "          WE WARMLY WELCOME OUR STUDENTS TO THIS LIBRARY.       ";

		cout << endl << " ENTER YOUR NAME : ";
		getline(cin, stdname);

		cout << endl << endl << " ENTER YOUR ROLL NUMBER : ";
		getline(cin, rolln);


		cout << endl << "ENTER YOUR AGE  : ";
		getline(cin, stdage);




		cout << endl << "ENTER YOUR GENDER 'MALE' / 'male' OR 'FEMALE' / 'female': ";
		cin >> gender;

		while (gender != "MALE" && gender != "FEMALE" && gender != "male" && gender != "female")
		{
			cout << " INVALID GENDER CHOICE !" << endl;
			cout << " RE-ENTER YOUR GENDER MALE OR FEMALE : ";
			cin >> gender;
		}

		if (s == sss || s == ss)
		{
			sr << endl << endl << "NAME OF THE STUDENT IS :  " << stdname;
			sr << endl << "ROLL NUMBER OF THE STUDENT IS :  " << rolln;
			sr << endl << "AGE  OF THE STUDENT IS :  " << stdage;
			sr << endl << "GENDER OF THE STUDENT IS :  " << gender << endl;
			sr << endl << "USER HISTORY IS BELOW :-  " << endl;

		}


		cout << "==============================================" << endl << endl;
		cout << "        WELCOME TO MAIN MENU OF LIBRARY !     " << endl << endl;



		cout << "==============================================" << endl << endl;


	}

	if (s == tt || s == ttt)// agar person type teacher hai then this will execute
	{
		cout << endl << "          WE WARMLY WELCOME OUR TEACHERS TO THIS LIBRARY.       ";



		cout << endl << endl << " ENTER YOUR FULL NAME  : ";
		getline(cin, name);

		cout << endl << "ENTER YOUR AGE : ";
		getline(cin, age);



		cout << endl << "ENTER YOUR GENDER 'MALE' / 'male' OR 'FEMALE' / 'female': ";
		cin >> gender;


		cout << "==============================================" << endl << endl;
		cout << "        WELCOME TO MAIN MENU OF LIBRARY !     ";




		cout << endl << endl << endl;

	}


	if (s == tt || s == ttt)
	{


		tr << endl << endl << "NAME OF THE TEACHER IS :  " << name;
		tr << endl << "AGE  OF THE TEACHER IS :  " << age;
		tr << endl << "GENDER OF THE TEACHER IS :  " << gender << endl;
		tr << endl << "USER HISTORY IS BELOW :-  " << endl;
	}



	cout << "=====================================================" << endl;

	char r = 0; //  MENU BASED SYSTEM  RUNS ACC TO CONDITION
	int count = 0;
	int ibaninput = 0, copyinput = 0;

	do{



		cout << endl << endl << " ENTER 'I' OR 'i' TO ISSUE A BOOK. " << endl << endl;
		cout << " ENTER 'C' OR 'c' CHECK BOOK DETAILS. " << endl << endl;
		cout << " ENTER 'R 'OR 'r' TO RETURN A BOOK. " << endl << endl;
		cout << " ENTER 'E' OR 'e' TO EXIT " << endl << endl;

		cout << " ENTER YOUR CHOICE : ";
		cin >> r;

		while (r != 'I'&&r != 'i'&&r != 'R'&&r != 'r'&&r != 'C'&&r != 'c'&&r != 'E'&&r != 'e')
		{
			cout << endl << endl << " INVALID CHOICE ! " << endl << endl;
			cout << " ENTER I/i TO ISSUE A BOOK." << endl << endl;
			cout << " ENTER 'C' OR 'c' CHECK BOOK DETAILS. " << endl << endl;
			cout << " ENTER R/r TO RETURN A BOOK." << endl << endl;
			cout << " ENTER 'E' OR 'e' TO EXIT " << endl << endl;
			cout << " RE-ENTER YOUR CHOICE : ";
			cin >> r;

		}

		ibaninput = 0, copyinput = 0;



		if (r == 'I' || r == 'i')
		{


			issuingbook(ibaninput, copyinput, bq, s, ss, sss, tt, ttt, iban);


		}


		int input = 0;



		if (r == 'C' || r == 'c')
		{


			checkbookdetails(input, iban, bq, bok);



		}




		int r_iban = 0, r_copies = 0;


		if (r == 'R' || r == 'r')
		{


			returningbook(r_iban, r_copies, s, ss, sss, tt, ttt, iban, bq);

		}




		if (s == ss || s == sss)

		{
			cout << endl << endl << "NAME OF THE STUDENT IS :  " << stdname;
			cout << endl << endl << "ROLL NUMBER OF THE STUDENT IS :  " << rolln;
			cout << endl << endl << "AGE NUMBER OF THE STUDENT IS :  " << stdage;
			cout << endl << endl << "GENDER OF THE STUDENT IS :  " << gender;

		}

		if (s == tt || s == ttt)
		{


			cout << endl << endl << "NAME OF THE TEACHER IS :  " << name;
			cout << endl << endl << "AGE  OF THE TEACHER IS :  " << age;
			cout << endl << endl << "GENDER OF THE TEACHER IS :  " << gender;

		}



	} while (r != 'E' && r != 'e');

	sr.close();
	tr.close();


}


void booksquantity(int *b, int*q)
{
	q = new int[4]; // DYNAMICALLY ALLOCATING MEMORY USING POINTERS


	for (int i = 0; i<4; i++)
	{
		q[i] = 4;

	}

	for (int i = 0; i<4; i++)
	{
		b[i] = q[i];
	}

	delete[] q;
	q = NULL;   // DE-ALLOCATING / ERASING THE  DYNAMICALLY RESERVED MEMORY	


}


void booksdetails(string *book)
{

	book[0] = " BOOK 1  :  Desires \n  IBAN  :  12 \n PRICE  :  2300  \n Author :  Parizad  \n PUBLISHING YEAR : 2011  \n EDITION : 5th  \n QUANTITY OF BOOK : ";
	book[1] = " BOOK 2  :  A ROAD TO SUCESS  \n  IBAN  :  22 \n PRICE  :  7300  \n Author :  Hamza  \n PUBLISHING YEAR : 1011  \n EDITION : 6th  \n QUANTITY OF BOOK : ";
	book[2] = " BOOK 3  :  FAILURE  \n  IBAN  :  34 \n PRICE  :  5300  \n Author :  Mansoor Ali  \n PUBLISHING YEAR : 2010  \n EDITION : 4th  \n QUANTITY OF BOOK : ";
	book[3] = " BOOK 4  :  LOVE  \n  IBAN  :  1322 \n PRICE  :  9300  \n Author :  Mubbashra Anwar  \n PUBLISHING YEAR : 2021  \n EDITION :13th  \n QUANTITY OF BOOK : ";

}

void booksibanumber(int ib[], int*z)  // using pointer for dynamic memory allocation 
{

	z = new int[4];
	for (int i = 0; i<4; i++)
	{
		if (i == 0)
		{
			z[i] = 12;
		}

		if (i == 1)
		{
			z[i] = 22;
		}

		if (i == 2)
		{
			z[i] = 34;
		}

		if (i == 3)
		{
			z[i] = 1322;
		}

	}

	for (int i = 0; i<4; i++)

	{
		ib[i] = z[i];
	}


	delete[] z;   //DEALLOCATING THE HEAP / DYNAMIC MEMORY
	z = NULL;

}


void issuingbook(int inputiban, int inputcopy, int *quantitybooks, string si, string ssi, string sssi, string tti, string ttti, int *numberibans)
{

	ofstream studentrec;
	studentrec.open("Student records.txt", ios::app);

	ofstream teacherrec;
	teacherrec.open("Teacher records.txt", ios::app);

	cout << " IBAN NUMBERS OF BOOKS ARE BELOW " << endl << endl;
	cout << " BOOK 1 (DESIRES) : 12 \n BOOK 2 (A ROAD TO SUCCESS): 22 \n BOOK 3 (FAILURE): 34 \n BOOK 4 (LOVE) : 1322 " << endl << endl;

	cout << endl << endl << " YOU CAN ONLY ISSUE 3 COPIES OF A SINGLE BOOK AT A SINGLE TIME! " << endl;

	cout << endl << endl << endl;


	cout << " ENTER IBAN NUMBER OF A BOOK TO ISSUE :  ";
	cin >> inputiban;

	while (inputiban != numberibans[0] && inputiban != numberibans[1] && inputiban != numberibans[2] && inputiban != numberibans[3])
	{
		cout << "INVALID IBAN NUMBER! \n\n RE-ENTER IBAN NUMBER : ";
		cin >> inputiban;
	}



	cout << " ENTER NUMBER OF COPIES YOU WANT TO ISSUE : ";
	cin >> inputcopy;

	while (inputcopy>3)
	{

		cout << endl << endl << " YOU CAN ONLY ISSUE 3 COPIES OF SINGLE BOOK AT A TIME.";
		cout << endl << "RE-ENTER COPIES OF BOOK : ";
		cin >> inputcopy;


	}



	if (inputiban == 12 && quantitybooks[0] == 0)
	{
		cout << " YOU CANNOT ISSUE THIS BOOK BECAUSE IT QUANTITY IS ZERO " << endl;
		cout << " CHOOSE ANY OTHER BOOK OR OPTION FROM MENU " << endl;
	}

	if (inputiban == 12 && quantitybooks[0] > 0)
	{


		while (quantitybooks[0] == 1 && inputcopy > 1 || quantitybooks[0] == 2 && inputcopy > 2 || quantitybooks[0] == 3 && inputcopy > 3 || quantitybooks[0] == 4 && inputcopy > 4)
		{

			cout << " THE QUANTITY OF BOOK IS : " << quantitybooks[0] << endl << "  YOU CANNOT ISSUE : " << inputcopy << " COPIES " << endl;
			cout << " RE-ENTER COPIES YOU WANT TO ISSUE : ";
			cin >> inputcopy;
		}

		cout << endl << " THE " << inputcopy << " ";
		cout << "COPIES OF BOOK  1 : (DESIRES) has been issued to the user below.\n";

		if (si == sssi || si == ssi) // AGAR STUDENT
		{
			studentrec << " -THE " << inputcopy << " COPIES OF BOOK  1  (DESIRES) has been issued to the user .\n ";
		}

		if (si == tti || si == ttti)// agar person type teacher hai then this will execute
		{
			teacherrec << " -THE " << inputcopy << " COPIES OF BOOK  1  (DESIRES) has been issued to the user .\n ";
		}



		quantitybooks[0] = quantitybooks[0] - inputcopy;
		cout << endl << endl << " NUMBER OF COPIES LEFT OF THIS BOOK = " << quantitybooks[0];


	}


	if (inputiban == 22 && quantitybooks[1] == 0)
	{
		cout << " YOU CANNOT ISSUE THIS BOOK BECAUSE IT QUANTITY IS ZERO " << endl;
		cout << " CHOOSE ANY OTHER BOOK OR OPTION FROM MENU " << endl;
	}


	if (inputiban == 22 && quantitybooks[1] > 0)
	{
		while (quantitybooks[1] == 1 && inputcopy > 1 || quantitybooks[1] == 2 && inputcopy > 2 || quantitybooks[1] == 3 && inputcopy > 3 || quantitybooks[1] == 4 && inputcopy > 4)

		{

			cout << " THE QUANTITY OF BOOK IS : " << quantitybooks[1] << endl << "  YOU CANNOT ISSUE : " << inputcopy << " COPIES " << endl;
			cout << " RE-ENTER COPIES YOU WANT TO ISSUE : ";
			cin >> inputcopy;
		}


		cout << endl << " THE " << inputcopy << " ";
		cout << "COPIES OF BOOK  2  (A ROAD TO SUCCESS) has been issued to to the user .\n";

		if (si == sssi || si == ssi) // AGAR STUDENT/student type kre

		{
			studentrec << " -THE " << inputcopy << " COPIES OF BOOK  2 (A ROAD TO SUCCESS) has been issued to to the user .\n";
		}

		if (si == tti || si == ttti)// agar teacher hai 
		{
			teacherrec << " -THE " << inputcopy << " COPIES OF BOOK  2 (A ROAD TO SUCCESS) has been issued to to the user .\n";
		}



		quantitybooks[1] = quantitybooks[1] - inputcopy;
		cout << endl << endl << " NUMBER OF COPIES LEFT OF THIS BOOK = " << quantitybooks[1];

	}

	if (inputiban == 34 && quantitybooks[2] == 0)
	{
		cout << " YOU CANNOT ISSUE THIS BOOK BECAUSE IT QUANTITY IS ZERO " << endl;
		cout << " CHOOSE ANY OTHER BOOK OR OPTION FROM MENU " << endl;
	}

	if (inputiban == 34 && quantitybooks[2] > 0)
	{

		while (quantitybooks[2] == 1 && inputcopy > 1 || quantitybooks[2] == 2 && inputcopy > 2 || quantitybooks[2] == 3 && inputcopy > 3 || quantitybooks[2] == 4 && inputcopy > 4)
		{

			cout << " THE QUANTITY OF BOOK IS : " << quantitybooks[2] << endl << "  YOU CANNOT ISSUE : " << inputcopy << " COPIES " << endl;
			cout << " RE-ENTER COPIES YOU WANT TO ISSUE : ";
			cin >> inputcopy;
		}

		cout << endl << " THE " << inputcopy << " ";
		cout << "COPIES OF BOOK  3 (FAILURE) has been issued to the user .\n";

		if (si == sssi || si == ssi) // AGAR STUDENT/

		{
			studentrec << " -THE " << inputcopy << " COPIES OF BOOK  3 (FAILURE) has been issued to the user .\n";
		}

		if (si == tti || si == ttti)// agar teacher hai 
		{
			teacherrec << " -THE " << inputcopy << " COPIES OF BOOK  3 (FAILURE) has been issued to the user .\n";
		}

		quantitybooks[2] = quantitybooks[2] - inputcopy;
		cout << endl << endl << " NUMBER OF COPIES LEFT OF THIS BOOK = " << quantitybooks[2];

	}

	if (inputiban == 1322 && quantitybooks[3] == 0)

	{
		cout << " YOU CANNOT ISSUE THIS BOOK BECAUSE IT QUANTITY IS ZERO " << endl;
		cout << " CHOOSE ANY OTHER BOOK OR OPTION FROM MENU " << endl;
	}


	if (inputiban == 1322 && quantitybooks[3] > 0)
	{

		while (quantitybooks[3] == 1 && inputcopy > 1 || quantitybooks[3] == 2 && inputcopy > 2 || quantitybooks[3] == 3 && inputcopy > 3 || quantitybooks[3] == 4 && inputcopy > 4)
		{

			cout << " THE QUANTITY OF BOOK IS : " << quantitybooks[3] << endl << "  YOU CANNOT ISSUE : " << inputcopy << " COPIES " << endl;
			cout << " RE-ENTER COPIES YOU WANT TO ISSUE : ";
			cin >> inputcopy;
		}


		cout << endl << " THE " << inputcopy << " ";
		cout << " COPIES OF BOOK  4  (LOVE) has been issued to the user below.\n";

		if (si == sssi || si == ssi) // AGAR STUDENT/

		{
			studentrec << " -THE " << inputcopy << " COPIES OF BOOK  4 (LOVE) has been issued to the user .\n";
		}

		if (si == tti || si == ttti)// agar teacher hai 
		{
			teacherrec << " -THE " << inputcopy << " COPIES OF BOOK  4 (LOVE) has been issued to the user .\n";
		}


		quantitybooks[3] = quantitybooks[3] - inputcopy;
		cout << endl << endl << " NUMBER OF COPIES LEFT OF THIS BOOK = " << quantitybooks[3];

	}


	studentrec.close();
	teacherrec.close();

}

void checkbookdetails(int userinput, int *booksiban, int *bookskiquantity, string *detailsofbooks)
{
	cout << " IBAN NUMBERS OF BOOKS ARE BELOW " << endl << endl;
	cout << " BOOK 1 (DESIRES) : 12 \n BOOK 2 (A ROAD TO SUCCESS): 22 \n BOOK 3 (FAILURE): 34 \n BOOK 4 (LOVE) : 1322 " << endl << endl;
	cout << endl << endl << " ENTER IBAN NUMBER OF A BOOK TO CHECK ITS FULL DETAILS : ";
	cin >> userinput;

	for (int i = 0; i<4; i++)
	{

		if (userinput == booksiban[i])
		{
			cout << endl << endl << detailsofbooks[i] << bookskiquantity[i] << endl << endl;
		}

	}
	cout << endl << endl << endl;


}

void returningbook(int iban_foreturn, int return_copies, string sh, string ssh, string sssh, string tth, string ttth, int *ibano, int *qob) //qob = quantity of books
{
	ofstream recordofstudent;
	recordofstudent.open("Student records.txt", ios::app);

	ofstream   recordofteacher;
	recordofteacher.open("Teacher records.txt", ios::app);



	cout << " ENTER IBAN NUMBER OF THE BOOK YOU WANT TO RETURN :";
	cin >> iban_foreturn;

	while (iban_foreturn != ibano[0] && iban_foreturn != ibano[1] && iban_foreturn != ibano[2] && iban_foreturn != ibano[3])
	{
		cout << "INVALID IBAN NUMBER! \n\n RE-ENTER IBAN NUMBER : ";
		cin >> iban_foreturn;
	}

	cout << " ENTER NUMBER OF COPIES YOU WANT TO RETURN :";

	cin >> return_copies;

	while (return_copies>3)
	{
		cout << endl << endl << " INVALID INPUT YOU CANNOT ISSUE OR RETURN MORE THAN 3 COPIES." << endl;
		cout << " RE-ENTER NUMBER OF COPIES YOU WANT TO RETURN : ";

		cin >> return_copies;
	}



	if (iban_foreturn == ibano[0] && return_copies > 0)
	{

		while (qob[0] == 1 && return_copies > 3 || qob[0] == 2 && return_copies > 2 || qob[0] == 3 && return_copies > 1 || qob[0] == 4 && return_copies > 0)

		{
			cout << " YOU CANNOT RETURN MORE COPIES THAN ISSUED IN ACTUAL !" << endl;
			cout << " RE-ENTER THE COPIES YOU WANT TO RETURN :  ";
			cin >> return_copies;

		}


		cout << endl << endl << " COPIES OF BOOKS BEFORE RETURNING :  ";
		cout << qob[0];
		cout << endl << endl << " COPIES OF BOOKS AFTER RETURNING :  ";
		qob[0] = qob[0] + return_copies;
		cout << qob[0];

		cout << endl << " BOOKS RETURNED = " << return_copies;

		cout << endl << endl << " NUMBER OF COPIES AVAILABLE OF THIS BOOK = " << qob[0];

		if (sh == sssh || sh == ssh)
		{
			recordofstudent << endl << " -THE " << return_copies << " COPIES OF (DESIRE) BOOK HAS RETURNED BY STUDENT." << endl;


		}

		if (sh == tth || sh == ttth)// agar person type teacher hai then this will execute
		{

			recordofteacher << endl << " -THE " << return_copies << " COPIES OF (DESIRE) BOOK HAS RETURNED BY TEACHER . " << endl;


		}

	}

	if (iban_foreturn == ibano[1] && return_copies > 0)
	{


		while (qob[1] == 1 && return_copies > 3 || qob[1] == 2 && return_copies > 2 || qob[1] == 3 && return_copies > 1 || qob[1] == 4 && return_copies > 0)

		{
			cout << " YOU CANNOT RETURN MORE COPIES THAN ISSUED IN ACTUAL !" << endl;
			cout << " RE-ENTER THE COPIES YOU WANT TO RETURN :  ";
			cin >> return_copies;

		}
		cout << endl << endl << " COPIES OF BOOKS BEFORE RETURNING :  ";
		cout << qob[1];
		cout << endl << endl << " COPIES OF BOOKS AFTER RETURNING :  ";
		qob[1] = qob[1] + return_copies;
		cout << qob[1] << endl;


		cout << endl << " BOOKS RETURNED = " << return_copies;

		cout << endl << endl << " NUMBER OF COPIES AVAILABLE OF THIS BOOK = " << qob[1] << endl;

		if (sh == sssh || sh == ssh)
		{
			recordofstudent << endl << " -THE " << return_copies << " COPIES OF (A ROAD TO SUCCESS) BOOK HAS RETURNED BY STUDENT ." << endl;

		}

		if (sh == tth || sh == ttth)// agar person type teacher hai then this will execute
		{

			recordofteacher << endl << " -THE " << return_copies << " COPIES OF (A ROAD TO SUCCESS) BOOK RETURNED BY TEACHER . " << endl;

		}


	}
	if (iban_foreturn == ibano[2] && return_copies > 0)
	{

		while (qob[2] == 1 && return_copies > 3 || qob[2] == 2 && return_copies > 2 || qob[2] == 3 && return_copies > 1 || qob[2] == 4 && return_copies > 0)

		{
			cout << " YOU CANNOT RETURN MORE COPIES THAN ISSUED IN ACTUAL !" << endl;
			cout << " RE-ENTER THE COPIES YOU WANT TO RETURN :  ";
			cin >> return_copies;

		}
		cout << endl << endl << " COPIES OF BOOKS BEFORE RETURNING :  ";
		cout << qob[2];
		cout << endl << endl << " COPIES OF BOOKS AFTER RETURNING :  ";
		qob[2] = qob[2] + return_copies;
		cout << qob[2] << endl;

		cout << endl << endl << " NUMBER OF COPIES AVAILABLE OF THIS BOOK = " << qob[2] << endl;


		if (sh == sssh || sh == ssh)
		{
			recordofstudent << endl << " -THE " << return_copies << " COPIES OF (FAILURE) BOOK RETURNED BY STUDENT ." << endl;

		}

		if (sh == tth || sh == ttth)// agar person type teacher hai then this will execute
		{

			recordofteacher << endl << " -THE " << return_copies << " COPIES OF (FAILURE) BOOK RETURNED BY TEACHER ." << endl;

		}


	}
	if (iban_foreturn == ibano[3] && return_copies > 0)
	{

		while (qob[3] == 1 && return_copies > 3 || qob[3] == 2 && return_copies > 2 || qob[3] == 3 && return_copies > 1 || qob[3] == 4 && return_copies > 0)

		{
			cout << " YOU CANNOT RETURN MORE COPIES THAN ISSUED IN ACTUAL !" << endl;
			cout << " RE-ENTER THE COPIES YOU WANT TO RETURN :  ";
			cin >> return_copies;

		}

		cout << endl << endl << " COPIES OF BOOKS BEFORE RETURNING :  ";
		cout << qob[3];
		cout << endl << endl << " COPIES OF BOOKS AFTER RETURNING :  ";
		qob[3] = qob[3] + return_copies;
		cout << qob[3] << endl;

		cout << endl << endl << " NUMBER OF COPIES AVAILABLE OF THIS BOOK = " << qob[3] << endl;

		if (sh == sssh || sh == ssh)
		{

			recordofstudent << endl << " -THE " << return_copies << " COPIES OF (LOVE) BOOK RETURNED BY STUDENT . " << endl;

		}

		if (sh == tth || sh == ttth)// agar person type teacher hai then this will execute
		{

			recordofteacher << endl << " -THE " << return_copies << " COPIES OF (LOVE) BOOK RETURNED BY TEACHER . " << endl;




		}




	}


}

