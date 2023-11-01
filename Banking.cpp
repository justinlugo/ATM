#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 123.71;
    int choice = 0;

    std::cout << "****** ATM ******\n";
    do
    {
        std::cout << "Choose from the options below:\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch(choice)
        {
            // Show Balance
            case 1:
                showBalance(balance);
                break;
            // Deposit Money
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            // Withdraw Money
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            // Exit
            case 4:
                std::cout << "Thanks for visiting, come again!\n";
                break;
            // Invalid Option
            default:
                std::cout << "Invalid option, try again.\n";
                break;
        }
    }while(choice != 4);

    return 0;
}

void showBalance(double balance)
{
    std::cout << "Your balance is: $"  << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit()
{
    double amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        std::cout << "Not a valid amount.\n";
        return 0;
    }
}

double withdraw(double balance)
{
    double amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    if (amount > balance)
    {
        std::cout << "Not enough funds to withdraw.\n";
        return 0;
    }
    else if (amount < 0)
    {
        std::cout << "Not a valid amount.\n";
        return 0;
    }
    else
    {
        return amount;
    }
}