/* Example using asctime by TechOnTheNet.com */

#include <stdio.h>
#include <time.h>

//void anotherMethed();

int main(int argc, const char * argv[])
{
    //anotherMethed();

    /* Define temporary variables */
    time_t current_time;
    struct tm *local_time;

    /* Retrieve the current time */
    current_time = time(NULL);

    /* Get the local time using the current time */
    local_time = localtime(&current_time);

    /* Display the local time */
    printf("The time at TechOnTheNet is: %s", asctime(local_time));

    return 0;
}

void anotherMethed(){
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );  
   printf("Current local time and date: %s", asctime(info));
}
