#include <stdio.h>
#include "myBank.h"

static double bank [SIZE_BANK][SIZE_INFO]={{0.0}};

void  O (){ //Opening a bank account

int temp_account=-1;
for (int i = 0; i < SIZE_BANK; i++){
    if(temp_account==-1){
        if(bank[i][0]==CLOSE){
        temp_account=i;
        bank[i][0]=OPEN;
        printf("\nWELCOME to the bank , your number account is %d",i+901);
        double ammout=0;
        printf("\nPlease enter ammount:");
        scanf("%lf",&ammout);
            if (ammout<0){
            printf("\nSorry , you don't input negative amount, a default ammout is 0");
         }else{
        bank[i][1]=ammout;
            }
        }
    }
}
    if(temp_account==-1){
    printf("\nSorry,All account is open !!");
    }
}


void B (int bankAccount){ //Account Balance

if (bank[bankAccount-901][0] ==OPEN){
 printf("\nYour balance in account %d is : %.2f",bankAccount,bank[bankAccount-901][1]);
    }else{
    printf("\nSorry, Your account is closed or don't exsit ");
}
}

void D (int bankAccount){ //Deposit

if (bank[bankAccount-901][0] ==OPEN){
double ammount=0;
printf("\nammount?");
scanf("%lf",&ammount);
    if (ammount>0){
    bank[bankAccount-901][1]= bank[bankAccount-901][1]+ammount;
    printf("\nYour new balance in account %d is : %.2f",bankAccount,bank[bankAccount-901][1]);
        }else {
    printf("\nSorry, You enter number negative to Deposit ");
}
}else{
    printf("\nSorry, Your account is closed or don't exsit ");
}
}

void W (int bankAccount){ //Attraction

if (bank[bankAccount-901][0] ==OPEN){
double ammount=0;
printf("\nammount?");
scanf("%lf",&ammount);
if (ammount>0 && (bank[bankAccount-901][1]-ammount)>=0){
    bank[bankAccount-901][1]= bank[bankAccount-901][1]-ammount;
 printf("\nYour new balance in account %d is : %.2f",bankAccount,bank[bankAccount-901][1]);
    }else {
    printf("\nSorry, You enter number negative to Deposit or your ammount is not suffisante ");
    }
}else{
    printf("\nSorry, Your account is closed or don't exsit ");
}
} 

void C (int bankAccount){ //Account Closing

if(bank[bankAccount-901][0]==OPEN){
bank[bankAccount-901][0]=CLOSE;
bank[bankAccount-901][1]=0.0;
printf("\nYour account %d is closed",bankAccount);
    
}else{
    printf("\nYour account is already closed or don't exist");
}
}

void I (){ //Add interest

double interest=0.0;
do{
printf("\nPlease; enter nmber interest to add in all account between 0 and 1 ");
scanf("%lf",&interest);

}while (interest>1|| interest<0);

for (int i = 0; i < SIZE_BANK; i++){
    if(bank[i][0]==OPEN){
        double temp_interret=bank[i][1]*interest;
        bank[i][1]=bank[i][1]+temp_interret;
    }
}
}

void P (){ //Print all accounts and balances
for (int i = 0; i < SIZE_BANK; i++){
    if (bank[i][0]==OPEN){
        printf("\nYour account %d have : %.2f ",i+901,bank[i][1]);
    }
}
}

void E (){ //Close all accounts and exit the program

for (int i = 0; i < SIZE_BANK; i++){
    if(bank[i][0]==OPEN){
    bank[i][0]=CLOSE;
    bank[i][1]=0.0;
printf("\n A Account %d is closed ",i+901);

}
}
printf("\nALL ACCOUNT IS CLOSED\n");
}