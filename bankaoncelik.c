
 
#include<conio.h>	
#include<stdio.h>
#include<stdlib.h>     
#include<string.h>		
 
struct kayitlar  {   
    char numara[20];
    int oncelik;
    struct kayitlar *next;
    
}*front, *rear, *temp;

void yazdir()                     
{
    int i;
    if(front==NULL)
    {
        printf("\nKuyruk Su Anda Bos !");      
		return;
    }
    struct kayitlar *der=front;  
    printf("\nSirada Bekleyen Dusteriler:\n\n");
   
    while(der!=NULL)
    {
        printf("\n\nOncelik Numarasi: %d",der->oncelik);
        printf("\n\n Adi: %s",der->numara); 
        der=der->next; 
    }
   
    printf("\n\n");  
    printf("-----------------------------------------------");
}

    
void bank(int oncelik,char *numara)	
{   
    struct kayitlar* newNode=(struct kayitlar*)malloc(sizeof(struct kayitlar)); 
    newNode->oncelik=oncelik; 
    strcpy(newNode->numara,numara); 
    newNode->next=NULL; 
    struct kayitlar *gecici; 
    if(front==NULL)
        front=rear=temp=newNode; 
        else if(newNode->oncelik>=rear->oncelik)
        {
            rear->next=newNode; 
            rear=newNode; 
            return;
        }
            else if(newNode->oncelik>temp->oncelik) 
        {
            
            for(;;) 
            {
                temp=temp->next; 
                if(gecici->oncelik<newNode->oncelik&&temp->oncelik>newNode->oncelik)
                {
                    gecici->next=newNode; 
                    newNode->next=temp; 
                    temp=gecici=front;
                    break;
                }
                else if(gecici->oncelik<newNode->oncelik&&temp->oncelik==newNode->oncelik)
                {
                    while(temp->oncelik==newNode->oncelik)
                    {
                        gecici=temp; 
                        temp=temp->next; 
                    }
                    gecici->next=newNode; 
                    newNode->next=temp; 
                    break;
                }
                else
                gecici=temp; 
            }
            temp=gecici=front;
        }        
        else if(newNode->oncelik<temp->oncelik)
        {
            newNode->next=front; 
            front=temp=newNode;
            return;
        }
        else if(newNode->oncelik==temp->oncelik)
        {
            while(newNode->oncelik==temp->oncelik)
            {
                gecici=temp; 
                temp=temp->next; 
            }
            gecici->next=newNode; 
            newNode->next=temp;                                                                           
            temp=gecici=front;
            return;
        }
}

     
void musterisil()
{
    if(front==NULL)
    {
    printf("Baska Musteri Yok!\n");
    return;
    }
    else
    {
        struct kayitlar *temp=front; 
        front=front->next; 
        printf("\nSiradaki Musteri = \n\n");
        printf("Oncelik Degeri:%d\n",temp->oncelik);
        printf("\nKullanici Numarasi: %s\n",temp->numara);
        free(temp); 
    }
}
int main()
{
    int sec, oncelik; 
    char numara[20]; 
    front=rear=NULL;
    int i; 
    printf("Oncelik Siralamasi : 0 > 1 > 2 \n");
      
    for(i=0 ; ;i++)   
    {
        printf("\n 1. Yeni Musteri Kayit"); 
        printf("\n 2. Kalan Musteriler");
        printf("\n 3. Musteri Silme / Siradaki Musteriyi Iste");
        printf("\n 4. Cikis");
     
        printf("\n Lutfen Seciminizi Yapiniz :");
        scanf("%d",&sec); 
        printf("\n\n\n\n\n");
     
        switch(sec) 
        {
            case 1:
                printf("0-)VIP Musteri \n");
                printf("1-)Yuksek Musteri\n");
                printf("2-)Standart Musteri\n");
                
                
                printf("\nLutfen islem yapmak icin oncelik sirasini seciniz : ");
            	    scanf("%d",&oncelik);
                if(oncelik<100){
					 if(oncelik>2) 
                {
                	printf("\n\n\nYanlis oncelik numarasi\n\n\n");
                	break;
				}
                printf("Kullanici Numarasi: ");
                scanf("%s",numara);
                bank(oncelik,numara);
                yazdir();
                break;
                }
                
               
			case 2:
                yazdir();
                break;
            case 3:
            	musterisil();
                break;
                
            case 4:
                printf("Tesekkurler, Isleminiz Sonlandirilmistir ...");
                
			default:
				printf("\n\n\nHatali islem");
				getch();
                
        
             
        }
    }
}
