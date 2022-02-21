#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define normalPrinting 	100
#define colourPrinting 	101

#define BLACK 			0
#define RED		    	1
#define GREEN			2
#define YELLOW			3
#define BLUE			4
#define MAGENTA			5
#define CYAN			6
#define	WHITE			7

#define unWanted       	9

void printColourText(int colourText,int ForegroundColorCode,int BackgroundColorCode );//start to print colour code
void copy2DArray(int array1[5][6], int array2[5][6]);//copying from array2 to array1
void digitIn2DArray(char num, int digitPosition, int colourCode);//giving 2D array to given digit
int cursorPosition(int digitPosition);//chaning the cursor position
void printDigit(int array[5][6],int digitPosition, int colourCode);//print digit
void printColon(int cursorPosition, int colourCode);//printing colon		
void printClockTime(int colourCodeDigit);//printing time per sec


int main(int argc, char **argv){

    printColourText(normalPrinting, unWanted, unWanted);//for normal printing

    //in main functin codes are  checking user inputs as arguments and find which clock is going to print
    int find=0, count=0, countH=0, countC=0;

    //finding - in reverse
    for (int i=argc-1; 0<=i; i--){
        int find_ = strcmp(argv[i], "-");//omit '-' input  
        if(find_==0){
            continue;
        }
        int res = strncmp(argv[i], "-", 1);//find flag count 
        if (res==0){
            find=1;//finded flag
            count++;// count flag
        }
    }

    if (find==1){ 

        //finding -h in reverse
        for (int i=argc-1; 0<=i; i--){
            int res = strcmp(argv[i], "-h");
            if (res==0){
                countH++;// -h flag count
            }
        }

        //finding -c in reverse
        for (int i=argc-1; 0<=i; i--){
            int res = strcmp(argv[i], "-c");
            if (res==0){
                countC++;//-c flag count
            }
        }
        
        //finding -blah blah (other falgs)
        if ((countH+countC)==count){
            if (countH>=1){//found -h
                printf("usage : clock \033[34m-h\033[0m                quick help on cmd\n");
                printf("usage : clock \033[34m-c\033[0m <color>        print clock with a color\n");
                printf("<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n");
            }else{//found -c
                //finding -c in reverse which index
                for (int i=argc-1; 0<=i; i--){
                    int res = strcmp(argv[i], "-c");
                    if (res==0 && argc==i+1){//fiding -c flag in last 
                        printf("\033[31mInvalid\033[0m use of arguments.\n");
                        printf("usage : clock \033[34m-h\033[0m                quick help on cmd\n");
                        printf("usage : clock \033[34m-c\033[0m <color>        print clock with a color\n");
                        break;
                    }else if (res==0){
                        //finding the after -c flag argument 
                        int black   = strcmp(argv[i+1], "black");
                        int red     = strcmp(argv[i+1], "red");
                        int green   = strcmp(argv[i+1], "green");
                        int yellow  = strcmp(argv[i+1], "yellow");
                        int blue    = strcmp(argv[i+1], "blue");
                        int magenta = strcmp(argv[i+1], "magenta");
                        int cyan    = strcmp(argv[i+1], "cyan");
                        int white   = strcmp(argv[i+1], "white");
                        
                        if (black==0 || red==0 || green==0 || yellow==0 || blue==0 || magenta==0 || cyan==0 || white==0){
                            //printing colous clock    
                            if (black==0){
                                printClockTime(BLACK);// printing black clock
                            } else if(red==0){
                                printClockTime(RED);// printing red clock
                            } else if (green==0){
                                printClockTime(GREEN);// printing green clock
                            } else if (yellow==0){
                                printClockTime(YELLOW);// printing yellow clock
                            } else if (blue==0){
                                printClockTime(BLUE);// printing blue clock
                            } else if (magenta==0){
                                printClockTime(MAGENTA);// printing magenta clock
                            } else if (cyan==0){
                                printClockTime(CYAN);// printing cyan clock
                            } else if (white==0){
        	                    printClockTime(WHITE);// printing white clock
                            }    
                        }else{
                            printf("%s :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n",argv[i+1]);
                        }
                        break;
                    }
                }
            }
        } else{//Found -blah blah
            printf("\033[91mInvalid\033[0m use of arguments.\n");
            printf("usage : clock \033[94m-h\033[0m                quick help on cmd\n");
            printf("usage : clock \033[94m-c\033[0m <color>        print clock with a color\n");
        }
    } else{
        	printClockTime(WHITE); // printing normal clock
    }

return 0;
}

