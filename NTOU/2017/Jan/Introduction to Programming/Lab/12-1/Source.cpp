#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int indexOfList_icmp(char *str, char *list[], int size){
	int n = 0;
	while (n < size){
		if (!_strcmpi(str, list[n])) break;
		n++;
	}
	if (n == size) return -1;
	else return n;
}

int main(){
	int i = 0, j, frequency[1000] = { 0 };
	char *p, *word[1000], document[] = "National Taiwan Ocean University was originally established in 1953 as a junior college for the study of maritime science and technology.\nAfter eleven years, in 1964, we became a maritime college which offered bachelor's and master's degrees in various fields of maritime studies. During this period, funds for running the college came from the Taiwan Provincial Government of the Republic of China.\nIn 1979 the national government took over the funding and we became the National Maritime College. After another decade, in 1989, the college grew into a full-fledged university, National Taiwan Ocean University (NTOU).";
	for (i = 0; i < 1000; i++){
		word[i] = '\0';
	}
	i = 0;
	p = strtok(document, " ().,\n");
	while (p != NULL){
		if (indexOfList_icmp(p, word, i) == -1){//return -1 表示找不到 ，找到則return 出現在world[i]的i
			word[i] = p;
			frequency[i]++;
			i++;
			printf("%d\n", frequency[0]);
		}
		else { 
			word[i] = p;
			frequency[indexOfList_icmp(p, word, i)]++;
		}
		
		p = strtok(NULL, " ().,\n");
	}
	for (j = 0; j < i; j++){
		printf("%s\t\t\t%d\n", word[j], frequency[j]);
	}
	printf("\n");
	return 0;
}