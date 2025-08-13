#include<stdio.h>
#include<stdlib.h>
int main()
{
    int pin=1234,enteredpin,attempts=0;
    float balance=1000.0,amount;
    int choice;
    while(attempts<3)
    {
        printf("Enter your 4digits pin:");
        scanf("%d",&enteredpin);
        if(enteredpin==pin)
        {
            printf("\nAccess granted");
            break;
        }
        else
        {
            attempts++;
            printf("Incorrect pin!Attempt left;%d\n",3-attempts);
        }
        if(attempts==3)
        {
            printf("\nCard Blocked");
            exit(0);
        }
    }
    do
    {
        printf("\nATM MENU\n");
        printf("You are under CCTV Survillance\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("5. Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Your current balance is: %.2f\n",balance);
            break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f",&amount);
                if(amount>0)
                {
                    balance+=amount;
                    printf("%.2f deposited successfully.\n",amount);
                }
                else
                {
                    printf("Invalid deposit amount!\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: \n");
                scanf("%f",&amount);
                if(amount>0&&amount<=balance)
                {
                    balance-=amount;
                    printf("%.2f Withdraw successfully.\n",amount);
                }
                else
                {
                    printf("Insufficient balance!\n");
                }
                break;
                case 4:
                printf("Thankyou visit again!\n");
                break;
                default:
                    printf("You are under CCTV Survillance\n");
        }
    }
    while(choice!=4);
    return 0;
}
