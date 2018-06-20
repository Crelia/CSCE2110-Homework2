//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classSpell.h"
#include "player.h"
#include "functions.h"

using namespace std;

cspellHash::cspellHash() {
	cnt = 0;

	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new classSpell;
		hashTable[i]->sName = "empty";
		hashTable[i]->sClass = "empty";
		hashTable[i]->sLevel = 0;
		hashTable[i]->next = NULL;
	}
}

int cspellHash::csHash(string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

void cspellHash::addCspell(ofstream& out_s, ifstream& in_s) {
        string name;
        string spclass;
        int level;
        char temp;
        int id;
        cnt++;
        id = cnt;

        while(in_s >> name) { //while you can read the file

                in_s >> spclass;
                in_s >> level;

                int index = csHash(name); //find what bucket to place the card into

                if(hashTable[index]->sName == "empty") { //if empty bucket set item info
                        hashTable[index]->sName = name;
                        hashTable[index]->sClass = spclass;
                        hashTable[index]->sLevel = level;

			//cout << hashTable[index]->sName << "\t\t" << hashTable[index]->sClass << "\t\t" << hashTable[index]->sLevel << endl << endl;
                }
                else { //if the bucket is filled, use chaining and add another item
                        classSpell* ptr = hashTable[index];
                        classSpell* n = new classSpell;
                        n->sName = name;
                        n->sClass = spclass;
                        n->sLevel = level;
                        n->next = NULL;

			//cout << n->sName << "\t\t" << n->sClass << "\t\t" << n->sLevel << endl << endl;

                        while(ptr->next != NULL) { //et next bucket
                                ptr = ptr->next;
                        }
                        ptr->next = n;
                }
        }





//	for(int j = 0; j < tableSize; j++) {
//	cout << hashTable[j]->sName << endl << hashTable[j]->sClass << endl << hashTable[j]->sLevel << endl << endl << endl;
//	}
}

int cspellHash::checkSpell(string pclass, string& spell, int level, int& ccnt) {
	for(int i = 0; i < tableSize; i++) {
		classSpell* ptr = hashTable[i];

		while(ptr != NULL) {

			//cout << ptr->sName << endl;
			//cout << ptr->sClass << endl;
			//cout << ptr->sLevel << endl << endl << endl;

			if(ptr->sClass == pclass) {
				if(ptr->sLevel == level) {
					spell = ptr->sName;
					cout << ptr->sName << " level " << ptr->sLevel << endl;
					ptr = ptr->next;
					ccnt++;
				}
				else {
					ptr = ptr->next;
				}
			}
			else {
			//	cout << ptr->sClass << endl;
				ptr = ptr->next;
			}
		}
	}
}

void cspellHash::findType(string pclass, string& spell, int level) {
	for(int i = 0; i < tableSize; i++) {
		classSpell* ptr = hashTable[i];

		while(ptr != NULL) {
			if(ptr->sClass == pclass) {
				if(ptr->sLevel == level) {
					if(ptr->sName == spell) {
						ptr = ptr->next;
					}
					else {
						spell = ptr->sName;
						return;
					}
				}
				else {
					ptr = ptr->next;
				}
			}
			else {
				ptr = ptr->next;
			}
		}
	}
}

void cspellHash::findSpell(string spell,int& lvl, string& pclass) {

	playerHash pl;
	int ccnt = 0;
	string perclass;

	for(int i = 0; i < tableSize; i++) {
		classSpell* ptr = hashTable[i];

		while(ptr != NULL) {
			if(spell == ptr->sName) {
				lvl = 0;
				lvl = ptr->sLevel;
				if(perclass == ptr->sClass) {}
				if(perclass != ptr->sClass) {ccnt++;}
				pclass = ptr->sClass;
				ptr = ptr->next;
			}
			else {
				ptr = ptr->next;
			}
		}
	}

//	cout << ccnt << endl << endl;

	for(int j = 0; j < tableSize; j++) {
		classSpell* ptr2 = hashTable[j];

		while(ptr2 != NULL) {
			if(spell == ptr2->sName) {
				cout << "Any level " << ptr2->sLevel << " or higher " << ptr2->sClass << " can  also learn " << ptr2->sName << endl << endl;
				ptr2 = ptr2->next;
			}
			else {
				ptr2 = ptr2->next;
			}
		}
	}
}


void cspellHash::checkHighest(string& spell, string pclass) {
	int lvl = 0;

	for(int i = 0; i < tableSize; i++) {
		classSpell* ptr = hashTable[i];

		while(ptr != NULL) {
			if(pclass == ptr->sClass) {
				if(lvl < ptr->sLevel) {
					lvl = ptr->sLevel;
					spell = ptr->sName;
					ptr = ptr->next;
				}
				else {
					ptr = ptr->next;
				}
			}
			else {
				ptr = ptr->next;
			}
		}
	}

	cout << spell << endl;

	for(int j = 0; j < tableSize; j++) {
		classSpell* ptr2 = hashTable[j];

		while(ptr2 != NULL) {
			if(pclass == ptr2->sClass) {
				if(lvl == ptr2->sLevel) {
					if(spell == ptr2->sName) {
						ptr2 = ptr2->next;
					}
					else {
						cout << ptr2->sName << endl;
						ptr2 = ptr2->next;
					}
				}
				else {
					ptr2 = ptr2->next;
				}
			}
			else {
				ptr2 = ptr2->next;
			}
		}
	}
}
