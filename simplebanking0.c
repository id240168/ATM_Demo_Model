


// This code has been created by Darol. Awei && help of a my colleague Elias.John. 

//Also, The Loan function has been created.






#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <math.h>  




// Can't install conio.h header file for masking, so i extract getch() out!!


int getch() {
    int ch;
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know 
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    ch = getchar();
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
}





void main_Menu_Switch_board(int option, int balance);

void checkBalance(int balance, char* text);
void deposit(int balance, int depositAmount);
void withdrawl(int balance, int withdrawlAmount);
void fundTransfer(int balance, int transferAmount);
void anotherTransection(int balance);
void thankYouMessage(void);
void bankingAmountoption_Menu(int balance, char* text1, char* text2);
void transectionAmount_options(int balance, char* text);
void bankingoperation_switch(int balance, int transcetionAmount, char* text);
void insufficientFund(int balance);
void bankCompanies_Menu(int balance);
void bankCompanies_switch(int balance);
void serviceProvider_Menu(int balance);
void serviceProvider_Switch(int balance);
void topUpTransections(int balance, int topUpAmount);
void topUpAmount_Menu(int balance, char* text);
void topUpAmount_Options(int balance, char* text);

void LoanApplied(int balance, double principal);

void TermsandCondition(int balance);
void Loan(int balance);
void Terms();



  void TermsandCondition(int balance)

  {

  char answer = get_char("\nDo you agree with our Terms and Condition Y/N: ");
  if (answer == 'y' || answer == 'Y')
  {
    system("clear");
    Loan(balance);
   

  }
  else if( answer == 'n' || answer == 'N')
  {
    
    system("clear");
    //printf("Thank you for using our Loan service.");
    anotherTransection(balance);

  }
  else
  {
    printf("\nInvalid input!!");
    printf("\n");
    TermsandCondition(balance);


  }

   }






   void Loan(int balance)
{

double principal = get_double("Enter Loan Amount: ");




if(1000 <= principal && principal <= 50000)
{


  // Annual rate of interest 
  double rate = 5;  
  
  // Time 
  double time = 2;  
  
  // Calculating compound Interest 
  double Amount = principal *  
                  ((pow((1 + rate / 100),  
                    time))); 
  double Payment = (Amount - principal) + principal; 
   
  printf("You have been approved a loan of : K%0.5lf, you are expected to repay K%0.5lf", principal, Payment); 
  LoanApplied(balance, principal);
  anotherTransection(balance);

}

else if(principal > 50000 && principal <= 100000)
{

       // Annual rate of interest 
  double rate = 8;  
  
  // Time 
  double time = 5;  
  
  // Calculating compound Interest 
  double Amount = principal *  
                  ((pow((1 + rate / 100),  
                    time))); 
  double Payment = (Amount - principal) + principal; 
   
  printf("You have been approved a loan of : K%0.5lf, you are expected to pay K%0.5lf", principal, Payment); 
  anotherTransection(balance);






}

else{

  printf("Invalid Loan Amount Apply.");
  printf("\n");
  Loan(balance);
}



}





void Terms()
{

  printf("\n *********************************** TERMS AND CONDITION APPLY ************************************************** ");
  printf("\n*                                                                                                                 *");
  printf("\n*          In order for you to apply for the loan you must agree with our Terms and Condition                     *");
  printf("\n*                                                                                                                 *");
  printf("\n* Maximum loan to apply is K100,000.00 and Minimum is K1000.00                                                    *");
  printf("\n* Loan applied from the range of K1000 to K50,000 will have to pay within 2 years with a annual rate of 5 percent *");
  printf("\n* Loan applied from the range of K50,000 to K100,000 will have to pay within 5 years with annual rate of 8 percent*");
  printf("\n*                                                                                                                 *");
  printf("\n");




}




void main_Menu(int balance){

printf("***************************************************\n");
printf("\n");
printf("******         WELCOME TO DIWAI BANK     **********\n");
printf("\n");
printf("******               MAIN MENU           **********\n");
printf("\n");
printf("***************************************************\n");
printf("\n");
printf(" * 1. Check Balance            5. Top Up           *\n");
printf(" * 2. Deposit                  6. Ezy Pay          *\n");
printf(" * 3. Withdrawl                7. Loan             *\n");
printf(" * 4. Fund Transfer            8. Exist            *\n");
printf("\n");
printf("****************************************************\n");

printf("\n");

int option = get_int("Enter Option:  ");
main_Menu_Switch_board(option, balance);
}

void checkBalance(int balance, char* text)
{
	printf("%s Balance: K%i\n", text,balance);
	anotherTransection(balance);
}

void deposit(int balance, int depositAmount)
{

	     balance = balance + depositAmount;
         printf("You have succesfully deposited K%i\n",depositAmount);
         checkBalance(balance,"New");
      
}

void withdrawl(int balance, int withdrawlAmount)
{
	if(balance < withdrawlAmount)
	{
		insufficientFund(balance);

	}
	else
	{
	      balance = balance - withdrawlAmount;
          printf("You have withdrawn K%i\n", withdrawlAmount);
          checkBalance(balance,"New");

	}    
         

}

