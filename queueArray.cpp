#include <stdio.h>
#include <stdlib.h>

int *dizi = NULL;
int sira = 0,siraBasi = 0,boyut = 2;

int deque(){
	if(sira == siraBasi){
		printf("sira bos");
		return -1;
	}
	if(sira-siraBasi <= boyut/4){
		int * dizi2 = (int *)malloc(sizeof(int)*boyut/2);
		for(int i=0;i<sira-siraBasi;i++){
			dizi2[i] = dizi[siraBasi+i];
		}	
		sira -= siraBasi;
		siraBasi = 0;
		boyut /= 2;
		free(dizi);
		dizi = dizi2;
	}
	return dizi[siraBasi++];
}

void toparla(){
	if(siraBasi == 0)
		return ;
	for(int i=0;i<boyut;i++){
		dizi[i] = dizi[i+siraBasi];
	}
	sira -= siraBasi;
	siraBasi = 0;
}

void enque(int a){
	if(dizi == NULL){
		dizi = (int *)malloc(sizeof(int)*2);
	}
	if(sira >= boyut){
		boyut *= 2;
		int * dizi2 = (int *)malloc(sizeof(int)*boyut);
		for(int i=0;i<boyut/2;i++)
			dizi2[i] = dizi[i];
		free(dizi);
		dizi = dizi2;
	}
	dizi[sira++] = a;
}

int main(){

	for(int i=0;i<20;i++){
		enque(i*10);
	}
	printf("Durum -> boyut :%d sira :%d sirabasi :%d",boyut,sira,siraBasi);
	for(int i=0;i<13;i++){
		printf("%d ",deque());
	}
	toparla();	
	printf("Durum -> boyut :%d sira :%d sirabasi :%d",boyut,sira,siraBasi);
	for(int i=0;i<20;i++){
		enque(i*10);
	}	
	printf("Durum -> boyut :%d sira :%d sirabasi :%d",boyut,sira,siraBasi);
	for(int i=0;i<30;i++){
		printf("%d ",deque());
	}
	printf("Durum -> boyut :%d sira :%d sirabasi :%d",boyut,sira,siraBasi);
}
