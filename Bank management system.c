#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
int exits;
struct date
{
    int mm,dd,yy;

};
struct
{
    int account_number,customer_age;
    char customer_name[60];
    char customer_address[60];
    char customer_NID_PASSPORT[15];
    int customer_phone;
    float customer_amount;
    struct date customer_dob;
    struct date customer_deposit;
    struct date customer_withdraw;

} adding,updating,deleted,checking,deposit,withdraw;

void fordelay(int y)
{
    int x,z;
    for(x=0; x<y; x++)
        z=x;
}

void main_winwods()
{
    int choice;

        printf("\n1. BANK Officer Control");
        printf("\n2. Customer Control");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            Officer_User_Pass();
            break;
        case 2:
            system("cls");
            customer_User_Pass();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nWrong entry!\n");
            fordelay(1000000000);
            break;
        }



}


void Officer_User_Pass()
{

    char user[15], pass[15];

    char officer[15]="officer",PassO[15]="officer";
    int x=0;
    printf("\n\nEnter the User Name of officer :");
    scanf("%s",user);
    printf("\n\nEnter the password of officer :");
    scanf("%s",pass);

    if (strcmp(user,officer)==0 && strcmp(pass,PassO)==0)
    {
        system("cls");
        Bank_officer_Control();
    }
    else
    {
        printf("\n\nWrong password!!!");
        printf("\nEnter 1 to try again and 0 to Menu:");
        scanf("%d",&exits);
        if (exits==1)
        {

            system("cls");
            Officer_User_Pass();
        }

        else if (exits==0)
        {
            system("cls");
            main_winwods();
            close();
        }
        else
        {
            printf("\nInvalid!");
            system("cls");
        }

    }
}
void customer_User_Pass()
{

    char user[15], pass[15];

    char customer[15]="customer",PassC[15]="customer";
    int x=0;
    printf("\n\nEnter the User Name of customer :");
    scanf("%s",user);
    printf("\n\nEnter the password of customer :");
    scanf("%s",pass);

    if (strcmp(user,customer)==0 && strcmp(pass,PassC)==0)
    {
        printf("\n\nPassword Match!\nLOADING");

        system("cls");
        Customer_Control();
    }
    else
    {
        printf("\n\nWrong password!!!");
        printf("\nEnter 1 to try again and 0 to Menu:");
        scanf("%d",&exits);
        if (exits==1)
        {

            system("cls");
            customer_User_Pass();
        }

        else if (exits==0)
        {

            system("cls");
            main_winwods();
            close();
        }
        else
        {
            printf("\nInvalid!");
            system("cls");
        }

    }
}

void Bank_officer_Control()
{
    int choice;
        printf("\n1. New Account");
        printf("\n2. Search The Account");
        printf("\n3. Update The Account");
        printf("\n4. View ALL The Customer Name");
        printf("\n5. Delete The Account");
        printf("\n6. Check Balance");
        printf("\n7. Money Deposit");
        printf("\n8. Money Withdraw");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            new_accounts();
            break;
        case 2:
            system("cls");
            search_The_Account();
            break;
        case 3:
            system("cls");
            update_The_Account();
            break;
        case 4:
            system("cls");
            view_ALL_The_Customer_Name();

            break;
        case 5:
            system("cls");
            delete_The_Account();
            break;
        case 6:
            system("cls");
            check_Balance();
            break;
        case 7:
            system("cls");
            money_Deposit();
            break;
        case 8:
            system("cls");
            money_Withdraw();
            break;
        case 9:
            system("cls");
            main_winwods();
            close();
            break;
        default:
 printf("\nWrong entry!\n");
            fordelay(1000000000);
            break;
        }



}
void Customer_Control()
{
    int choice;
    while(1)
    {
        printf("\n1. Check Balance");
        printf("\n2. Money Deposit");
        printf("\n3. Money Withdraw");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            check_Balance();
            break;
        case 2:
            system("cls");
            money_Deposit();
            break;
        case 3:
            system("cls");
            money_Withdraw();
            break;
        case 4:
            system("cls");
            main_winwods();
            close();
            break;
        default:
            break;
        }

    }

}
void   new_accounts()

{

    FILE *datafile;

    datafile=fopen("customerrecord.dat","a+");
Account_number:
    system("cls");
    printf(" ADD RECORD");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy);
    printf("\nEnter the account number:");
    scanf("%d",&checking.account_number);
    while(fscanf(datafile,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (checking.account_number==adding.account_number)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto Account_number;

        }
    }
    adding.account_number=checking.account_number;
    printf("\nEnter the name:");
    scanf("%s",adding.customer_name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy);
    printf("\nEnter the age:");
    scanf("%d",&adding.customer_age);
    printf("\nEnter the address:");
    scanf("%s",adding.customer_address);
    printf("\nEnter the NID or PASSPORT number:");
    scanf("%s",adding.customer_NID_PASSPORT);
    printf("\nEnter the phone number: ");
    scanf("%d",&adding.customer_phone);
    printf("\nEnter the amount to deposit:$ ");
    scanf("%f",&adding.customer_amount);

    fprintf(datafile,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);


    fclose(datafile);
    printf("\nAccount created successfully!");
