#include <stdio.h>

int a,b;

int i,j,k,carry,carries;

main(){
   while (2 == scanf("%d%d",&a,&b)){
      if (a == 0 && b == 0) return;
      carries = carry = 0;
      for (i=9;i>=0;i--) {
        carry = a%10+b%10+carry > 9;
        carries += carry;
        a /= 10; 
        b /= 10;
      }
      if (carries == 0) printf("No carry operation.\n");
      else if (carries == 1) printf("1 carry operation.\n");
      else printf("%d carry operations.\n",carries);
   }
}
