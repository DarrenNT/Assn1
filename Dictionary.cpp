#include <cstdio>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define rowNum 5
#define colNum 12
#define MAX 128

char ch;
int newLine = 0;
char array[rowNum][colNum];
int count[5];
int numWord = 0;
int i = 0;
int foundWord = 0;
char buffer[MAX];
//strlen(buffer)
/*
	Author : Darren Tam
	Assignment #1
	Purpose : To allow the user to input a file with text in it
		  and return the frequency of words based on the text
		  in the order they were given.
*/

int wordLength(char x[]){
	int num = 0;
	for( int i = 0; i < MAX; i++){
		if(x[i] == '\0'){
			num = i+1;
			break;
		}
	}
	return num;
}

int compare(char x[], char y[]){
	int check = 0;
	for(int j = 0; j < colNum; j++){
		if(x[j] != y[j]){
			check = -1;
		}
	}
	return check;
}

int importDict(){ //A function that puts words into the Dictionary and counts frequency.

while( cin.good() ){
	ch = cin.get();
	if( isalpha(ch) ){
		buffer[i] = ch;
		i++;
		newLine = 1;
	}else{
		if(newLine){
			buffer[i] = '\0';
			if(i >= 13){
				cout << "The string " << buffer << " is too big" << endl;
			}else if(numWord >= 5){
				cout << "Some word(s) was skipped" << endl;
			}else{
			//Compares buffer array with the dictionary array to check if
			//the word is already inside the dictionary and increases count if so.
				for(int j = 0; j < numWord; j++){
					if(strcmp(buffer, array[j]) == 0){ //ok
						count[j]++;
						foundWord = 1;
					}
				}

			//If there are no duplicates and its not the first word
			//then it adds the word here.
				if(!foundWord && (numWord > 0)){ //hit
					for(int x = 0; x < wordLength(buffer); x++){
						if(buffer[x] != '\0'){
						array[numWord][x] = buffer[x];
						}else{
							count[numWord]++;
							break;
						}
					}
				numWord++;
				}
			}

			//Prints the first word into the Dictionary
				if(numWord == 0){ //ok
					for(int j = 0; j < 1; j++){
						for(int x = 0; x < wordLength(buffer); x++){
							if(buffer[x] != '\0'){
							array[j][x] = buffer[x];
							}else{
								break;
							}
						}
					}
					count[0]++;
					numWord++;
				}
			//Resets variables here so while loop can go through again.
			i = 0;
			newLine = 0;
			foundWord = 0;
		}
	}
	
}
return 0;
}

void readDict(){ //Prints out the Dictionary
	for(int j = 0; j < numWord; j++){
		printf("Word: %-13s | Frequency: %-2i"  , array[j], count[j]);
		cout << endl;
	}
}

int main(){

importDict();
readDict();

}
