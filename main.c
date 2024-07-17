//200202002 Berkay MALKOÇ 200202087 Ferhat ARSLAN
#include <stdio.h>
#include <stdlib.h>
#define BYT 13

int inissira[BYT];
int onsira[BYT];
int ondeki=-1,arkadaki=-1,son=-1,dn=-1,saySaat=1;
int dizi[84],b,p=1,t=1,s=1,temp,bir,iki,x=1,f,eln=0,oln=0,i=1,k=1;
int oncelikID[28],ucakID[28],istenenSaat[28],ertelenmeSaati[28],istenenSaat2[28],newOncelik[28],elenen[10],elenen1[10];

void dosyadanOku(){
    FILE *dosya = fopen("input.txt","r+");
    dizi[0]=0;
    oncelikID[0]=0;
    ucakID[0]=0;
    istenenSaat[0]=0;
    while(feof(dosya)==0){
        fscanf(dosya,"%d",&b);
        dizi[x]=b;
        x++;
    }
    for(int n=1; n<x; n++){
        if(n%3==1){
            oncelikID[p]=dizi[n];
            p++;
        }
        if(n%3==2){
            ucakID[s]=dizi[n];
            s++;
        }
        if(n%3==0){
            istenenSaat[t]=dizi[n];
            t++;
        }
    }

    printf(" Oncelik ID  Ucak ID  Istenen Saat\n");
    for(int k=1; k<p; k++){
        printf("   %d          %d         %d\n",oncelikID[k],ucakID[k],istenenSaat[k]);
    }
    printf("\n");
    printf("veriler okunuyor...");
    sirala();
    fclose(dosya);
}

void kuyrEkle(int istenenSaat[],int oncelikID[],int ucakID[],int ertelenmeSaati[]){
   int a=1;
   int d;
   FILE*dosya3=fopen("bekleme.txt","w");
   newOncelik[0]=0;
   int tut;

   for(x=1; x<=28; x++){
        ertelenmeSaati[x]=0;
    }

    if(arkadaki==BYT-1){
        printf("kuyruk dolu\n");
    }

    else{
    for(saySaat=1;saySaat<=24;saySaat++){
    dn:
    for(a=1;a<=28;a++){
       if(ertelenmeSaati[a]==3){

            ondeki=0;
            arkadaki++;
            inissira[arkadaki]=ucakID[a];
            dn=0;
            son++;
            onsira[son]=oncelikID[a];
            tut=a;
            if(saySaat<=24)
            printf("%d numarali ucak saat %d 'de inis yapti (bekleme suresi: %d) \n",ucakID[a],saySaat,ertelenmeSaati[a]);
            fprintf(dosya3,"%d  ",ertelenmeSaati[a]);
            for(d=1;d<=28;d++){
            if(istenenSaat[d]==saySaat){
                ertelenmeSaati[d]++;
                istenenSaat[d]++;
            }
        }
        ertelenmeSaati[tut]=-1;
        istenenSaat[tut]=-1;
        a=0;
        saySaat++;
        goto dn;
       }
    }
    for(a=1;a<=28;a++){
        if(istenenSaat[a]==saySaat){
            ondeki=0;
            arkadaki++;
            inissira[arkadaki]=ucakID[a];
            dn=0;
            son++;
            onsira[son]=oncelikID[a];
            tut=a;
            if(saySaat<=24&&ertelenmeSaati[a]<4){
                printf("%d numarali ucak saat %d 'de inis yapti (bekleme suresi: %d)\n",ucakID[a],saySaat,ertelenmeSaati[a]);
                fprintf(dosya3,"%d  ",ertelenmeSaati[a]);
            }
            if(saySaat>24){
                    elenen1[oln]=ucakID[a];
            printf("\n%d numarali ucag kapasite doldugu icin inis yapamadi\n",ucakID[a]);
            oln++;
            }

            for(d=tut+1;d<=28;d++){
            if(istenenSaat[d]==saySaat){
                ertelenmeSaati[d]++;
                istenenSaat[d]++;
            }
            if(ertelenmeSaati[d]>=4){
                    elenen[eln]=ucakID[d];

                for(int m1=d;m1<28;m1++){
                    onsira[m1]=onsira[m1+1];
                    ertelenmeSaati[m1]=ertelenmeSaati[m1+1];
                    inissira[m1]=inissira[m1+1];
                    ucakID[m1]=ucakID[m1+1];
                    oncelikID[m1]=oncelikID[m1+1];
                    istenenSaat[m1]=istenenSaat[m1+1];
                    istenenSaat2[m1]=istenenSaat2[m1+1];
                }
            eln++;
            }
        }a=0;
        saySaat++;
        goto dn;
        }
   }
   fprintf(dosya3,"%d",ertelenmeSaati[a]);
}
}
for(int i=0;i<eln;i++){
    printf("\n%d numarali ucak 3'ten fazla ertelenme sebebi ile farkli havalimanina yonlendirildi.\n",elenen[i]);
}
fclose(dosya3);
yazdir(inissira);
}

