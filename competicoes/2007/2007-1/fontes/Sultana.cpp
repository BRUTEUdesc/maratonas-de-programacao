#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int valores[8][8];
int pos[8];
vector<int> sum;

void leMatrizValor(){
	for(int a=0;a<8;a++){
		scanf("%i %i %i %i %i %i %i %i",&valores[a][0],&valores[a][1]
		,&valores[a][2],&valores[a][3],&valores[a][4],&valores[a][5],
		&valores[a][6],&valores[a][7]);
    }		
}

bool msmC(int x){
	for(int a=0;a<x;a++){
		if(pos[a]==pos[x]){
			return true;
		}
	}
	return false;
}

bool msmD(int x){
	for(int a=0;a<x;a++){
		int num = x-a;
		if(pos[a]==pos[x]+num || pos[a]==pos[x]-num){
			return true;
		}
		
	}
	return false;
}


void adicionaSol(){
	int soma =0;
	for(int a=0;a<8;a++){
		soma = soma+valores[a][pos[a]];
	}
	sum.push_back(soma);
	
}


int main()
{	
	int num=0;	
	scanf("%i",&num);
	for(int a=0;a<num;a++){
		sum.clear();
		leMatrizValor();
		int i[8];
		for(i[0] = 0;i[0]<8;i[0]++){
			pos[0] = i[0];
			
			for(i[1] = 0;i[1]<8;i[1]++){
				
				pos[1]=i[1];
				
				if(!msmC(1)&&!msmD(1)){
					for(i[2] = 0;i[2]<8;i[2]++){
						
						
						pos[2]=i[2];
						if(!msmC(2)&&!msmD(2)){
							for(i[3] = 0;i[3]<8;i[3]++){
								
								pos[3]=i[3];
								if(!msmC(3)&&!msmD(3)){
									for(i[4] = 0;i[4]<8;i[4]++){
										
										pos[4]=i[4];
										if(!msmC(4)&&!msmD(4)){
											for(i[5] = 0;i[5]<8;i[5]++){
												
												pos[5]=i[5];
												if(!msmC(5)&&!msmD(5)){
													for(i[6] = 0;i[6]<8;i[6]++){
														
														pos[6]=i[6];
														if(!msmC(6)&&!msmD(6)){
															for(i[7] = 0;i[7]<8;i[7]++){
																pos[7]=i[7];
																if(!msmC(7)&&!msmD(7)){
																	
																	adicionaSol();
															
															
																}
															}
													
													
														}
													}
											
											
												}
											}
									
									
										}
									}
							
							
								}
							}
					
					
						}
					}
				}
			}
		}
		
		
		
		sort(sum.begin(),sum.end());
		int n = sum[sum.size()-1];
		if (n < 10)
		    printf("    %i\n",n);	
		else if (n < 100)
		    printf("   %i\n",n);	
		else if (n < 1000)
		    printf("  %i\n",n);	
		else if (n < 10000)
		    printf(" %i\n",n);	
		else
			printf("%i\n",n);	
		
	}
}
