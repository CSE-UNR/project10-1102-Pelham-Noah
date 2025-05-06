//Noah Pelham
//Project 10
//*make wordle*
//library
#include <stdio.h>
//macros
#define ROW 10
#define COL 45
//functions/ store word in 2darray/ prompt for guess, store guess/ check if guess is 5 letters/ check if guess is only letters/ convert to lowercase if their are any uppercase/ check if guess is right/ repeat 6 times, or if guess isnt 5 letters or only letters, or guess is correct/

//later/ display previous guesses/ display correct letters as uppercase/ display correct letters in wrong place with an arrow underneath/

//main
int main(){
//variables*no global variables*
char arr[ROW][COL];
FILE* fp;
int cols;
//code*turn to functions after you sort logic/display and input can stay in main*
	//stores word
	fp = fopen("mystery.txt","r");
		if (fp == NULL){
			printf ("cant read\n");
			return 0;
		}
		int rows = 0;
		while (fscanf (fp, "%s", arr[rows]) == 1){
			rows++;
		}
	fclose(fp);
	//function call 6 times or when correct
	for (int i = rows; i < rows + 6; i++){
		if (i < 6){
			printf ("GUESS %d! Enter your guess: ", i);
			scanf ("%s", arr[i]);
			//function if won
			if (arr[i] == arr[0]){
				printf ("You won in %d guess!\n", i);
			}
			//
			//checks length
			for (int rowi = i; rowi < ROW; rowi++){
			for (int coli = 0; arr[rowi][coli] != '\0'; coli++){
				cols++;
			}
			}
			}
			else if (cols != 5){
				printf ("Your guess must be 5 letters long.\n");
				printf ("Please try again: ");
				scanf ("%s", arr[i]);
				//function if won
				if (arr[i] == arr[0]){
					printf ("You won in %d guess!\n", i);
				}
			}
			//
		else {
			printf ("FINAL GUESS : ");
			scanf ("%s", arr[i]);
			//function if won
			if (arr[i] == arr[0]){
				printf ("You won in %d guess!\n", i);
			}
			//
			//checks length
			for (int rowi = i; rowi < ROW; rowi++){
			for (int coli = 0; arr[rowi][coli] != '\0'; coli++){
				cols++;
			}
			}
			else if (cols != 5){
				printf ("Your guess must be 5 letters long.\n");
				printf ("Please try again: ");
				scanf ("%s", arr[i]);
				//function if won
				if (arr[i] == arr[0]){
					printf ("You won in %d guess!\n", i);
				}
			}
			//
		}
		
		
	}
	return 0;
}
//modules
