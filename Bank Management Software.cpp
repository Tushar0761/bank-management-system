#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

// define colors
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"

using namespace std;

// class
class bankAcc
{
  string userName;
  int bankBalance;

public:
  static int numberOfAcc;
  static int number;
  int accNo;

  // Constructor
  bankAcc();
  bankAcc(string userName);

  // public methods to create acc
  void createAcc();
  void createAcc(string userName);

  // to print single acc details.
  string printName();
  void printAcc();

  // to print data table.
  void dataTable();
  // to deposit in account
  void depositAmt(int amount);
  // withdraw amount from account
  void withdraw(int amount);
  // check for enough balance or not
  bool hasBalance(int amount);
};
// static variables
int bankAcc::number = 0;
int bankAcc::numberOfAcc = 1000;
int counter = 0;

// global String
string notValid = "****************** Not valid Input ***********************";

// defining functions
void welcomeMsg();

void printTable(int numberOfAcc, bankAcc objList[]);
void astLine();
void blankLine();
void startApp(bankAcc accList[]);
void createBankAcc(bankAcc accList[]);

void withdraw(bankAcc accList[]);
void desopitInAcc(bankAcc accList[]);
void transferMoney(bankAcc accList[]);

bool notValidAcc(int accNo);

int validIntInput(char i);

int main()
{
  system("cls");
  welcomeMsg();
  cout << "Enter 1 to start application.";
  string start;
  cin >> start;
  system("cls");
  welcomeMsg();
  bankAcc accList[100];
  startApp(accList);
  return 0;
}

// declaring function

// Starting loop for main function.
void startApp(bankAcc accList[])
{
  char choice;
  while (1)
  {

    cout << endl
         << YELLOW_TEXT << "Choose Options..." << RESET_COLOR << endl
         << "0. Press " << RED_TEXT << "Q or 0" << RESET_COLOR << " for Exit." << endl
         << "1. Press " << CYAN_TEXT << "C or 1" << RESET_COLOR << " for Create Account." << endl
         << "2. Press " << CYAN_TEXT << "D or 2" << RESET_COLOR << " for Deposit in your Account." << endl
         << "3. Press " << CYAN_TEXT << "W or 3" << RESET_COLOR << " for Withdraw money from your Account." << endl
         << "4. Press " << CYAN_TEXT << "T or 4" << RESET_COLOR << " for Transfer money from your Account to other account." << endl
         << "5. Press " << CYAN_TEXT << "A or 5" << RESET_COLOR << " for print Table of all account present in bank." << endl
         << endl
         << RESET_COLOR
         << ">";
    cin >>
        choice;

    if (choice == 'q' || choice == 'Q' || choice == '0')
    {
      cout << endl
           << "===============" << endl
           << "Bye.";
      break;
    }

    if (choice == 'c' || choice == 'C' || choice == '1')
    {
      createBankAcc(accList);
    }
    else if (choice == 'd' || choice == 'D' || choice == '2')
    {
      desopitInAcc(accList);
    }
    else if (choice == 'w' || choice == 'W' || choice == '3')
    {
      withdraw(accList);
    }
    else if (choice == 't' || choice == 'T' || choice == '4')
    {
      transferMoney(accList);
    }
    else if (choice == 'A' || choice == 'a' || choice == '5')
    {
      printTable(bankAcc::number, accList);
    }
    else
    {
      cout << notValid;
    }
  }
}

// Create Bank Acc
void createBankAcc(bankAcc accList[])
{
  blankLine();
  cout << "Creating Bank Account for you. Please wait..." << endl
       << "Enter Your full Name :" << endl
       << ">";

  char userName[30];
  cin.getline(userName, 30);
  cin.getline(userName, 30);
  accList[counter].createAcc(userName);

  system("cls");

  cout << CYAN_TEXT;
  blankLine();
  cout << "... Account created for '" << GREEN_TEXT << userName << CYAN_TEXT << "' With account number :" << GREEN_TEXT << bankAcc::number + 1100 << endl
       << endl
       << YELLOW_TEXT << "Please remember your account number for future transaction : " << GREEN_TEXT << bankAcc::number + 1100;
  cout << RESET_COLOR;
  astLine();
  counter++;
}

// deposit in your acc
void desopitInAcc(bankAcc accList[])
{
  int accNumber;

  blankLine();
  cout << endl
       << "Enter '-1' to cancel operation..." << endl
       << "Enter Your four digit Account Number : ";

inputNumber:
  cout << endl
       << ">";
  accNumber = validIntInput('a');
  if (accNumber == -1)
  {
    cout << RED_TEXT << "Transaction cancelled." << endl;
    astLine();
    return;
  }

  accNumber -= 1101;
  if (notValidAcc(accNumber))
    goto inputNumber;

  cout << endl
       << "Enter amount to deposit: " << endl
       << ">";
  int amt = validIntInput('m');

  accList[accNumber].depositAmt(amt);

  // accList[accNumber].depositAmt
}

