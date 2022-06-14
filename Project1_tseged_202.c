#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*declare the prototypes here*/
int rollDice();
bool passLine();
bool dontpassLine();
int playGame();


int rollDice()
{
    int dieChoice=0; /*choice to roll dice or not*/
    int diceSum =0;
    int die1, die2=0;
    printf("Press 1 to roll the dice\n");
    scanf("%d",&dieChoice);

    if(dieChoice==1)
    {
    die1 = rand()%6+1;
    die2 = rand()%6+1;

    diceSum = die1+die2;
    printf("-------------------------\n");
    printf("First die: %d\n", die1);
    printf("Second die: %d\n", die2);
    printf("Total sum of die: %d\n", diceSum);
    printf("-------------------------\n");

    }
    return diceSum;

}

bool passLine(int bankroll, int bet) {
	 
	int d = 0; /*d will be assigned result of dice roll*/
    int askDoubleBet = 0; /*this will be used to ask if user wants to double bet*/
    int newRoll = 0; /*will be assigned newroll value if point is reached*/
	
    /* check the bankroll, return false if not enough money in bankroll*/
	if (bankroll < 5) 
	   return false;
         
    d= rollDice(); /*assign the sum of rolled dices to d*/   
	  
      switch(d)
                {
                    case 7:
                    case 11:
                            {
                                bankroll += bet;  /*add bet money to bank roll. Ex, if bet=80, bankroll=180*/
				                return true;
                                break;
                            }
		    case 2:
		    case 3:
                    case 12:
                            {
                                bankroll -= bet; /*subtract bet money to bank roll. Ex, if bet=80, bankroll=20*/
                                return false;
                                break;
                            }
                    default:
                            {
                                
                                printf("Point: %d\n",d);

                                /*If user has enough money in bankroll to double bet, ask the user if they want to double their bet.*/
                                /*For example, if user betted $90 in first roll and draws a point, they won't be asked to double their bet because they dont have enough money to do so.*/
                                
                                if((bet*2)<=bankroll)
                                    {
                                        printf("Do you want to double your bet? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                                        scanf("%d", &askDoubleBet);
                                        
                                        if(askDoubleBet==1)
                                            {
                                                bet *=2;
                                                printf("Bet: $%d\n", bet);
                                            }
                                    }

                                newRoll = rollDice(); /*Assign the returned value of rollDice() to newRoll*/

                                while(newRoll!=7 && newRoll!=d)
                                    {
                                        newRoll = rollDice();
                                    }

                                if(newRoll == d) /*use rolls point, user wins.*/
                                    {
                                        printf("You drew your point. Congrats! You won %d.\n", bet);
                                        bankroll+=bet;
                                        printf("You have %d\n", bankroll);
                                        return true;
                                    }

                                if(newRoll==7) /*user rolls 7, user loses*/
                                {
                                    bankroll -= bet;
                                    printf("You drew 7. You lost %d\n\n", bet);
                                    printf("You have %d\n", bankroll);
                                    return false;
                                }                               
                                break;
                            }
                }
    return 0;
}

bool dntpassLine(int bankroll, int bet) {
	 
    int d = 0; /*d will be assigned result of dice roll*/
    int askDoubleBet = 0; /*this will be used to ask if user wants to double bet*/
    int newRoll = 0; /*will be assigned newroll value if point is reached*/
     
     /*check bankroll*/
	if (bankroll < 5) 
	   return false;
         
        d = rollDice(); /*assign the sum of rolled dices to d*/
         
	  switch(d)
                {
                    case 2:
                    case 3:
                    case 12:
                            {
                                bankroll += bet;  /*add bet money to bank roll. Ex, if bet=80, bankroll=180*/
				                return true;
                                break;
                            }
                    case 7:
                    case 11:
                            {
                                bankroll -= bet; /*subtract bet money to bank roll. Ex, if bet=80, bankroll=20*/
                                return false;
                                break;
                            }
                    default:
                            {
                               
                                printf("Point: %d\n",d);

                                /*If user has enough money in bankroll to double bet, ask the user if they want to double their bet.*/
                                /*For example, if user betted $90 in first roll and draws a point, they won't be asked to double their bet because they dont have enough money to do so.*/
                                
                                if((bet*2)<=bankroll)
                                    {
                                        printf("Do you want to double your bet? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                                        scanf("%d", &askDoubleBet);
                                        
                                        if(askDoubleBet==1)
                                            {
                                                bet *=2;
                                                printf("Bet: $%d\n", bet);
                                            }
                                    }

                                newRoll = rollDice(); /*Assign the returned value of rollDice() to newRoll*/

                                while(newRoll!=7 && newRoll!=d)
                                    {
                                        newRoll = rollDice();
                                    }

                                if(newRoll == 7) /*use rolls point, user wins.*/
                                    {
                                        printf("You drew 7. Congrats! You won %d.\n", bet);
                                        bankroll+=bet;
                                        printf("You have $%d\n", bankroll);
                                        return true;
                                    }

                                if(newRoll==d) /*user rolls 7, user loses*/
                                {
                                    bankroll -= bet;
                                    printf("You drew your point. You lost %d\n\n", bet);
                                    printf("You have $%d\n", bankroll);
                                    return false;
                                }

                                
                                
                                break;
                            }
                }
                return 0;
}

int playGame(int bankroll)
{
    int bet=0; /*user's amount of bet*/
    int choice = 0; /*choice for switch*/
    int letItRide = 1; /*to prompt user to let it ride or not*/
    int playAgain = 1; /*"Do you want to play again?" IF ENOUGH BANK ROLL*/
    bool succ_flag=false; /*bollean for result from passline or dont passline*/
    
    bankroll = 100;
    /*Start game by printing out available money(100) and asking for bet value*/

    printf("You bankroll currently is %d, please make your bet: ", bankroll);

    scanf("%d",&bet); /*prompt and scan bet from user*/ 
    
    
    while(bet<5 || bet>bankroll) /*if bet is lessthan 5 and morethan bankroll*/
    {
        printf("Error. Entered bet money is not allowed.\nTry again by entering an appropriate amount.\n");
        scanf("%d", &bet); 
    }
    printf("You made a bet of $%d\n\n", bet); /* print bet money if appropriate value. */
    
    
    printf("Enter your choice:\n1. Pass Line\n2. Do not Pass Line\n3. Quit\n");
    scanf("%d",&choice);
    
    switch(choice) /*switch to print out choice*/
    {  
        case 1: 
            {
                printf("You choose Pass Line.\n");
                break;
            }
        case 2:
            {
                printf("You choose Don't Pass Line.\n");
                break;
            }
        case 3:
        default:
            {
                printf("Au revoir!\n"); /*exits if 3 or anyother input for choice*/
                break;
            }
    }
    
    

    /*while pass line and user wants to play again*/
    while((choice==1) && (letItRide ==1 || playAgain ==0))
        {
            
            succ_flag = passLine(bankroll, bet);
            if(succ_flag == true) /*is win*/
                {
                    printf("Congrats! You won!\n");
                    printf("Do you want to let it ride? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                    scanf("%d", &letItRide);
                    if(letItRide==1)
                         return letItRide;
                    else
                        return 0;

                
                }
            else
                {
                    if(bankroll>=5)
                        {
                            printf("Sorry, you lost.\n");
                            printf("Do you want to quit? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                            scanf("%d", &playAgain);

                            if(playAgain==1)
                                {
                                    printf("Thank you for playing, see you next time. Adios!\n");
                                    return 0;
                                }
                    
                        }
                    else
                        {
                            printf("Sorry, you don't sufficient funds to keep playing. Til next time!\n");
                            return 0;
                        }

                }
        }
        /*while don't pass line and user wants to play again*/
    while((choice==2) && (letItRide ==1 || playAgain ==0)) 
        {
         succ_flag = dntpassLine(bankroll, bet);
            if(succ_flag == true) /*if win*/
                {
                    printf("Congrats! You won!\n");
                    printf("Do you want to let it ride? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                    scanf("%d", &letItRide);
                    if(letItRide==1)
                          return letItRide;
                    else    
                        return 0;

               
                }
            else
                {
                    if(bankroll>=5)
                        {
                            printf("Sorry, you lost.\n");
                            printf("Do you want to quit? (Enter 1 for \"Yes\" and 0 for \"No\")\n");
                            scanf("%d", &playAgain);

                            if(playAgain==1)
                                {
                                    printf("Thank you for playing, see you next time. Adios!\n");
                                    return 0;
                                }
                           
                    else
                        {
                            printf("Sorry, you don't sufficient funds to keep playing. Til next time!\n");
                            return 0;
                        }
                        
                        }
                }   
            }
        

        if(choice!=1 && choice!=2)
        {/*returns 0 if choice is neither passline nor dont passline*/
            return 0;
        }

        return 0;
}

int main()
{
    int seed = 0;
    int bankroll=100;
    int playIntent=0;

    printf("Welcome to the simplified version of the Craps game.\n");

    
    printf("Enter a randon number: \n");
    scanf("%d", &seed);
    srand(seed); 

     do {
        playIntent = playGame(bankroll);
     } while (playIntent == 1);
    
    return 0;

}

