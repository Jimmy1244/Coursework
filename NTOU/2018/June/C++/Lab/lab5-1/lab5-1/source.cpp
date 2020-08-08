#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SaleItem
{
    int size;
    void (*print)(SaleItem *);//之後的printXxx function 都需要傳一個 SaleItem *xxx進去
    unsigned char data[1];
};

struct Book
{
    int size;
    void (*print)(SaleItem *);
    char title[80];
    char author[30];
    char publisher[30];
    char year[5];
    double price;
};
  
void printBook(struct SaleItem *book)
{
    struct Book *bPtr = (struct Book *)book;
  
    printf("Book name is %s\n", bPtr->title);
    printf("     author is %s\n", bPtr->author);
    printf("     publisher is %s\n", bPtr->publisher);
    printf("     price is %f\n\n", bPtr->price);
}
  
struct Magazine
{
    int size;
    void (*print)(SaleItem *);
    char title[80];
    char issue[10];
    char year[5];
    char month[3];
    char publisher[30];
    double price;
};
  
void printMagazine(struct SaleItem *magazine)
{
    struct Magazine *mPtr = (struct Magazine *)magazine;

    printf("Magazine name is %s\n", mPtr->title);
    printf("         issue is %s\n", mPtr->issue);
    printf("         month/year is %s/%s\n", 
            mPtr->month, mPtr->year);
    printf("         publisher is %s\n", mPtr->publisher);
    printf("         price is %f\n\n", mPtr->price);
}
  
struct VCD
{
    int size;
    void (*print)(SaleItem *);
    char title[80];
    char seriesTitle[80];
    char casts[60];
    char year[5];
    char producer[30];
    double price;
};

void printVCD(struct SaleItem * VCD){
	  struct VCD *vPtr = (struct VCD *)VCD;

    printf("VCD name is %s\n", vPtr->title);
    printf("         seriesTitle is %s\n", vPtr->seriesTitle);
    printf("         casts is %s\n", vPtr->casts);
	printf("         year is %s\n", vPtr->year);
    printf("         producer is %s\n", vPtr->producer);
    printf("         price is %f\n\n", vPtr->price);
}

void initialize(int *nItems, struct SaleItem *items[])
{
    struct Book *bPtr;
    struct Magazine*mPtr;
    struct VCD *vPtr;
  
    bPtr = (struct Book*) malloc(sizeof(struct Book)); // 配置
    items[0] = (struct SaleItem *) bPtr; // 強制型態轉換
    bPtr->size = sizeof(struct Book);  // 結構佔記憶體大小
    bPtr->print = printBook;  // 指向列印本結構之函式
    strcpy(bPtr->title, 
	    "Harry Potter and the Prisoner of Azkaban ");
    strcpy(bPtr->author, "J.K. Rowling ");
    strcpy(bPtr->publisher, "Bloomsbury");
    strcpy(bPtr->year, "2000");
    bPtr->price = 7.99;

    mPtr = (struct Magazine*) 
        malloc(sizeof(struct Magazine));
    items[1] = (struct SaleItem *) mPtr;
    mPtr->size = sizeof(struct Magazine);
    mPtr->print = printMagazine;
    strcpy(mPtr->title, "Reader's Digest");
    strcpy(mPtr->issue, "---");
    strcpy(mPtr->year, "2005");
    strcpy(mPtr->month, "03");
    strcpy(mPtr->publisher, 
	    "The Reader's Digest Association, Inc.");
    mPtr->price = 13.5;

    vPtr = (struct VCD*) malloc(sizeof(struct VCD));
    items[2] = (struct SaleItem *) vPtr;
    vPtr->print = printVCD;
    strcpy(vPtr->title, "The Two Towers");
    strcpy(vPtr->seriesTitle, "Lord of the Rings");
    strcpy(vPtr->casts, "Elijah Wood, Ian Mackellen");
    strcpy(vPtr->year, "2003");
    strcpy(vPtr->producer, "Entertainment in Video");
    vPtr->price = 70;

    *nItems = 3;
}

void main()
{
    int nItems;
    struct SaleItem *items[100];
    int i;

    initialize(&nItems, items);

	 for (i=0; i<nItems; i++){
		 (*items[i]->print)(items[i]);
	 }


    for (i=0; i<nItems; i++)
      free(items[i]); // 請注意此處也不需要區分資料的種類

    printf("Press enter to continue...");
    getchar();
}