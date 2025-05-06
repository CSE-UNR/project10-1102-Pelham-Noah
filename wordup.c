//Noah Pelham
//Project 10
//*make wordle*
//library
#include <stdio.h>
//macros
#define ROW 10
#define COL 45
//functions/ convert to lowercase if their are any uppercase/ check if guess is right/ repeat 6 times, or if guess isnt 5 letters or only letters, or guess is correct/
void word(int row1, int col1, char arr1[][col1]);
void guess(int row2, int col2, char arr2[][col2]);
void check(int row3, int col3, char arr3[][col3], int i3);
void convert(int row4, int col4, char arr4[][col4], int i4);
//later/ display previous guesses/ display correct letters as uppercase/ display correct letters in wrong place with an arrow underneath/

//main
int main(){
//variables*no global variables*
char guessarr[ROW][COL];
//code
	word(ROW, COL, guessarr);
	guess(ROW, COL, guessarr);
	return 0;
}
//modules
void word(int row1, int col1, char arr1[][col1]){
FILE* fp;
	fp = fopen("mystery.txt","r");
		if (fp == NULL){
			printf ("cant read\n");
			return;
		}
		int rows = 0;
		while (fscanf (fp, "%s", arr1[rows]) == 1){
			rows++;
		}
	fclose(fp);
}
void guess(int row2, int col2, char arr2[][col2]){
	for (int i = 1; i < 7; i++){
		
		if (i < 7){
			printf ("GUESS %d! Enter your guess: ", i);
			scanf ("%s", arr2[i]);
			//check function call
			check(ROW, COL, arr2, i);
			//convert to lowercase
			convert(ROW, COL, arr2, i);
			//check correctness
			
			//check game state
		}
		else {
			printf ("FINAL GUESS : ");
			scanf ("%s", arr2[i]);
			//check function call
			check(ROW, COL, arr2, i);
			//convert to lowercase
			convert(ROW, COL, arr2, i);
			//check correctness
			
			//check game state
		}
		
		
	}
}
void check(int row3, int col3, char arr3[][col3], int i3){
	int lettercount;
	int check3;
	do{
		check3 = 0;
		for (int coli = 0; arr3[i3][coli] != '\0'; coli++){
			lettercount++;
		}
		if (lettercount != 5){
			printf ("Your guess must be 5 letters long.");
		}
		//compare to lower&uppercase, initialize 2darray with alphabet
		char alphabet[][27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz"}
		//*ask how to do, something weird with the if else*
		else if (arr3[i3] != alphabet[0] || arr3[i3] != alphabet[1]){
			printf ("Your guess must contain only letters.");
		}
		else if (lettercount != 5 || arr3[i3] != alphabet[0] || arr3[i3] != alphabet[1]){
			printf ("\n");
			printf ("Please try again: ");
			scanf ("%s", arr3[i3]);
			check3 = 1;
		}
	}while(check3 == 1);
}
//convert to lowercase
void convert(int row4, int col4, char arr4[][col4], int i4){
	char alphabet[][27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz"}
	for (int coli = 0; arr4[i4][coli] != '\0'; coli++){
		if (arr[i4][coli] == alphabet[0]){
			arr[i4][coli] = alphabet[1];
		}
	}
}
//check for correct position, check for correct letter

//display for game state/ win/ loss/ correct letters and position