void printClockTime(int colourCodeDigit){

	    printf("\033[?25l"); //Hiding the cursor
		printf("\033[2J"); //Clear console

	    while(1){
        char timeVal[10];
        char dateVal[12];

        // Define temporary variables 
        time_t current_time;
        struct tm *local_time;

        // Retrieve the current time 
        current_time = time(NULL);

        // Get the local time using the current time 
        local_time = localtime(&current_time);

        strftime(timeVal,20,"%X", local_time); //store current time in timeVal
        strftime(dateVal,20,"%Y-%m-%d", local_time); //store date in dateVal


        //printing time as given colour

        // printing hours
        for(int i=0; i<2; i++){
  		    digitIn2DArray(timeVal[i], i, colourCodeDigit);
        }
        printColon(15, colourCodeDigit);// Print colon //15 => changing the cursor position 
        // printing mintues
        for(int i=3; i<5; i++){
  		    digitIn2DArray(timeVal[i], i, colourCodeDigit);
        }
        printColon(34, colourCodeDigit);// Print colon //34 => changing the cursor position 
        // printing secounds
        for(int i=6; i<8; i++){
  		    digitIn2DArray(timeVal[i], i, colourCodeDigit);
        }


        //printing date as given colour
        printf("\033[8;23H");//changing the cursor position 
        
        printColourText(colourPrinting, colourCodeDigit, unWanted);
        printf("%s\n",dateVal);
        printColourText(normalPrinting, unWanted, unWanted);

        sleep(1);//sleeping 1 sec
    }

}

void printColourText(int colourText,int ForegroundColorCode,int BackgroundColorCode){
    if(colourText == normalPrinting){
        printf("\033[0m");
    }else if(colourText == colourPrinting){
        if(ForegroundColorCode==unWanted){
        printf("\033[%dm", BackgroundColorCode +40);
        } else if(BackgroundColorCode==unWanted){
        printf("\033[%dm", ForegroundColorCode +30);
        }
    }
}

void digitIn2DArray(char num, int digitPosition, int colourCode){
    int arrayFor0[5][6]={ // 0
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int arrayFor1[5][6]={ // 1
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
    int arrayFor2[5][6]={ // 2
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1}
	};
    int arrayFor3[5][6]={ // 3
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int arrayFor4[5][6]={ // 4
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
    int arrayFor5[5][6]={ // 5
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int arrayFor6[5][6]={ // 6
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int arrayFor7[5][6]={ // 7
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
    int arrayFor8[5][6]={ // 8
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int arrayFor9[5][6]={ // 9
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
    int array[5][6];//for stroe digit array

    switch (num) // copying correct digit2Darray in array
        {
        case '1': copy2DArray(array,arrayFor1); break;
        case '2': copy2DArray(array,arrayFor2); break;
        case '3': copy2DArray(array,arrayFor3); break;
        case '4': copy2DArray(array,arrayFor4); break;
        case '5': copy2DArray(array,arrayFor5); break;
        case '6': copy2DArray(array,arrayFor6); break;
        case '7': copy2DArray(array,arrayFor7); break;
        case '8': copy2DArray(array,arrayFor8); break;
        case '9': copy2DArray(array,arrayFor9); break;  
        case '0': copy2DArray(array,arrayFor0); break;
        }

    printDigit(array, digitPosition, colourCode);//print digit 
}

void printDigit(int array[5][6],int digitPosition, int colourCode){
	
	for(int row=0; row<5; row++){
		for(int colum=0; colum<6;colum++){
			printf("\033[%d;%dH", row+2, colum+cursorPosition(digitPosition));//changing the cursor position 
			if(array[row][colum]==0){
				printColourText(normalPrinting, unWanted, unWanted);
				printf(" ");
			}
			else if(array[row][colum]==1){
				printColourText(colourPrinting, unWanted, colourCode);
				printf(" ");
				printColourText(normalPrinting, unWanted, unWanted);
			}
		}
	}		
}

int cursorPosition(int digitPosition){
	int cPosition;
	switch (digitPosition) // copying correct digit2Darray in array
        {
        case 0 : cPosition= 2; break;
        case 1 : cPosition= 9; break;
        case 3 : cPosition=21; break;
        case 4 : cPosition=28; break;
        case 6 : cPosition=40; break;
        case 7 : cPosition=47; break;
        }
	return cPosition;
}

void printColon(int cursorPosition, int colourCode){		
	
	int array[5][6]={ // Defining an array for a colon
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0}
	};
	for(int row=0; row<5; row++){
		for(int colum=0; colum<6;colum++){
			printf("\033[%d;%dH",row+2, colum+cursorPosition);//changing the cursor position 
			if(array[row][colum]==0){
				printColourText(normalPrinting, unWanted, unWanted);
				printf(" ");
			}
			else if(array[row][colum]==1){
				printColourText(colourPrinting, unWanted, colourCode);
				printf(" ");
				printColourText(normalPrinting, unWanted, unWanted);
			}
		}
	}		
}

void copy2DArray(int array1[5][6], int array2[5][6]){
	for(int row=0; row<5; row++){
		for(int colum=0; colum<6; colum++){
			array1[row][colum]=array2[row][colum];
		}
	}
}