add_invalid:
    printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&exits);
    system("cls");
    if (exits==1)
        Bank_officer_Control();
    else if(exits ==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }

}

void search_The_Account()
{

    FILE *searching;
    searching=fopen("customerrecord.dat","r");

    printf("\nEnter The account number :");
    scanf("%d",&checking.account_number);

    while(fscanf(searching,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number==checking.account_number)
        {

            printf("\nThe name: %s",adding.customer_name);

            printf("\nThe date of birth(mm/dd/yyyy) %d/%d/%d",adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy);

            printf("\nThe age: %d",adding.customer_age);

            printf("\nThe address: %s",adding.customer_address);

            printf("\nThe NID or PASSPORT number: %s",adding.customer_NID_PASSPORT);

            printf("\nThe phone number: %d",adding.customer_phone);

            printf("\nThe amount to deposit:$ %f",adding.customer_amount);
        }
        else
        {
            printf("\nSorry, No record found in the database");
        }
        fclose(searching);

searching:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)
            Bank_officer_Control();
        else if(exits==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto searching;
        }

    }

}
void update_The_Account(void)
{
    int choice,tst=0;
    FILE *oldinfo,*newinfo;
    oldinfo=fopen("customerrecord.dat","r");
    newinfo=fopen("recordupdated.dat","w");
    printf("\nEnter the account number :");
    scanf("%d",&updating.account_number);
    while(fscanf(oldinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number==updating.account_number)
        {
            tst=1;
            printf("\nOnly Change Address or Phone Number\n1.Address\n2.Phone\n3.Both\nEnter your Choice: ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Enter the new address :");
                scanf("%s",updating.customer_address);
                fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,updating.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

                printf("\nChanges successfully");
            }
            else if(choice==2)
            {
                printf("Enter the new phone number :");
                scanf("%d",&updating.customer_phone);
                fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,updating.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

                printf("\nChanges successfully");
            }

            else if(choice==3)
            {
                printf("\nEnter the new address :");
                scanf("%s",updating.customer_address);
                printf("\nEnter the new phone number :");
                scanf("%d",&updating.customer_phone);
                fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,updating.customer_address,adding.customer_NID_PASSPORT,updating.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

                printf("\nChanges successfully");
            }
        }
        else
        {
            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);
        }

        fclose(oldinfo);
        fclose(newinfo);
        remove("customerrecord.dat");
        rename("recordupdated.dat","customerrecord.dat");


        if(tst!=1)
        {
            system("cls");
            printf("\nRecord not found!");
updated:
            printf("\nEnter 1 To try again,2 officer control,0 to exits :");
            scanf("%d",&exits);
            system("cls");
            if (exits==1)

                update_The_Account();
            else if (exits==2)
                Bank_officer_Control();
            else if(exits==0)
                close();
            else

            {
                printf("\nInvalid!\a");
                goto updated;
            }
        }


        else
        {
            printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&exits);
            system("cls");
            if (exits==1)
                Bank_officer_Control();
            else
                close();

        }
    }

}
void view_ALL_The_Customer_Name()
{


    FILE *allcustomer;
    int find=0;
    allcustomer=fopen("customerrecord.dat","r");
    system("cls");
    printf("\nAccount numbert\t\t NAME\t\t\tAge\t\t\tADDRESS\t\tNID or PASSPORT\t\tPHONE\n");
    while(fscanf(allcustomer,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        printf("\n%d\t\t\t %s\t\t\t%d\t\t\t%s\t\t%s\t\t%d",adding.account_number,adding.customer_name,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone);
        find++;
    }

    fclose(allcustomer);
    if (find==0)
    {
        system("cls");
        printf("\nSorry, No record in the database!!\n");
    }
allcustomer:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&exits);
    system("cls");
    if (exits==1)
        Bank_officer_Control();
    else if(exits==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto allcustomer;
    }




}

