#include<stdio.h>
#include<conio.h>
#include<math.h>
void giris(int no[],int not[], int N);
void siralasonuc(int no[], int not[], int N);
float ortalama(int not[],int N);
int enyuksek(int not[], int N);
int endusuk(int not[], int N);
void siralanumara(int no[], int not[], int N);
double standartsapma(int no[], int not[], int N);
void goruntule(int no[], int not[], int N);
void kucuk(int no[], int not[], int N);
void ortalamaustu(int no[], int not[], int N);
int adet(int not[], int N);


void main()
{
	int OgrNum[BUFSIZ], Not[BUFSIZ];
	int N;
	float ort;
	int sayac=0;
	int max;
	int min;
		printf("Ogrenci sayisini giriniz ?:");
		scanf("%d",&N);
				giris(OgrNum, Not ,N);
				kucuk(OgrNum, Not ,N);
				goruntule(OgrNum, Not ,N);
	ort=ortalama(Not, N);
	printf("Not Ortalamasý:%5.2f\n",ort);
				ortalamaustu(OgrNum, Not ,N);
			sayac=adet(Not, N);
			printf("60'dan kucuk sinav sonucu: %d\n",sayac);
	max=enyuksek(Not,N);
	printf("En yuksek sinav sonucu: %3d \n",max);
	min=endusuk(Not,N);
	printf("En dusuk sinav sonucu:%3d \n",min);
				siralasonuc(OgrNum, Not ,N);
				siralanumara(OgrNum, Not ,N);
	
	printf("Standart sapma: %f",standartsapma(OgrNum, Not ,N) );
	getch();
}
void giris(int no[],int not[], int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("Ogrenci No:");
		scanf("%d",&no[i]);
		printf("%d numarali ogrencinin notu :",no[i]);
		scanf("%d",&not[i]);
	}

}
void goruntule(int no[], int not[], int N)
{
	printf("OgrenciNo\tOgrenciNotu\n");
	for (int i=0; i<N;i++)
		printf("%8d\t %3d\n",no[i], not[i]);
}
float ortalama(int not[],int N)
{
	float t;
	int i;
	t=0;
	for(i=0; i<N; i++)
		t=t+not[i];
	float ort=t/N;
	return ort;
}
void kucuk(int no[], int not[], int N)
{
	int i=0;
	for (i=0; i<N;i++)
	{
	if(not[i]<60)
		printf("60'dan kucuk sinav sonucu::%3d \n Ogrenci Numarasý:%3d\n",not[i],no[i]);
	}
}
void ortalamaustu(int no[], int not[], int N)
{
	float t;
	int k;
	t=0;
	for(k=0; k<N; k++)
		t=t+not[k];
	float ort=t/N;

	int i=0;
	for (i=0; i<N;i++)
	{
	if(not[i]>ort)
		printf("Ortalamayi gecen ogrencinin nosu:%3d\n Ortalamayi gecen ogrencinin notu :%3d\n",no[i],not[i]);
	}

}
int adet( int not[], int N)
{
	int i=0;
	int sayac=0;
	for (i=0; i<N;i++)
	{
		if(not[i]<60)
			sayac++;
	}
	return sayac;
}
int enyuksek(int not[], int N)
{
	int max,i;
	max=not[0];
	for(i=1;i<N;i++)
	{
		if(not[i]>max)
			max=not[i];
	}
	return max;
}
int endusuk(int not[], int N)
{
	int min,i;
	min=not[0];
	for(i=1;i<N;i++)
	{
		if(not[i]<min)
			min=not[i];
	}
	return min;
}
void siralasonuc(int no[], int not[], int N)
 {
	 printf("Notlara gore siralama:\n");
	int   k,i,gecici;
	for(i=0; i<N-1; i++)
    for(k=0; k<N-1; k++)
    if( not[k]<not[k+1] )
	  {
         gecici = not[k];
           not[k] = not[k+1];
         not[k+1] = gecici;
      }
   for(i=0; i<N; i++)
      printf("not:%d no:%d \n ",not[i],no[i]);
 }
void siralanumara(int no[], int not[], int N)
{
	printf("Numaralara gore siralama:\n");
	int   k,i,gecici;
	for(i=0; i<N-1; i++)
    for(k=0; k<N-1; k++)
    if( no[k]<no[k+1] )
	  {
         gecici = no[k];
           no[k] = no[k+1];
         no[k+1] = gecici;
      }
   for(i=0; i<N; i++)
      printf("no:%d not:%d \n ",no[i],not[i]);
}
double standartsapma(int no[], int not[], int N)
{
	double sapma;
	float toplam=0;
	float ort=0.0;
	float t;
	int i;
	t=0;
	for(i=0; i<N; i++)
	{
		t=t+not[i];
		float ort=t/N;
	}
	for(i=0; i<N; i++)
	
		toplam=toplam+pow(ort-not[i],2);
		sapma=sqrt(toplam/N);
	
	return sapma;
}
 
