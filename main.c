#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int cash=100;
void play(int bet){
	char *c=(char*)malloc(10000*sizeof(char));
  c[0]='j';c[1]='q';c[2]='k';
	printf("Shuffling....");
	srand(time(NULL));
	int i;
	for(i=0;i<5;i++){
		int x=rand()%3;
		int y=rand()%3;
		int t=c[x];c[x]=c[y];c[y]=t;
		
	}
	int playerguess;
	printf("What's the position of queen - 1 ,2 or 3 ?");
	scanf("%d",&playerguess);
	if(c[playerguess-1]=='q'){
		cash+=3*bet;
		printf("you Win ! =\"%c %c %c \"total cahs =%d",c[0],c[1],c[2],cash);
	}
	else{
		cash-=bet;
		printf("you Loose ! =\"%c %c %c \"total cahs =%d",c[0],c[1],c[2],cash);
	}
  free(c);
}
int main(void) {
	int bet;
	printf("**Welcome to the Virtual Casino**\n\n");
  printf("Total cahs =$%d\n",cash);
	while(cash>0){
		printf("What's your bet? $");
		scanf("%d",&bet);
		
		if(bet==0||bet>cash)break;
		play(bet);
		printf("\n**********************************\n");
		
		
		
	}



	return 0;
}