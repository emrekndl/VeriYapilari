#include <stdio.h>

int adim = 1;
	
struct yigin{
	int veri[3];
	int sayac;
} a[3];  //a[0] birinci disk a[1] ikinci disk a[2] üçüncü disk

int pop(yigin * d){   //dizinin en sonundaki elemanı okur.
	d -> sayac--;
	return d -> veri[d -> sayac];
}

void push(yigin * d, int veri){  //dizinin içine veri ekler.
	d -> veri[d -> sayac] = veri;
	d -> sayac++;
	printf("push :%d ",veri);
}

int top(yigin * d){    //dizinin en üstündeki elemanı döndürür.
	return d -> veri[d -> sayac-1];
}

int birinciDisk(){ //1 numaralı, en küçük diskin hangi direkte olduğunu bulur.
	for(int i=0;i<3;i++)
		if(top(&a[i]) == 1)
			return i;
}

int enKucukDisk(){ 
	int ekDisk = 100;
	int ekDirek = 0;
	for(int i=0;i<3;i++)
		if(top(&a[i]) < ekDisk && top(&a[i]) > 1){ //1 numaralı en küçük diskten sonraki en küçük diski bulur.
			ekDisk = top(&a[i]);
			ekDirek = i;
		}
	return ekDirek;
}

int oynarMi(yigin * direk1, yigin * direk2){ //Verilen iki direk arasındaki disk hareketinin mümkün olup olmadığına bakar.
	if(direk2 -> sayac <= 0)             //Ya hedef direkte hiç disk yoktur ya da hedef direkteki disk, oynatmak istediğimiz
		return 1;                    //direkteki diskten küçüktür. 
	if(top(direk1) < top(direk2))
		return 1;
	return 0;
}

int oyunBittiMi(){ //Oyunun başlangıcında disklerin bulunduğu 0 numaralı direkte hiç disk kalmaması ve diğer iki direkten birisinde
	if(a[0].sayac <= 0 && a[1].sayac == 3)  //3 diskinde bulunması durumunu kontrol eder.
		return 1;
	if(a[0].sayac <= 0 && a[2].sayac == 3)
		return 1;
	return 0;
}

void print(){  //Disk durumlarını ve adım sayısını yazdırır.
	printf(" %d. adim \n",adim);
	for(int i=0;i<3;i++){
		printf("%d.direk :",i);
		for(int j=0;j<a[i].sayac;j++){
			printf("%d \t",a[i].veri[j]);
		}
		printf("\n");
	}
}

void oyna(yigin * kimden, yigin * kime){  //Bir direkten diğer direğe diski oyantır.Adım değeri artar.Her oyamadan sonra direklerin durumu basılır 
	push(kime,pop(kimden));
	adim++;
	print();
}


int main(){
	for(int i=0;i<3;i++)
		a[i].sayac = 0; //bütün yığınların sayaçları 0 yapıldı.Boş yapıldı.
	for(int i=3;i>0;i--)
		push(&a[0],i); //İlk 3 disk 0 numaralı yığına(direğe) yerleştirildi.Oyunun başlangıç durumu.
	print(); //Başlangıç durumu ekrana basılır.
	while(!oyunBittiMi()){
		int kimden = birinciDisk();
		int kime = kimden;
		printf("kimden :%d kime :%d \n",kimden,kime);
		while(!oynarMi(&a[kimden],&a[kime])){
			kime++;
			if(kime > 2)
				kime = 0;
		        printf("kimden :%d kime :%d \n",kimden,kime);
		}
		printf("kimden :%d kime :%d \n",kimden,kime);
		oyna(&a[kimden],&a[kime]);
		if(oyunBittiMi())
			break;
		kimden = enKucukDisk();
		kime = kimden;
		while(!oynarMi(&a[kimden],&a[kime])){
			kime++;
			if(kime > 2)
				kime = 0;
		}
		oyna(&a[kimden],&a[kime]);
	}
	printf("oyun bitti\n");		
}
