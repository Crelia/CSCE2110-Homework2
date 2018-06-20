//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "spells.h"
#include "functions.h"

using namespace std;

spellHash::spellHash() {
	cnt = 0;

	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new spells;
		hashTable[i]->sName = "empty";
		hashTable[i]->sType = "empty";
		hashTable[i]->next = NULL;
	}
}

int spellHash::sHash(string key) {
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;

	return index;
}

void spellHash::addSpell(ofstream& out_s, ifstream& in_s) {
        string name;
        string type;
        char temp;
        int id;
        cnt++;
        id = cnt;

        while(in_s >> name) { //while you can read the file

                in_s >> type;

                int index = sHash(name); //find what bucket to place the card into

                if(hashTable[index]->sName == "empty") { //if empty bucket set item info
                        hashTable[index]->sName = name;
                        hashTable[index]->sType = type;
                }
                else { //if the bucket is filled, use chaining and add another item
                        spells* ptr = hashTable[index];
                        spells* n = new spells;
                        n->sName = name;
                        n->sType = type;
                        n->next = NULL;

                        while(ptr->next != NULL) { //et next bucket
                                ptr = ptr->next;
                        }
                        ptr->next = n;
                }
        }

}

void spellHash::highestStype(string spell) {
	for(int i = 0; i < tableSize; i++) {
		spells* ptr = hashTable[i];

		while(ptr != NULL) {

			if(ptr->sName == spell) {
				cout << "\n" << spell << " is of type " << ptr->sType << endl;
				return;
			}
			else {
				ptr = ptr->next;
			}
		}
	}
}


/*void spellHash::findSpells(string& type, string& spell) {
	for(int i = 0; i < tableSize; i++) {
		spells* ptr = hashTable[i];

		while(ptr != NULL) {
			if(ptr->sType == type) {
				ccnt++;
				ptr = ptr->next;
			}
			else {
				ptr = ptr->next;
			}
		}
	}
}

void spellHash::findOnespell(string& type, string& spell) {
	for(int i = 0; i < tableSize; i++) {
		spells* ptr = hashTable[i];

		while(ptr != NULL) {
			if(ptr->sType == type) {
				spell = ptr->sName;
				return;
			}
			else {
				ptr = ptr->next;
			}
		}
	}
}
*/
