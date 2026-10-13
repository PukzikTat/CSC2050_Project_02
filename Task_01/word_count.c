#include <stdio.h>


int main(int argc, char *argv[]){
	//Check if there's only two arugment
	if(argc != 2){
		printf("Error: only two arguments\n");
		return 1;
	}

	//Read the file
	FILE *fp = fopen(argv[1], "r");

	//Check NULL
	if(fp == NULL){
		printf("File not open\n");
		return 1;
	}

	//Set up count for every char, line, word
	int ch_count = 0;
	int lines_count = 0;
	int word_count = 0;

	//Get the char on the file until it's End of file
	int ch;
	while((ch = fgetc(fp)) != EOF){

		//Count word
	   	if(ch == ' ' || ch == '\n'){
			word_count++;
		}

		//Count line
		if(ch == '\n'){
			lines_count++;
		}

		//Count every char
		ch_count++;
	}

	//Print all the count and filename
	printf(" %d  %d %d %s \n", lines_count, word_count, ch_count, argv[1]);

	//Close the file
	fclose(fp);	
	return 0;
}