void fundTransfer(int balance, int transferAmount)
{


	if(balance < transferAmount)
	{
		insufficientFund(balance);

	}
	else
	{

	    int accountNumber = get_int("Enter Acc#: ");
        balance = balance - transferAmount;	
        printf("\nYou have succesfully transfered K%i to Acc#: %i\n", transferAmount, accountNumber);
        checkBalance(balance,"New");
	  

	}

     
       

}

void LoanApplied(int balance, double principal)
{


	     balance = balance + principal;
         printf("\n");
         checkBalance(balance,"New");


}






void bankCompanies_Menu(int balance) 
{


    printf(" **************************************\n");
    printf(" *         Transfer To                *\n");
    printf(" **************************************\n");
    printf(" *   1. BSP          4. Kina          *\n");
    printf(" *   2. ANZ          5. Wespac        *\n");
    printf(" *   3. Diwai        6. Mibank        *\n");
    printf(" *                                    *\n");
    printf(" *   7. Back         8. Exit          *\n");
    printf(" *                                    *\n");
    printf(" **************************************\n");

    bankCompanies_switch(balance);


}


void bankCompanies_switch(int balance)
{
	char* text = "";
	int option = get_int("Enter Option: ");

	if(option == 1){
		text = "  BSP ";
	}
	else if(option == 2){
		text = "  ANZ ";
	}
	else if(option == 3){
		text = " Diwai";
	}
	else if(option == 4){
		text = " Kina ";
	}
	else if(option == 5){
		text = "Wespec";
	}
	else if(option == 6){
		text = "Mibank";
	}
	else if(option == 7){
		//system("clear");
		main_Menu(balance);
	}
	else if(option == 8){
		thankYouMessage();
	}
	else{

		printf("Error! Enter correct option");

	}

	system("clear");

	
	bankingAmountoption_Menu(balance, text, "Transfer");
}






void serviceProvider_Menu(int balance){


	printf(" ************************************* \n");
	printf(" *        Service Providers           *\n");
	printf(" **************************************\n");
	printf(" *   1. Digicel      3. Voda-Phone    *\n");
	printf(" *   2. B-mobile     4. Telikom       *\n");
	printf(" *                                    *\n");
	printf(" *   5. Back         6. Exit          *\n");
	printf(" *                                    *\n");
	printf(" **************************************\n");

	
	serviceProvider_Switch(balance);

}


void serviceProvider_Switch(int balance){


	char* text = "";
	int option = get_int("Enter Option: ");


	system("clear");

	if(option == 1){

		text = "Digicel ";
	}
	else if(option == 2){
		text = "B-mobile";
	}
	else if(option == 3){
		text = "VodaPhne";
	}
	else if(option == 4){
		text = "Telikom ";
	}
	else if(option == 5){
		main_Menu(balance);
	}
	else if(option == 6){
		thankYouMessage();
	}
	else{

		printf("Incorrect Input");
		serviceProvider_Menu(balance);


		
	}

	topUpAmount_Menu(balance, text);
	


}





void topUpAmount_Menu(int balance, char* text){
	printf(" **************************************\n");
	printf(" *           %s  TopUp           *\n", text);
	printf(" **************************************\n");
	printf(" *   1. K3           4. K20           *\n");
	printf(" *   2. K5           5. K50           *\n");
	printf(" *   3. K10          6. Other         *\n");
	printf(" *                                    *\n");
	printf(" *   7. Back         8. Exit          *\n");
	printf(" *                                    *\n");
	printf(" **************************************\n");
	

	topUpAmount_Options(balance,text);

}

void topUpAmount_Options(int balance, char* text){

	int topUpAmount = 0;
   int option = get_int(" Enter Option: ");

	if(option == 1){
		topUpAmount = 3;
	}
	else if(option == 2){
		topUpAmount  = 5;
	}
	else if(option == 3){
		topUpAmount  = 10;
	}
	else if(option == 4){
		topUpAmount  = 20;
	}
	else if(option == 5){
		topUpAmount  = 50;
	}

	else if(option == 6){

		topUpAmount = get_int(" Enter TopUp Amount:");
	}
		
	

	else if(option == 7){

		serviceProvider_Menu(balance);

	}
	
		
	else if(option == 8){
		thankYouMessage();
	}

	else{
		system("clear");
		printf("            INVALID INPUT!\n");
		topUpAmount_Menu(balance, text);
	}
	
	system("clear");
	topUpTransections(balance, topUpAmount);


}




void topUpTransections(int balance, int topUpAmount)
{


	if(balance < topUpAmount)
	{
		insufficientFund(balance);
	}

	else{



		balance = balance - topUpAmount;
		printf("\nAmount TopUp:  K%i",topUpAmount);


		  srand(time(0));

    // Generate a random 12-digit number

	long long voucherNumber = 0;  
    for (int i = 0; i < 12; i++) {

       voucherNumber = voucherNumber * 10 + rand() % 10;

    }

    printf("\nYour Voucher number: %lld\n", voucherNumber);

    checkBalance(balance, "\nNew");

    


	} 


}










