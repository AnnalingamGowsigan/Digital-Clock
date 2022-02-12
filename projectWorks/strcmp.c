#include <stdio.h>
#include <string.h>

int main () {
   char str1[15]="-ad";
   char str2[15]="-h";
   int ret;

   //strcpy(str1, "abcdef");
   //strcpy(str2, "ABCDEF");

   ret = strncmp(str1, "-", 1);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}