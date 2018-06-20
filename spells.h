//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef spells_h
#define spells_h

class spellHash {
	private:
		static const int tableSize = 64;
		int cnt;
		struct spells {
			string sName;
			string sType;
			spells* next;
		};

		spells* hashTable[tableSize];
	public:
		spellHash();
		int sHash(string key);
		void addSpell(ofstream& out_s, ifstream& in_s);
		void highestStype(string spell);
};

#endif /*spells_h*/
