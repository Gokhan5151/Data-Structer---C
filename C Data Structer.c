#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Veri{
	char * veri;
	int CatID;
	struct Veri * next;
}Veri;
typedef struct Kategori{
	int KategoriID;
	char * KategoriName;
	struct Kategori * nextCat;
}Kategori;
Kategori * AddCat(Kategori * cat,char * name){
	    Kategori *currCat=cat;
		Kategori * newCat=(Kategori *)malloc(sizeof(Kategori));
		newCat->KategoriName=name;
		
		newCat->nextCat=NULL;
		if(currCat==NULL){
			newCat->KategoriID=1;
			currCat=newCat;
			return newCat;
		
		}else{
		
			while(currCat->nextCat!=NULL){
				currCat=currCat->nextCat;
			
			}
			newCat->KategoriID=currCat->KategoriID+2;
			currCat->nextCat=newCat;
			return cat;
	
		}
	
}
Veri * addData(Veri * dat,char * data,int catID){
	Veri * dataNew=(Veri *)malloc(sizeof(Veri));
	Veri * currData=dat;
	dataNew->CatID=catID;
	dataNew->veri=data;
	dataNew->next=NULL;
	if(currData==NULL){
		return dataNew;
	}else{
		while(currData->next!=NULL){
			currData=currData->next;
		}
		currData->next=dataNew;
		return dat;
	}
	
}
void list_data(Veri * veriler,int ID){
	Veri * iter=veriler;
	while(iter!=NULL){
	if(iter->CatID==ID){
		printf("-%s",iter->veri);
		printf("\n");
	}
	iter=iter->next;
	}
}
int main(int argc, char *argv[]) {
	Kategori * kategori=NULL;
    Veri * veriler=NULL;
    kategori=AddCat(kategori,"Kitap");
    kategori=AddCat(kategori,"Makale");
    kategori=AddCat(kategori,"Yapay Zeka");
  
    veriler=addData(veriler,"Ucak",1);
    veriler=addData(veriler,"Dunya",3);
    veriler=addData(veriler,"Saglik",3);
    list_data(veriler,1);




	
	return 0;
}
