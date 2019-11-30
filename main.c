#include <stdio.h>
#include <stdlib.h>
#include "myBank.h"

int account_check(){
int account_number;
    do{
printf("\nEnter Number Account :");
scanf("%d",&account_number);

}while(account_number<901||account_number>950);

return account_number;
}

int main() {

    char transactionType;
    printf("\nSelect a porogrom from the list:");
    printf("\nO: Opening a bank account");
    printf("\nB: Account Balance");
    printf("\nD: Deposit");
    printf("\nW: Attraction");
    printf("\nC: Account Closing");
    printf("\nI: Add interest");
    printf("\nP: Print all accounts and balances");
    printf("\nE: Close all accounts and exit the program");
    printf("\nPlease enter your selection: ");

       char line[256];
    int account_number;
while(transactionType!='E'){
    
    if (fgets(line, sizeof line, stdin) == NULL) {
        printf("\nInput error.\n");
        exit(1);        
    }

    transactionType = line[0];
    printf("\nTransaction type?: %c\n", transactionType);

    switch(transactionType)
    {
        case 'O':
            O();
            break;
        case 'B':
        account_number=account_check();
           B(account_number);
            break;
        case 'D':
        account_number=account_check();
           D(account_number);
            break;
        case 'W':
        account_number=account_check();
           W(account_number);
            break;
        case 'C':
         account_number=account_check();
           C(account_number);
            break;
        case 'I':
            I();
            break;
        case 'P':
            P();
            break;
        case 'E':
            E();
            break;
        default:
        if (transactionType !='O' || transactionType !='B' || transactionType !='D' || transactionType !='W' 
        || transactionType !='C'|| transactionType !='I' || transactionType !='P' || transactionType !='E' ){
         printf("\nTry again\n");
    
        }      
    }
}
    return 0;
}