#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;

/*
Structure describing a word entry in the dictionary class
*/
typedef struct entry{ 
	int count;
	WORD w;
	struct entry *nextWord = NULL;
} ENTRY;

class Dictionary{

DICT dictionary;
int word_count;

public:

Dictionary(){ // Constructor
	word_count = 0;
}
	
ENTRY *LocateWord(WORD);
BOOL FullDictionary(void);
BOOL InsertWord(WORD);
WORD GetWords(void);
void DumpDictionary(void);
BOOL CompareWords(WORD, WORD);
void SortWords(void);

WORD word;
ENTRY *head;
head = new entry;

};

// adds word to dictionary, if word cant be added returns false, else returns true
BOOL Dictionary::InsertWord(WORD word)
{
/* 
IF THERE ARE NO WORDS IN THE LIST, ADD THE ENTRY AND INITIALIZE A HEAD POINTER.
RETURN 1. BECAUSE IT IS THE FIRST. WE HAVE NOTHING TO DO WITH IT AFTERWARD.

*/	if(word_count ==0){	 
		head = word;
		count++;
		word_count++;
		return 1;
	} 
	int index = LocateWord(word);
	if( index != -1) word.count++;//(freq of new word will inc to 1 )

	else if(FullDictionary() == 1) return 0;// if dict is full, cant add
	else{
		entry *nextWord = word;		// if dict isnt, then link new word.

		dictionary[word_count] = word;
		count[word_count]++;
		word_count++;
		return 1;
	}				
}

// Will sort dictionary and display the contents
void Dictionary::DumpDictionary() {
	int numCount = 1;
	SortWords();

	for( int i = 0; i < word_count; i++){
		printf("%3d : %s", numCount++,dictionary[i].c_str());

		for(int j = 0; j < (30 - dictionary[i].length()); j++)
			cout << " ";

		 cout << count[i] << endl;
	}
}

/*
retrieves next word in input stream. word defined as ass#1. 
returns a WORD or empty string ( if no more words in input stream.
*/
void Dictionary::GetWords(){

	WORD word;
	char ch;
	BOOL neww;

	while(cin.good()){


		ch = cin.get();

		if(isalpha(ch)){

			ch = tolower(ch);
			word += ch;
			neww = 0;
		}else{

			neww = 1;
		}

		if(neww == 1){

			InsertWord(word);
			word.clear();
		}
	}		
}



//if full, return 1, else 0
BOOL Dictionary::FullDictionary() {
	if(word_count == MAX) return 1;
	else return 0; 
}

// determine if dictionary comtains word. if yes, return position, else return val < 0
ENTRY Dictionary::*LocateWord(WORD word) {
	for(int *i = head; i < MAX; i++) 
		if(i == word) return i;

	return -1;

}

BOOL Dictionary::CompareWords(WORD word1, WORD word2){
	if(word1<word2) return 1;
	else return 0;
}

void Dictionary::SortWords(){
	int index = 1;
	int tmpCount;
	WORD tmpWord;

	while(index < word_count){

		int i = index;
		while(i > 0){

			if(CompareWords(dictionary[i], dictionary[i-1])){
				tmpWord = dictionary[i-1];
				tmpCount = count[i-1];

				dictionary[i-1] = dictionary[i];
				count[i-1] = count[i];

				dictionary[i] = tmpWord;
				count[i] = tmpCount;

				i--;

			} else
				break;
		}

		index++;		
	}
}

