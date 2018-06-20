//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"
#include "player.h"
#include "classSpell.h"
#include "spells.h"

using namespace std;

int main () {
	ofstream out_s; //out stream file
        ifstream in_s; //in stream file

        playerHash pObj; //hash object
	cspellHash csObj;
	spellHash sObj;

        int choice = -1;
	string name;
	string pclass;
	string spell;
	string type;
        int id = 0;
	int lvl = 0;
	int ccnt = 0;

        while (choice != 0) { //loop until user decides to quit
                cout << "What do you want to do?\n";
                cout << " 0  - quit\n 1  - Add players from file\n 2  - Add class-spell relationships\n 3  - Add spell types\n 4  - Find a players highest spells (given current level)\n 5  - See who can learn what spells\n 6 - Spells able to be learned in general\n 7 - Find the highest level spells of each class";
                cout << "Enter your selection: ";
                cin >> choice;

                switch (choice) {
                        case 1: //get the instream file, add the item, close the file
                                get_stream(in_s, out_s);
				pObj.addPlayer(out_s, in_s);
                                in_s.close();
                                break;
			case 2:
				get_stream(in_s, out_s);
				csObj.addCspell(out_s, in_s);
				in_s.close();
				break;
			case 3:
				get_stream(in_s, out_s);
				sObj.addSpell(out_s, in_s);
				in_s.close();
				;break;
                        case 4: //Find player name, pass to function
				cout << endl << "What is the players name: ";
				cin.ignore();
				getline(cin, name);
				cout << endl;
				pObj.findHighestspell(name, pclass, lvl);

				csObj.checkSpell(pclass, spell, lvl, ccnt);

				while(ccnt != 0) {
					csObj.findType(pclass, spell, lvl);
					ccnt--;
					cout << spell << endl;
					sObj.highestStype(spell);
				}
				;break;
                        case 5:
				cout << endl << "What is the spell you would like to check on: ";
				cin.ignore();
				getline(cin, spell);
				cout << endl;
				csObj.findSpell(spell, lvl, pclass);

				pObj.compareLvl(lvl, pclass);

				;break; //print hash table
                        case 6:
				cout << endl << "What is the spell you would like to check on: ";
				cin.ignore();
				getline(cin, spell);
				cout << endl;

				csObj.findSpell(spell, lvl, pclass);

				cout << pclass << endl;

				//pObj.
				;break;//find extra cards
                        case 7:
				cout << endl << "What class would you like to learn the highest possible spells of: ";
				cin.ignore();
				getline(cin, pclass);
				cout << endl;

				csObj.checkHighest(spell, pclass);

				//cout << spell << endl << endl;

				;break;//find universal cards
                }
        }



	return 0;
}
