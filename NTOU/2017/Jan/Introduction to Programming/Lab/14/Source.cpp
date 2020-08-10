#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct borrowerInfo {
	char borrowerID[12], name[20];
	int count;
};

struct bookInfo {
	char bookID[12], title[80], author[80];
	int count;
};

struct dateInfo {
	int year, month, day;
};

struct circulateInfo {
	borrowerInfo *borrower;
	bookInfo *book;
	dateInfo borrowDate, dueDate, returnDate;
};

void parseBorrowerData(borrowerInfo *bp, char *line) {
	char *strp;
	strp = strtok(line, "\t"); if (strp == NULL) { printf("@@ no borrower ID\n"); exit(0); }
	strcpy(bp->borrowerID, strp);
	strp = strtok(NULL, "\t");//if NULL print error
	strcpy(bp->name, strp);
	bp->count = 0;
}
void printfBorrowers(borrowerInfo borrower) {
	printf("Borrower ID: %s, Name: %s\n", borrower.borrowerID, borrower.name);
}

void creatBook(bookInfo *bp, char *line) {
	char *strp;
	strp = strtok(line, "\t"); if (strp == NULL) { printf("@@ no book ID\n"); exit(0); }
	strcpy(bp->bookID, strp);
	strp = strtok(NULL, "\t");//if NULL print error
	strcpy(bp->title, strp);
	strp = strtok(NULL, "\t");//if NULL print error
	strcpy(bp->author, strp);
	bp->count = 0;
}

void printBookData(bookInfo book) {
	printf("Book ID : %s\n", book.bookID);
	printf("	title : %s\n", book.title);
	printf("	author : %s\n", book.author);
}

/*void borrow(circulateInfo *record, borrowerInfo br[], int brsize, bookInfo book[], int booksize){
int i;
char borrowerID[20], bookID[20];
printf("Input the borrower ID: ");
scanf("%s", borrowerID);
for (i = 0; i < brsize; i++){
if (br[i].borrowerID == borrowerID)
record->borrower = &br[i];
}
printf("Input the boook ID: ");
scanf("%s",bookID);
for (i = 0; i < booksize; i++){
if (book[i].bookID == bookID)
record->book = &book[i];
}
printf("Input the borrowing date (year/month/day): ");
scanf("%d/%d/%d", &record->borrowDate.year, &record->borrowDate.month, &record->borrowDate.day);
printf("Input the due date (year/month/day): ");
scanf("%d/%d/%d", &record->dueDate.year, &record->dueDate.month, &record->dueDate.day);
printf("A circulation record has been created.\n\n");
record->returnDate.year = 0;
record->returnDate.month = 0;
record->returnDate.day = 0;
}*/
void returnData(circulateInfo *record) {
	printf("Input the returning date (year/month/day): ");
	scanf("%d/%d/%d", &record->returnDate.year, &record->returnDate.month, &record->returnDate.day);
	printf("A book has been returned.\n\n");
}
int checkborrower(int recordTotal, circulateInfo record[]) {
	char borrowerID[20], bookID[20];
	int i;
	printf("Input the borrower ID: ");
	scanf("%s", borrowerID);
	printf("Input the book ID: ");
	scanf("%s", bookID);
	for (i = 0; i < recordTotal; i++) {
		if (record[i].borrower->borrowerID == borrowerID && record[i].book->bookID);
		return i;
	}
	return -1;
}

/*void creatRecordData(circulateInfo *record, char *str) {
	strcpy(record->borrower->borrowerID, strtok(str, "\t"));
	strcpy(record->book->bookID, strtok(NULL, " \t"));
	record->borrowDate.year = atoi(strtok(NULL, "/"));
	record->borrowDate.month = atoi(strtok(NULL, "/"));
	record->borrowDate.day = atoi(strtok(NULL, "\t"));
	record->dueDate.year = atoi(strtok(NULL, "/"));
	record->dueDate.month = atoi(strtok(NULL, "/"));
	record->dueDate.day = atoi(strtok(NULL, "\t"));
	record->returnDate.year = atoi(strtok(NULL, "/"));
	record->returnDate.month = atoi(strtok(NULL, "/"));
	record->returnDate.day = atoi(strtok(NULL, "\t"));
}*/