void sirala(){
    for (x = 0 ; x < ( t - 1 ); x++){
        for (int y = 1 ; y < t- x - 1; y++){
            if (oncelikID[y] > oncelikID[y+1]){
                temp        = oncelikID[y];
                oncelikID[y]   = oncelikID[y+1];
                oncelikID[y+1] = temp;
                bir=ucakID[y];
                ucakID[y]   = ucakID[y+1];
                ucakID[y+1] = bir;
                iki=istenenSaat[y];
                istenenSaat[y]   = istenenSaat[y+1];
                istenenSaat[y+1] = iki;

            }

            else if(oncelikID[y]==oncelikID[y+1]){
                if(ucakID[y]>ucakID[y+1]){
                    bir=0;
                    bir = ucakID[y];
                    ucakID[y] = ucakID[y+1];
                    ucakID[y+1] = bir;
                    iki=istenenSaat[y];
                    istenenSaat[y]   = istenenSaat[y+1];
                    istenenSaat[y+1] = iki;
                }
            }
        }
    }
    printf("herhangi bir tusa basiniz");
    getch();
    system("cls");
    printf("\n oncelik  ucak id  inis saat \n");
    for ( x = 1 ; x <t ; x++ )
        printf(" %d       %d      %d\n", oncelikID[x], ucakID[x], istenenSaat[x]);
        istenenSaat2[0]=0;
    for (int i = 1 ; i <= 28 ; i++){

        istenenSaat2[i] = istenenSaat[i];
    }
    printf("\n---herhangi bir tusa basiniz---");
    getch();
    system("cls");
    kuyrEkle(istenenSaat,oncelikID,ucakID,ertelenmeSaati);
}

int main(){
    printf("Oncelik sirasi:\n1 numarali oncelik: Ambulans ucagi\n2 numarali oncelik: Savas Ucagi\n3 numarali oncelik: Yolcu Ucagi\n4 numarali oncelik: Kargo Ucagi\n");
    dosyadanOku();

    return 0;
}
void yazdir(int inissira[]){  printf("\n---herhangi bir tusa basiniz---");
    getch();
    system("cls");
    int sayacc=0;
    int bekl[25];
    int s=1;
    bekl[0]=0;

    FILE *dosya3=fopen("bekleme.txt","r");
    while(!feof(dosya3)!=NULL){
        fscanf(dosya3,"%d",&f);
        bekl[s]=f;
        s++;
    }
    FILE *dosya2=fopen("output.txt","w");
    if(ondeki==-1)
        printf("kuyruk bos\n");
    else{
        int i;
        printf("\n");
        for(int i=0;i<eln;i++){
    printf("\n%d numarali ucak 3'ten fazla ertelenme sebebi ile farkli havalimanina yonlendirildi.\n",elenen[i]);
}
        for(int m=0;m<oln;m++){
            printf("\n%d numarali ucak havalimani kapasitesi doldugundan Sabiha havalimanina yonlendirildi. \n",elenen1[m]);
        }
        printf("ucak ID               oncelikID              talep saati        bekleme                inis saati          kalkis   \n");
        fprintf(dosya2,"ucak ID        oncelikID      talep saati    bekleme     inis saati     kalkis   \n");
        for(i=1;i<=28;i++)  {
            if(ertelenmeSaati[i]==-1){
                ertelenmeSaati[i]=3;
            }
        }
        for(i=ondeki; i<10; i++){

            fprintf(dosya2,"%6d        %6d       %6d        %6d        %6d       %6d\n",inissira[i],onsira[i],i+1-(ertelenmeSaati[i+1]),bekl[i+1],i+1,i+2);
            printf("%10d         %10d          %10d         %10d            %10d          %10d \n",inissira[i],onsira[i],i+1-(ertelenmeSaati[i+2]),bekl[i+1],i+1,i+2);

            sayacc++;
        }
    }
}
