#include <stdio.h>
#include <stdlib.h>
int num,opt,opt2,x,i,j; //declaration of integer type of global variables
char name[50]; //declaration char type of global variable
char conf; //declaration of global variable for confirmation
float price; //declaration of global variable for formularize the price
void menu(); //declaration of menu function
void fast_food(); //declaration of fast food function
void cold_drinks(); //declaration of cold drinks function
void ice_cream(); //declaration of ice cream function
void billing(float pr); //declaration of billing function

int main()
{
    printf("\t\t\t\t\t   **VARIELICIOUS VENDING MACHINE**\n\n");
    printf("\t\t\t\t\t   WELCOME TO OUR VENDING MACHINE!!\n\n");
    printf("\t\t\t      Enter your name (Max. 50 Characters) : "); //machine prompted the user to enter their name
    gets(name);
    printf("\n\t\t\t\t\t  Hi %s. Welcome to VARIELICIOUS!!", name); //machine greets the user
    menu(); //calling menu function
    return 0;
}
void menu()
{
    int opt;
    printf("\n\n\t\t\t\t\tHere is the list of our items : \n\n");
    for(num=1;num<4;num++){
        printf("\t\t\t\t\t[%d] FAST FOOD\n", num=1);
        printf("\t\t\t\t\t[%d] COLD DRINKS\n", num=2);
        printf("\t\t\t\t\t[%d] ICE CREAM\n", num=3);
    }
    rtr:
    printf("\n\t\t\t\t\tEnter Your Choice : "); //machine prompted user to enter their choice
    scanf("%d", &opt); //user enters choice of item
    switch(opt)
    {
        case 1:
            fast_food(); //calling fast food function
            break;
        case 2:
            cold_drinks(); //calling cold drinks function
            break;
        case 3:
            ice_cream(); //calling ice cream function
            break;
        default:
            printf("\t\t\t\t\tCHOOSE AGAIN!!\n"); //showing invalid message when user enter invalid input
            goto rtr;
            break; //retry from rtr
    }
}
void fast_food()
{
    char s[][8] = {{"Regular"},{"Medium"},{"Large"}}; //initialization of size of PIZZA
    float a[3] = {16.00,24.00,30.00}; //initialization of price of different size of PIZZA
    float b[3] = {4.60,12.30,2.30}; //initialization of price of BURGER, TACO AND SANDWICH
    float *aPtr, *bPtr; //2 pointer declaration
    aPtr=&a[0]; //store address of a[0] in pointer a
    bPtr=&b[0]; //store address of b[0] in pointer b

    system("cls"); //clear the screen of menu function
    printf("\n\n\t\t\t\t\t**FAST FOOD**\n\n");
    for(num=1;num<5;num++){
        printf("\t\t\t\t\t[%d] PIZZA\n", num=1);
        printf("\t\t\t\t\t[%d] BURGER\n", num=2);
        printf("\t\t\t\t\t[%d] TACO\n", num=3);
        printf("\t\t\t\t\t[%d] SANDWICH\n", num=4);
    }
    rtr: //label rtr is defined
    printf("\n\t\t\t\t\tEnter Your Choice : ");
    scanf("%d", &opt); //user enter 1/2/3/4
    switch(opt)
    {
        case 1:
            for(num=1;num<4;num++){
            printf("\n\t\t\t\t\t\tSize : [%d] Regular", num=1);
            printf("\n\t\t\t\t\t\t       [%d] Medium", num=2);
            printf("\n\t\t\t\t\t\t       [%d] Large", num=3);
            }
            rtr2: //label rtr2 is defined
            printf("\n\n\t\t\t\t\t\tEnter Your Choice : ");
            scanf("%d", &opt2);
            switch(opt2)
            {
                case 1:
                    i=0;
                    printf("\n\t\t\t\t\t\tPrice of %s PIZZA : RM %.2f", s[i],*(aPtr+i)); /* s[0]=Regular & *aPtr=16.00
                                                                                           (pointer stay at a[0]) */
                    goto ch; //jump to ch
                    break;
                case 2:
                    i=1;
                    printf("\n\t\t\t\t\t\tPrice of %s PIZZA : RM %.2f", s[i],*(aPtr+i)); /* s[1]=Medium & *(aPtr+1)=24.00
                                                                                           (+1 step from a[0],a[1])*/
                    goto ch; //jump to ch
                    break;
                case 3:
                    i=2;
                    printf("\n\t\t\t\t\t\tPrice of %s PIZZA : RM %.2f", s[i],*(aPtr+i)); /* s[2]=Large & *(aPtr+2)=30.00
                                                                                           (+2 step from a[0],a[2])*/
                    goto ch; //jump to ch
                    break;
                default:
                    printf("\t\t\t\t\t\tChoose 1/2/3 ONLY!!!"); //displays if user enters other than 1/2/3
                    goto rtr2; //jump to rtr2

                    ch: //label ch is defined
                    printf("\n\t\t\t\t\t\tHow many do you want? : "); /*asks user to enter the quantity of PIZZA that user
                                                                        desires*/
                    scanf("%d", &x);
                    price=x * *(aPtr+i);
                    printf("\n\t\t\t\t\t\tTotal to be paid : RM %.2f\n", price); //displays the total to be paid

                    printf("\n\t\t\t\t\t\t(Press Y/y for Yes or N/n for No)");
                    printf("\n\t\t\t\t\t\tConfirm Your Order %s : ", name); //asks for order confirmation
                    scanf(" %c%*c", &conf);
                    if(conf=='Y'||conf=='y'){ //if user confirmed the order
                        billing(price);} //calling billing function
                    else if(conf=='N'||conf=='n'){ //if not
                        goto ch;} //jump to ch
                    else{
                        printf("\n\t\t\t\t\t\tFAILED"); //shows failed message when user enter other than Y/y and N/n
                        fast_food();} //calling fast food function
            }
            break;
        case 2:
            j=0;
            printf("\n\t\t\t\t\t\tPrice of BURGER : RM %.2f", *(bPtr+j)); //*bPtr=4.60(pointer stay at b[0])
            printf("\n\t\t\t\t\t\tSize : Small");
            goto ch2; //jump to ch2
            break;
        case 3:
            j=1;
            printf("\n\t\t\t\t\t\tPrice of TACO : RM %.2f", *(bPtr+j)); //*(bPtr+1)=12.30(+1 steps from b[0],b[1])
            printf("\n\t\t\t\t\t\tSize : Large");
            goto ch2; //jump to ch2
            break;
        case 4:
            j=2;
            printf("\n\t\t\t\t\t\tPrice of SANDWICH : RM %.2f", *(bPtr+j)); //*(bPtr+2)=2.30(+2 steps from b[0],b[2])
            printf("\n\t\t\t\t\t\tSize : Small");
            goto ch2; //jump to ch2
            break;
        default:
            printf("\t\t\t\t\t\tChoose 1/2/3/4 ONLY!!!");
            goto rtr; //jump to rtr if user enters other than 1/2/3/4

            ch2: //label ch2 is defined
            printf("\n\t\t\t\t\t\tHow many do you want? : "); //asks user to enter the quantity of selected fast food that user desires
            scanf("%d", &x);
            price=x * *(bPtr+j);
            printf("\n\t\t\t\t\t\tTotal to be paid : RM %.2f\n", price); //displays the total to be paid

            printf("\n\t\t\t\t\t\t(Press Y/y for Yes or N/n for No)");
            printf("\n\t\t\t\t\t\tConfirm Your Order %s : ", name); //asks for order confirmation
            scanf(" %c%*c", &conf);
            if(conf=='Y'||conf=='y'){ //if user confirmed the order
                billing(price);} //calling billing function
            else if(conf=='N'||conf=='n'){ //if not
                goto ch2;} //it jump to ch2
            else{
                printf("\n\t\t\t\t\t\tFAILED");
                fast_food();} //calling fast food function when user enter invalid input
    }
}
void cold_drinks()
{
    float a[4]={2.50,2.00,2.20,1.60}; //initialization of the prices of each cold drink
    float *aPtr; //declaration of pointer a
    aPtr=&a[0]; //store address of a[0] in pointer a
    system("cls"); //clear the screen of menu function
    printf("\n\n\t\t\t\t\t**COLD DRINKS**\n\n");
    for(num=1;num<5;num++){
        printf("\t\t\t\t\t[%d] PEPSI\n", num=1);
        printf("\t\t\t\t\t[%d] MOUNTAIN DEW\n", num=2);
        printf("\t\t\t\t\t[%d] COKE\n", num=3);
        printf("\t\t\t\t\t[%d] ICE LEMON TEA\n", num=4);
    }
    rtr: //label rtr is defined
    printf("\n\t\t\t\t\tEnter Your Choice : ");
    scanf("%d", &opt); //user enters 1/2/3/4
    switch(opt)
    {
        case 1:
            i=0;
            printf("\n\t\t\t\t\t\tPrice of PEPSI : RM %.2f", *(aPtr+i)); //*aPtr=2.50(pointer stay at a[0])
            printf("\n\t\t\t\t\t\tQuantity : 200ml");
            break;
        case 2:
            i=1;
            printf("\n\t\t\t\t\t\tPrice of MOUNTAIN DEW : RM %.2f", *(aPtr+i)); //*aPtr=2.00(+1 step from a[0],a[1])
            printf("\n\t\t\t\t\t\tQuantity : 200ml");
            break;
        case 3:
            i=2;
            printf("\n\t\t\t\t\t\tPrice of COKE : RM %.2f", *(aPtr+i)); //*aPtr=2.20(+2 steps from a[0], a[2])
            printf("\n\t\t\t\t\t\tQuantity : 210ml");
            break;
        case 4:
            i=3;
            printf("\n\t\t\t\t\t\tPrice of ICE LEMON TEA : RM %.2f", *(aPtr+i)); //*aPtr=1.60(+3 steps from a[0],a[3])
            printf("\n\t\t\t\t\t\tQuantity : 210ml");
            break;
        default:
            printf("\t\t\t\t\t\tChoose 1/2/3/4 ONLY!!!");
            goto rtr; //jump to rtr if user enters other than 1/2/3/4
    }
            ch: //label ch is defined
            printf("\n\t\t\t\t\t\tHow many do you want? : ");
            scanf("%d", &x);
            price=x * *(aPtr+i);
            printf("\n\t\t\t\t\t\tTotal to be paid : RM %.2f\n", price);

            printf("\n\t\t\t\t\t\t(Press Y/y for Yes or N/n for No)");
            printf("\n\t\t\t\t\t\tConfirm Your Order %s : ", name);
            scanf(" %c", &conf);
            if(conf=='Y'||conf=='y'){ //if user confirmed the order
                billing(price);} //calling billing function
            else if(conf=='N'||conf=='n'){ //if not
                goto ch;} //jump to ch
            else{
                printf("\n\t\t\t\t\t\tFAILED");
                cold_drinks();} //calling cold drinks function when user enter invalid input
}
void ice_cream()
{
    float a[4]={2.00,2.40,1.80,2.10}; //initialization of the prices of each ice cream
    float *aPtr;//declaration of pointer a
    aPtr=&a[0]; //store address of a[0] in pointer a
    system("cls");
    printf("\n\n\t\t\t\t\t**ICE CREAM**\n\n");
    for(num=1;num<5;num++){
        printf("\t\t\t\t\t[%d] NEOPOLITAN\n", num=1);
        printf("\t\t\t\t\t[%d] CHOCOLATE\n", num=2);
        printf("\t\t\t\t\t[%d] STRAWBERRY\n", num=3);
        printf("\t\t\t\t\t[%d] LIME VANILLA\n", num=4);
    }
    rtr: //label rtr is defined
    printf("\n\t\t\t\t\tEnter Your Choice : ");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
            i=0;
            printf("\n\t\t\t\t\t\tPrice of NEOPOLITAN : RM %.2f", *(aPtr+i)); //*aPtr=2.00(pointer stay at a[0])
            printf("\n\t\t\t\t\t\tQuantity : 64ml");
            break;
        case 2:
            i=1;
            printf("\n\t\t\t\t\t\tPrice of CHOCOLATE is : RM %.2f", *(aPtr+i)); //*aPtr=2.40(+1 step from a[0],a[1])
            printf("\n\t\t\t\t\t\tQuantity : 70ml");
            break;
        case 3:
            i=2;
            printf("\n\t\t\t\t\t\tPrice of STRAWBERRY : RM %.2f", *(aPtr+i)); //*aPtr=1.80(+2 steps from a[0],a[2])
            printf("\n\t\t\t\t\t\tQuantity : 60ml");
            break;
        case 4:
            i=3;
            printf("\n\t\t\t\t\t\tPrice of LIME VANILLA : RM %.2f", *(aPtr+i)); //*aPtr=2.10(+3 steps from a[0],a[3])
            printf("\n\t\t\t\t\t\tQuantity : 65ml");
            break;
        default:
            printf("\t\t\t\t\t\tChoose 1/2/3/4 ONLY!!!");
            goto rtr; //jump to rtr if user enters other than 1/2/3/
    }
            ch: //ch label is defined
            printf("\n\t\t\t\t\t\tHow many do you want? : ");
            scanf("%d", &x);
            price=x * *(aPtr+i);
            printf("\n\t\t\t\t\t\tTotal to be paid : RM %.2f\n", price);

            printf("\n\t\t\t\t\t\t(Press Y/y for Yes or N/n for No)");
            printf("\n\t\t\t\t\t\tConfirm Your Order %s : ", name);
            scanf(" %c%*c", &conf);
            if(conf=='Y'||conf=='y'){ //if user confirmed the order
                billing(price);} //calling billing function
            else if(conf=='N'||conf=='n'){ //if not
                goto ch;} //jump to ch
            else{
                printf("\n\t\t\t\t\t\tFAILED");
                ice_cream();} //calling ice cream function when user enter invalid input
}
void billing(float pr) //function definition of billing function
{
    float amt; //amount
    char ch; //choice
    printf("\n\t\t\t\t\t\tEnter Amount : RM ");
    scanf("%f", &amt); //user enter amount to be paid
    if(amt>pr)
    {
        printf("\n\t\t\t\t\t\tYour Change : RM %.3f", amt-pr);
        printf("\n\t\t\t\t\t\tPlease Collect Your Change...");
    }
    else if(amt==pr)
    {
        printf("\n\t\t\t\t\t\tYour Change : RM %.3f", amt-pr);
    }
    else{
        printf("\n\t\t\t\t\t\tInsufficient Amount!!"); /*if the amount to be paid that user entered is less than the actual price, it
                                               displays Insufficient Amount!!*/
        billing(pr); //calling billing function
    }
    printf("\n\n\t\t\t\t\t\t(Press Y/y for Yes or N/n for No)");
    printf("\n\t\t\t\t\t\tDO YOU WISH TO BUY ANY THING MORE %s? : ", name); //machine asks user if user want to buy again
    scanf(" %c", &ch);
    if(ch=='Y'||ch=='y'){
        system("cls"); //clear the screen of billing function
        menu();} //if user desires to buy again, it will call the menu function
    else if(ch=='N'||ch=='n'){
        printf("\n\t\t\t\t\t\t***THANK YOU FOR BUYING WITH US***");} //if user does not wish to buy anymore, it will print this
}
