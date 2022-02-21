#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    int find=0, count=0, countH=0, countC=0;

    /*printf("The number of argumants :%d\n",argc);
    for (int i=0;i<argc;i++){
        printf("The argumants [%d] is :%s\n",i+1, argv[i]);

    }*/

    //finding - in reverse
    for (int i=argc-1; 0<=i; i--){
        int find_ = strcmp(argv[i], "-");
        if(find_==0){
            continue;
        }
        int res = strncmp(argv[i], "-", 1);
        if (res==0){
            find=1;
            count++;
        }
    }

    if (find==1){

        //finding -h in reverse
        for (int i=argc-1; 0<=i; i--){
            //printf("The argumants [%d] is :%s\n",i+1, argv[i]);
            int res = strcmp(argv[i], "-h");
            if (res==0){
                countH++;
            }
        }

        //finding -c in reverse
        for (int i=argc-1; 0<=i; i--){
            //printf("The argumants [%d] is :%s\n",i+1, argv[i]);
            int res = strcmp(argv[i], "-c");
            if (res==0){
                countC++;
            }
        }
        
        //finding -blah blah
        if ((countH+countC)==count){
            if (countH>=1){//found -h
                printf("usage : clock -h                quick help on cmd\n");
                printf("usage : clock -c <color>        print clock with a color\n");
                printf("<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n");
            }else{//found -c
                //finding -c in reverse which index
                for (int i=argc-1; 0<=i; i--){
                    int res = strcmp(argv[i], "-c");
                    if (res==0 && argc==i+1){
                        printf("Invalid use of arguments.\n");
                        printf("usage : clock -h                quick help on cmd\n");
                        printf("usage : clock -c <color>        print clock with a color\n");
                        break;
                    }else if (res==0){
                        //printf("The argumants [%d] is :%s\n",i+1, argv[i]);

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
                                printf("printing black clock\n");//printing black clock
                            } else if(red==0){
                                printf("printing red clock\n");//printing red clock
                            } else if (green==0){
                                printf("printing green clock\n");//printing green clock
                            } else if (yellow==0){
                                printf("printing yellow clock\n");//printing yellow clock
                            } else if (blue==0){
                                printf("printing blue clock\n");//printing blue clock
                            } else if (magenta==0){
                                printf("printing magenta clock\n");//printing magenta clock
                            } else if (cyan==0){
                                printf("printing cyan clock\n");//printing cyan clock
                            } else if (white==0){
                                printf("printing white clock\n");//printing white clock
                            }    
                        }else{
                            printf("%s :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n",argv[i+1]);
                        }
                        break;
                    }
                }
            }
        } else{//Found -blah blah
            printf("Invalid use of arguments.\n");
            printf("usage : clock -h                quick help on cmd\n");
            printf("usage : clock -c <color>        print clock with a color\n");
        }
    } else{
        printf("printing normal clock\n");// printing normal clock
    }

return 0;
} 
