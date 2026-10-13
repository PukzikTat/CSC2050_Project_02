#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	//Check argument
	if(argc != 2){
		printf("Error: Need Two arguments\n");
		return 1;
	}

	//Read the file
	FILE *fp = fopen(argv[1], "r");

	//Check NULL
	if(fp == NULL){
		printf("File not open.\n");
		return 1;
	}

	//Set up buffer and buffer's size for getline and cmp
	char *buffer1 = NULL;
	char *buffer2 = NULL;
	size_t bufsize = 0;
	ssize_t character = 0;

	//While it's not getline = -1 then keep the loop for getting every line
	while((character = getline(&buffer1, &bufsize, fp)) != -1){

		//Check if it's different or NULL then print the str
		if(buffer2 == NULL || strcmp(buffer1, buffer2) != 0){
			printf("%s", buffer1);
		}
		
		//Swap the str for comparing after next sentence
		char *temp_file = buffer1;
		buffer1 = buffer2;
		buffer2 = temp_file;
		
	}

	//Free memeory 
	free(buffer1);
	free(buffer2);

	//Close the file
	fclose(fp);

}
