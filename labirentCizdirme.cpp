#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int x = 0, y = 0;
	 printf("Labirentin Sinirlarini Giriniz :\n");

        printf("Satir sayisini giriniz :");
        scanf("%d",&x);
        printf("Sutun sayisini giriniz :");
        scanf("%d",&y);

	int labirent[x][y];
        srand(time(NULL));
        int r = 0;
 	for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){

                        r = rand()%100+1;
			if(i==0 || j==0 || i==(x-1) || j ==(y-1))
				labirent[i][j] = 1;
                       
			 if(((j==0 || j==y-1)&& j%2==0)||((i==0 || i==x-1)&&i%2==0))
                                labirent[i][j] = 1;
                         else if(i%2!=0 && j%2!=0)
                                labirent[i][j] = 0;
			 else if(((i%2!=0 && j!=0 && j!=y-1) && j%2==0) || (i%2==0 && (i!=0 && i!=x-1 && j%2!=0)))
				labirent[i][j] = 1;
			 else if(i%2==0 && j%2==0)
				labirent[i][j] = 0;
			

                }
        }
 	labirent[0][0] = 0;
	if(r%2==0)
        	labirent[x-1][rand()%(y-1)] = 0;
	else if(r%3==0)
        	labirent[rand()%(x-2)+1][y-1] = 0;
	else// if(r%3==0 && r%2==0)
        	labirent[rand()%(x-2)+1][0] = 0;
	//else
        //	labirent[0][rand()%(y-1)] = 0;

	FILE *dosya = fopen("lab.txt","w");

        fprintf(dosya,"%d\n%d\n",x,y);
         for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                       fprintf(dosya,"%d",labirent[i][j]);
                }
               fprintf(dosya,"\n");
        }
        fclose(dosya);


}