void delete_The_Account()
{
    int tst=0;
    FILE *oldinfo,*newinfo;
    oldinfo=fopen("customerrecord.dat","r");
    newinfo=fopen("recordupdated.dat","w");
    printf("\nEnter the account number :");
    scanf("%d",&deleted.account_number);
    while(fscanf(oldinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number!=deleted.account_number)
        {

            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

        }
        else
        {
            tst++;
            printf("\nRecord deleted successfully!\n");

        }
    }
    fclose(oldinfo);
    fclose(newinfo);
    remove("customerrecord.dat");
    rename("recordupdated.dat","customerrecord.dat");


    if(tst==0)
    {
        system("cls");
        printf("\nRecord not found!");
deleted:
        printf("\nEnter 1 To try again,2 officer control,0 to exits :");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)

            delete_The_Account();
        else if (exits==2)
            Bank_officer_Control();
        else if(exits==0)
            close();
        else

        {
            printf("\nInvalid!\a");
            goto deleted;
        }
    }


    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)
            Bank_officer_Control();
        else
            close();

    }
}

void check_Balance()
{

    FILE *searching;
    searching=fopen("customerrecord.dat","r");

    printf("\nEnter The account number :");
    scanf("%d",&checking.account_number);

    while(fscanf(searching,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number==checking.account_number)
        {

            printf("\nBalance : %f",adding.customer_amount);

        }
        else
        {
            printf("\nSorry, You Have no Money Please Deposited");
        }
        fclose(searching);

searching:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)
            Customer_Control();
        else if(exits==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto searching;
        }

    }


}
void money_Deposit()
{



    int tst=0;
    FILE *oldinfo,*newinfo;
    oldinfo=fopen("customerrecord.dat","r");
    newinfo=fopen("recordupdated.dat","w");
    printf("\nEnter the account number :");
    scanf("%d",&deposit.account_number);
    while(fscanf(oldinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number==deposit.account_number)
        {
            tst=1;
            printf("Enter the amount you want to deposit :$ ");
            scanf("%f",&deposit.customer_amount);
            adding.customer_amount = adding.customer_amount + deposit.customer_amount;
            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);
            printf("\n\nDeposited successfully!");
            printf("\nBalance : %f",adding.customer_amount);
        }
        else
        {

            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

        }
    }
    fclose(oldinfo);
    fclose(newinfo);
    remove("customerrecord.dat");
    rename("recordupdated.dat","customerrecord.dat");


    if(tst!=1)
    {
        system("cls");
        printf("\nRecord not found!");
Deposited:
        printf("\nEnter 1 To try again,2 Menu,0 to exits :");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)

            money_Deposit();
        else if (exits==2)
            main_winwods();
        else if(exits==0)
            close();
        else

        {
            printf("\nInvalid!\a");
            goto Deposited;
        }
    }


    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)
            Customer_Control();
        else
            close();

    }
}

void money_Withdraw()
{

    int tst=0;
    FILE *oldinfo,*newinfo;
    oldinfo=fopen("customerrecord.dat","r");
    newinfo=fopen("recordupdated.dat","w");
    printf("\nEnter the account number :");
    scanf("%d",&withdraw.account_number);
    while(fscanf(oldinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",&adding.account_number,adding.customer_name,&adding.customer_dob.mm,&adding.customer_dob.dd,&adding.customer_dob.yy,&adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,&adding.customer_phone,&adding.customer_amount,&adding.customer_deposit.mm,&adding.customer_deposit.dd,&adding.customer_deposit.yy)!=EOF)
    {
        if (adding.account_number==withdraw.account_number)
        {
            tst=1;
            printf("Enter the amount you want to withdraw :$ ");
            scanf("%f",&withdraw.customer_amount);
            adding.customer_amount = adding.customer_amount - withdraw.customer_amount;
            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);
            printf("\n\Withdraw successfully!");
            printf("\nBalance : %f",adding.customer_amount);
        }
        else
        {

            fprintf(newinfo,"%d %s %d/%d/%d %d %s %s %d %f %d/%d/%d\n",adding.account_number,adding.customer_name,adding.customer_dob.mm,adding.customer_dob.dd,adding.customer_dob.yy,adding.customer_age,adding.customer_address,adding.customer_NID_PASSPORT,adding.customer_phone,adding.customer_amount,adding.customer_deposit.mm,adding.customer_deposit.dd,adding.customer_deposit.yy);

        }
    }
    fclose(oldinfo);
    fclose(newinfo);
    remove("customerrecord.dat");
    rename("recordupdated.dat","customerrecord.dat");


    if(tst!=1)
    {
        system("cls");
        printf("\nRecord not found!");
Withdraw:
        printf("\nEnter 1 To try again,2 Menu,0 to exits :");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)

            money_Withdraw();
        else if (exits==2)
            main_winwods();
        else if(exits==0)
            close();
        else

        {
            printf("\nInvalid!\a");
            goto Withdraw;
        }
    }


    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exits);
        system("cls");
        if (exits==1)
            Customer_Control();
        else
            close();

    }


}
int main()
{
    main_winwods();
    return 0;
}

