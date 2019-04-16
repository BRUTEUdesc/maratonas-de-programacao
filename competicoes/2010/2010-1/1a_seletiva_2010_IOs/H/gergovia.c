#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char buf[1000000],*t,*r;
	//freopen("gergovia.in","r",stdin);
	long long s,w,z,f;
	int n;
	while(1){
		scanf("%i",&n);
		if(!n)exit(0);
		f=getchar();
		gets(buf);
		t=buf;
		s=w=0;
		while(r=strtok(t," ")){
			t=NULL;
			z=atoi(r);
			w+=z;
			s+=abs(w);
		}	
		printf("%lld\n",s);
	}	
	return 0;
}	
