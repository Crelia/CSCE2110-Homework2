//Jefferson Crelia
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef player_h
#define player_h

class playerHash {
	private:
		static const int tableSize = 64;
		int cnt;
		struct player {
			string pName; //player name
			string pClass; //player class
			int pLevel; //player level
			player* next; //next node
		};
		player* hashTable[tableSize]; //table of 64 buckets
	public:
		playerHash();
		int pHash(string key); //hash function
		void addPlayer(ofstream& out_s, ifstream& in_s);
		void findHighestspell(string name, string& pclass, int& lvl);
		void compareLvl(int lvl, string& pclass);
};

#endif /*player_h*/
