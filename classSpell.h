//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef classSpell_h
#define classSpell_h

class cspellHash {
	private:
		static const int tableSize = 64;
		int cnt;
		struct classSpell {
			string sName; //spell name
			string sClass; //class
			int sLevel; //level required
			classSpell* next;
		};
		classSpell* hashTable[tableSize];
	public:
		cspellHash();
		int csHash(string key); //hash function
		void addCspell(ofstream& out_s, ifstream& in_s);
		int checkSpell(string pclass, string& spell, int level, int& ccnt);
		void findType(string pclass, string& spell, int level);
		void findSpell(string spell, int& lvl, string& pclass);
		void checkHighest(string& spell, string pclass);
};

#endif /*classSpell_h*/
