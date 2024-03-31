#include <iostream>
#include <map>
#include <list>//i need double linked list.
#include <cstdint>

//https://cpprefjp.github.io/reference/list/list.html

//basicaly to ListList's A or B or C or D is not have meen.

template<class T> using List = std::map<std::intmax_t, T>;
template<class T> using ListListA = List<std::list<T>>;//i need replace to std::list to double linked list.//this is holding anpairble vector.
template<class T> using ListListB = std::list<List<T>>;//this is area holder like... what??
template<class T> using ListListC = List<List<T>>;//like a duty 2d array??
template<class T> using ListListD = std::list<std::list<T>>;//like a duty 2d array??

/**/
enum class Names {
	none=0,
	One,
	tow,
	three,
	OreNoNamaeWoItteMiro,
};
template<class T> using NamedList = std::map<Names, T>;
/**/

/**/
enum class Tag {
	X=0,
	Y,
	Z,
	Hoge,
};
template<class Idx,class T> using TagedList = std::map<Idx, T>;//lolololololol you need only name?
/**/
int main() {
	List<int> L;

	L[19] = 130;

	for (auto& o :  L) {
		std::cout << o.first<<':' << o.second << std::endl;
	}

	ListListA<int> VLA;

	VLA[10].push_back( 100);
	for (auto& o :  VLA) {
		std::cout << o.first<< std::endl;
	}
	ListListB<int> VLB;

	VLB.push_back({});
	VLB.back()[0] = 9;
	for (auto& o : VLB) { 
		std::cout << o[0] << std::endl;
	}

	ListListC<int> LLC;
	LLC[10][20] = 30;
	for (auto& o : LLC) {
		std::cout << o.second[20] << std::endl;
	}

	ListListD<int> LLD;
	LLD.push_back({});
	LLD.back().push_back(10);

	for (auto& o : LLD) {
		std::cout << o.back() << std::endl;
	}

	NamedList<int> NL;

	NL[Names::OreNoNamaeWoItteMiro] = 53;
	for (auto& o : NL) {
		std::cout <<(int)o.first<<':'<< o.second << std::endl;
	}

	TagedList<Tag, int> TL;
	TL[Tag::X] = 10;
	for (auto& o : TL) {
		std::cout <<(int)o.first<<':'<< o.second << std::endl;
	}
}