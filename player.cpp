//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "classSpell.h"
#include "functions.h"

using namespace std;

playerHash::playerHash() {
	cnt = 0;

	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new player;
		hashTable[i]->pName = "empty";
		hashTable[i]->pClass = "empty";
		hashTable[i]->pLevel = 0;
		hashTable[i]->next = NULL;
	}
}

int playerHash::pHash(string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

void playerHash::addPlayer(ofstream& out_s, ifstream& in_s) {
        string name;
	string perclass;
	int level;
        char temp;
        int id;
        cnt++;
        id = cnt;

        while(in_s >> name) { //while you can read the file

//		cout << "It gets here\n";

		in_s >> perclass;
//		cin.ignore();
		in_s >> level;

                int index = pHash(name); //find what bucket to place the card into

                if(hashTable[index]->pName == "empty") { //if empty bucket set item info
                        hashTable[index]->pName = name;
			hashTable[index]->pClass = perclass;
			hashTable[index]->pLevel = level;

			//cout << hashTable[index]->pName << endl << hashTable[index]->pClass << endl << hashTable[index]->pLevel << endl;
                }
                else { //if the bucket is filled, use chaining and add another item
                        player* ptr = hashTable[index];
                        player* n = new player;
                        n->pName = name;
                        n->pClass = perclass;
			n->pLevel = level;
                        n->next = NULL;

                        while(ptr->next != NULL) { //et next bucket
                                ptr = ptr->next;
                        }
                        ptr->next = n;
                }
        }

}

void playerHash::findHighestspell(string name, string& pclass, int& lvl) {
	cspellHash cs;

	for(int i = 0; i < tableSize; i++) {
		player* ptr = hashTable[i];

		while(ptr != NULL) {
			if(ptr->pName == name) {
				lvl = ptr->pLevel;
				pclass = ptr->pClass;
				return;
			}
			else {
				ptr = ptr->next;
			}
		}
	}
}

void playerHash::compareLvl(int lvl, string& pclass) {
	for (int i = 0; i < tableSize; i++) {
		player* ptr = hashTable[i];

		//cout << ptr->pName << ptr->pClass << ptr->pLevel << endl << endl;

		while(ptr != NULL) {
			if(ptr->pLevel >= lvl) {
				if(ptr->pClass == pclass) {
					cout << ptr->pName << endl;
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
}