// withdraw from your acc.
void withdraw(bankAcc accList[])
{
  int accNumber;
  blankLine();

  cout << "Withdrawing From your Account... Please wait" << endl
       << "Enter Your four digit Account Number : ";

inputNumber:
  cout << endl
       << ">";
  accNumber = validIntInput('a');
  if (accNumber == -1)
  {
    cout << RED_TEXT << "Transaction cancelled." << endl;
    astLine();
    return;
  }

  accNumber -= 1101;
  if (notValidAcc(accNumber))
    goto inputNumber;

  cout << endl
       << "Enter amount to withdraw: " << endl
       << ">";

  int amt = validIntInput('m');

  accList[accNumber].withdraw(amt);
}
// transfer money from one account to another.
void transferMoney(bankAcc accList[])
{
  blankLine();
  int accFrom, accTO;

  cout << "Transferring From your Account... Please wait" << endl
       << "Enter Your four digit Account Number : ";

inputAcc1:
  cout << endl
       << ">";
  accFrom = validIntInput('a');
  if (accFrom == -1)
  {
    cout << RED_TEXT << "Transaction cancelled." << endl;
    astLine();
    return;
  }

  accFrom -= 1101;
  if (notValidAcc(accFrom))
    goto inputAcc1;

  cout << endl
       << "Enter Account number of account which you want to transfer your money : ";

inputAcc2:
  cout << endl
       << ">";
  accTO = validIntInput('a');
  if (accTO == -1)
  {
    cout << RED_TEXT << "Transaction cancelled." << endl;
    astLine();
    return;
  }

  accTO -= 1101;
  if (notValidAcc(accTO))
    goto inputAcc2;

  cout << endl
       << "Enter amount to Transfer: " << endl
       << ">";
  int amt = validIntInput('m');

  if (!accList[accFrom].hasBalance(amt))
  {

    cout << endl
         << RED_TEXT
         << "Not enough balance" << RESET_COLOR << endl;
    return;
  }

  accList[accFrom].withdraw(amt);
  accList[accTO].depositAmt(amt);
  system("cls");
  blankLine();
  cout << CYAN_TEXT << "Money Transferred from " << GREEN_TEXT << accList[accFrom].printName() << CYAN_TEXT << " to " << GREEN_TEXT << accList[accTO].printName() << CYAN_TEXT << endl
       << "Transferred Amount : " << GREEN_TEXT << amt << RESET_COLOR << endl;

  astLine();
}
// for checking valid acc in database
bool notValidAcc(int accNo)
{
  if (accNo >= 0 && accNo < 100 && accNo < counter)
  {
    return false;
  }
  cout << endl
       << YELLOW_TEXT
       << "Invalid account number. Enter '-1' to Terminate."
       << RESET_COLOR;
  return true;
}

// to check valid acc or amount
int validIntInput(char i)
{
  int input;

  string msg = i == 'a' ? "Invalid account number. " : "Invalid amount. ";
  while (!(cin >> input))
  {
    cout << endl
         << YELLOW_TEXT
         << msg << "Enter '-1' to Terminate." << endl
         << RESET_COLOR
         << ">";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return input;
}

// counstructer
bankAcc::bankAcc()
{
  numberOfAcc++;
  this->accNo = numberOfAcc;

  this->userName = "null";
  this->bankBalance = 0;
}
// constructor
bankAcc::bankAcc(string userName)
{
  numberOfAcc++;
  this->accNo = numberOfAcc;

  this->userName = userName;
  this->bankBalance = 0;
}
// only create acc with default
void bankAcc::createAcc()
{
  number++;
  numberOfAcc++;
  this->accNo = numberOfAcc;
  this->userName = "null";
  this->bankBalance = 0;
}

// create acc with username
void bankAcc::createAcc(string userName)
{
  number++;

  this->bankBalance = 0;
  numberOfAcc++;
  this->accNo = numberOfAcc;

  this->userName = userName;
}

// print blank line for design...
void blankLine()
{
  cout << endl
       << " ";

  for (int i = 0; i < 55; i++)
  {
    cout << "_";
  }
  cout << endl;
}
void astLine()
{
  cout << endl
       << " ";

  for (int i = 0; i < 55; i++)
  {
    cout << "*";
  }
  cout << endl;
}

// print table
void printTable(int numberOfAcc, bankAcc objList[])
{
  cout << GREEN_TEXT;
  blankLine();
  cout << "|" << setw(13) << "Acc No."
       << "| Name of Holder" << setw(26) << "| Balance.|";
  blankLine();
  cout << CYAN_TEXT << endl;

  for (int i = 0; i < numberOfAcc; i++)
  {
    objList[i].dataTable();
  }
  blankLine();
  cout << RESET_COLOR;
  astLine();
}

// print table type object
void bankAcc::dataTable()
{
  cout << "|" << setw(13) << this->accNo << "|" << setw(30) << this->userName << "|" << setw(9) << this->bankBalance << "|" << endl;
}

// print that object
void bankAcc::printAcc()
{
  cout << endl
       << "Account No. : " << this->accNo << endl
       << "Name of holder : " << this->userName << endl
       << "Balance. : " << this->bankBalance << endl;
}

string bankAcc::printName()
{
  return this->userName;
}

void welcomeMsg()
{
  cout << endl
       << endl
       << GREEN_TEXT << "Banking Management System ~ Project by : Tushar Panchal" << endl
       << CYAN_TEXT;
  astLine();
  cout
      << setw(35) << "Welcome to my bank" << endl;

  astLine();
  cout << CYAN_TEXT;
}
void bankAcc::depositAmt(int amount)
{
  system("cls");
  cout << CYAN_TEXT;

  blankLine();
  this->bankBalance += amount;
  cout << "Successfully deposit Rs." << GREEN_TEXT << amount << CYAN_TEXT << " to your account. " << endl;
  cout << RESET_COLOR;
  astLine();
}

void bankAcc::withdraw(int amount)
{
  blankLine();
  if (this->bankBalance < amount)
  {
    system("cls");

    cout << RED_TEXT << endl
         << "Not enough balance." << endl;
    astLine();
    cout << RESET_COLOR;

    return;
  }

  system("cls");
  cout << CYAN_TEXT;
  blankLine();

  this->bankBalance -= amount;
  cout << "Successfully withdraw Rs." << GREEN_TEXT << amount << CYAN_TEXT << " from your account." << endl
       << RESET_COLOR;
  astLine();
}
// check for enough balance
bool bankAcc::hasBalance(int amount)
{
  return this->bankBalance >= amount;
}