int main() {
	bookInfo book[50];
	borrowerInfo borrower[20];
	circulateInfo record[200];
	int bookTotal = 0, borrowerTotal = 0, recordTotal = 0;
	int action = 1, countBorrowers = 0, countBooks = 0, i = 0, check;
	char dataName[20], buf[400]/*one line data*/;
	int k;
	char borrowerID[20], bookID[20];
	FILE *fpt;
	while (action != 0) {
		printf("Menu of NTOU CSE Library Circulation System\n"
			"1. Borrow a book.\n"
			"2. Return a book.\n"
			"3. Print all the borrowers.\n"
			"4. Print all the books.\n"
			"5. Print all the circulation records.\n"
			"6. Import borrower data.\n"
			"7. Import book data.\n"
			"8. Import circulation data.\n"
			"0. Exit.\n"
			"Please choose one action : \n");
		scanf("%d", &action);
		switch (action) {
		case 6:
			printf("Input the file name of borrower data: ");
			scanf("%s", dataName);
			fpt = fopen(dataName, "r");
			while (fgets(buf, sizeof(buf), fpt) != NULL) {
				parseBorrowerData(&borrower[countBorrowers], buf);
				countBorrowers++;
			}
			fclose(fpt);
			printf("%d borrowers have been created.\n", countBorrowers);
			printf("\n");
			break;
		case 3:
			printf("\nData of all borrowers:\n");
			while (i < countBorrowers) {
				printfBorrowers(borrower[i]);
				i++;
			}
			printf("\n");
			break;
		case 7:
			printf("Input the file name of book data : ");
			scanf("%s", dataName);
			fpt = fopen(dataName, "r");
			while (fgets(buf, sizeof(buf), fpt) != NULL) {
				creatBook(&book[countBooks], buf);
				countBooks++;
			}
			fclose(fpt);
			printf("%d books have been created.\n\n", countBooks);
			break;
		case 4:
			i = 0;
			printf("\nData of all books:\n");
			while (i < countBooks) {
				printBookData(book[i]);
				i++;
			}
			printf("\n");
			break;
		case 1:
			printf("Input the borrower ID: ");
			scanf("%s", borrowerID);
			for (i = 0; i < countBorrowers; i++) {
				if (strcmp(borrower[i].borrowerID, borrowerID) == 0)
					record[recordTotal].borrower = &borrower[i];
			}
			printf("Input the boook ID: ");
			scanf("%s", bookID);
			for (i = 0; i < countBooks; i++) {
				if (strcmp(book[i].bookID, bookID) == 0)
					record[recordTotal].book = &book[i];
			}
			printf("Input the borrowing date (year/month/day): ");
			scanf("%d/%d/%d", &record[recordTotal].borrowDate.year, &record[recordTotal].borrowDate.month, &record[recordTotal].borrowDate.day);
			printf("Input the due date (year/month/day): ");
			scanf("%d/%d/%d", &record[recordTotal].dueDate.year, &record[recordTotal].dueDate.month, &record[recordTotal].dueDate.day);
			printf("A circulation record has been created.\n\n");
			record[recordTotal].returnDate.year = 0;
			record[recordTotal].returnDate.month = 0;
			record[recordTotal].returnDate.day = 0;
			recordTotal++;
			break;
		case 2:
			check = checkborrower(recordTotal, record);
			if (check == -1) break;
			returnData(&record[check]);
			break;
		case 5:
			i = 0;
			while (i < recordTotal) {
				printf("%s	%s	%d/%d/%d	%d/%d/%d	%d/%d/%d\n",
					record[i].borrower->borrowerID,
					record[i].book->bookID,
					record[i].borrowDate.year,
					record[i].borrowDate.month,
					record[i].borrowDate.day,
					record[i].dueDate.year,
					record[i].dueDate.month,
					record[i].dueDate.day,
					record[i].returnDate.year,
					record[i].returnDate.month,
					record[i].returnDate.day);
				i++;
			}
			printf("\n");
			break;
		case 8: 
			printf("Input the file name of book data : ");
			scanf("%s", dataName);
			fpt = fopen(dataName, "r");
			i = 0;
			while (fgets(buf, sizeof(buf), fpt) != NULL) {
				strcpy(borrowerID, strtok(buf, "\t"));
				for (k = 0; k < countBorrowers; k++) {
					if (strcmp(borrowerID, borrower[k].borrowerID) == 0) {
						record[i].borrower = &borrower[k];
					}
				}
				strcpy(bookID, strtok(NULL, "\t"));
				for (k = 0; k < countBooks; k++) {
					if (strcmp(bookID, book[k].bookID) == 0) {
						record[i].book = &book[k];
					}
				}
				record[i].borrowDate.year = atoi(strtok(NULL, "/"));
				record[i].borrowDate.month = atoi(strtok(NULL, "/"));
				record[i].borrowDate.day = atoi(strtok(NULL, "\t"));
				record[i].dueDate.year = atoi(strtok(NULL, "/"));
				record[i].dueDate.month = atoi(strtok(NULL, "/"));
				record[i].dueDate.day = atoi(strtok(NULL, "\t"));
				record[i].returnDate.year = atoi(strtok(NULL, "/"));
				record[i].returnDate.month = atoi(strtok(NULL, "/"));
				record[i].returnDate.day = atoi(strtok(NULL, "\t"));
				i++;
			}
			printf("%d circulation records have been created.\n\n", i);
			break;
		default:
			break;
		};
	}
	printf("\nThanks for using NTOU CSE Library Circulation System!!");
	return 0;
}