void bankingAmountoption_Menu(int balance, char* text1, char* text2)

{

printf("*******************************************\n");
printf("*****    %s %s Menu     *******\n", text1, text2);
printf("\n");
printf("******************************************\n");
printf("\n");
printf(" * 1. K20                     4. K200    *\n");
printf(" * 2. K50                     5. K500    *\n");
printf(" * 3. K100                    6. Other   *\n");
printf("**                                      **\n");
printf(" * 7. Back                    8. Exist   *\n");
printf("\n");
printf("******************************************\n");

//system("clear");
transectionAmount_options(balance,text2);


}
void transectionAmount_options(int balance, char* text)

{
int transcetionAmount = 0;
int choice = get_int(" Enter Option: ");
if(choice == 1)
{
	transcetionAmount = 20;


}
else if(choice == 2)
{
	transcetionAmount = 50;

}
else if(choice == 3)
{
	transcetionAmount = 100;
	
}
else if(choice == 4)
{
	transcetionAmount = 200;
	
}
else if(choice == 5)
{
	transcetionAmount = 500;
	
}
else if(choice == 6)
{
   transcetionAmount = get_int("Enter %s  Amount : ", text);
	
}
else if(choice == 7)
{
	main_Menu(balance);
	
}
else if(choice == 8)
{
	thankYouMessage();
	
}
else
{
	printf(" incorrect option please enter integer");

}
system("clear");
bankingoperation_switch(balance, transcetionAmount, text);




}

void bankingoperation_switch(int balance, int transcetionAmount, char* text)
{
	if(strcmp(text, "Deposit") == 0)
	{
		deposit(balance, transcetionAmount);


	}
	else if(strcmp(text, "Withdrawl") == 0)
	{
		withdrawl(balance, transcetionAmount);

	}
	else if(strcmp(text, "Transfer") == 0)
	{
		fundTransfer(balance, transcetionAmount);

	}
	else
	{
		printf("Incorrect option\n");
	}

}



void anotherTransection(int balance)
{
	char answer = get_char("\nWould you like to perform\nanother transection:  ");
	if (answer == 'y' || answer == 'Y')
	{
		system("clear");
		main_Menu(balance);

	}
	else if( answer == 'n' || answer == 'N')
	{
		thankYouMessage();

	}
	else
	{
		printf("Invalid input!!");

	}

}



void insufficientFund(int balance)
{
	printf("\n WARNING: You have insufficient fund in your");
	printf("account. Please contact our nearest");
	printf("branch.\n");
	anotherTransection(balance);

}





void thankYouMessage(void)
{
printf("\n");
printf("************************************************\n");
printf("\n");
printf("********        Thank you for doing      ********\n");
printf("\n");
printf("******         business with us          ********\n");
printf("\n");
printf("*************************************************\n");
exit(0);



}


void main_Menu_Switch_board(int option, int balance){
	
	switch(option){
		case 1:
		  	checkBalance(balance, "current");
		  break; 
		case 2:
			system("clear");
			bankingAmountoption_Menu(balance, "Diwai", "Deposit");
		        
		  break;
		case 3:
			system("clear");
			bankingAmountoption_Menu(balance, "Diwai", "Withdrawl");
			
		 
		  break;
		case 4:
			system("clear");
			bankCompanies_Menu(balance);
		  
		  break;
		case 5:
		  system("clear");
		  serviceProvider_Menu(balance);

		  break;
		case 6:
		  printf("6");
		case 7:
		  system("clear");
		  Terms(); 
          TermsandCondition(balance);
		case 8:
		  thankYouMessage();

		  break;  
		default:
		printf("default");




		}

	}




int main(int argc, char* argv[]){

	int balance = 1000;


	//Creating password

	 char pin[100];
    int i = 0;
    int ch;
    int attempts = 0;

    printf("Enter PIN: ");
    while ((ch = getch()) != '\n') {
        if (ch == 127 || ch == 8) { // handle backspace
            if (i != 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pin[i++] = ch;
            // echo the '*' to get feel of taking password 
            printf("*");
        }
    }

    pin[i] = '\0';

    while(strcmp(pin, "1234") != 0 && attempts < 3 -1) { // Setting the pin for only 3 attampt.

        attempts++;
        if (attempts < 3) {

            printf("\nInvalid PIN. Please try again.\n");
            
        }
        i = 0;

        printf("Enter PIN: ");
        while ((ch = getch()) != '\n') {
            if (ch == 127 || ch == 8) { // handle backspace
                if (i != 0) {
                    i--;
                    printf("\b \b");
                }
            } else {
                pin[i++] = ch;
                printf("*");
            }
        }
        pin[i] = '\0';
    }

    if (strcmp(pin, "1234") == 0) {

    	system("clear");

        main_Menu(balance); // calling the main_Menu function


    } else {
        printf("\nYou have reached the maximum number of attempt.  \n");
        printf("\nYour card is locked for security measures");
        printf("\nCall our agent +675 71111 4444 or visit our nearest servise to activate your Card.");
        

    }



	return 0;

}
