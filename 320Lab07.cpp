#include <iostream>
#include <fstream>
#include <string>
#include "d_hash.h"
#include "d_hashf.h"

using namespace std;

ifstream& getWord(ifstream& fin, string& w);


int main(){
    string a,b,c;
    ifstream file,file2;
myhash<string,hFstring> hash(1373);
cout << "Input a file for spell checking: ";
cin >> b;
cout << endl;
file.open("dict.dat"); 
while(getline(file,c)){ //goes through each line (getword would be helpful for paragraphs, but each line in dict.dat is its own line, so using getword instead would be
//redundant.)
hash.insert(c);
}
file2.open(b);
string e = "";
cout << "Misspelled words: " << endl << endl;
while(getWord(file2,e)){
if(hash.find(e) == hash.end()){
cout << e << endl;
}
}
file2.close();
file.close();
}

//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}
