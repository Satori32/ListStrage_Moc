#include <iostream>
#include <map>
#include <list>//i need double linked list.
#include <cstdint>
#include <unordered_map>

//https://cpprefjp.github.io/reference/list/list.html

//basicaly to ListList's A or B or C or D is not have meen.

template<class T> using List = std::unordered_map<std::intmax_t, T>;//cut the sort theory.
template<class T> using SortdList = std::map<std::intmax_t, T>;
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
template<class T> using SortedNamedList = std::map<Names, T>;
/**/

/**/
enum class Tag {
	X=0,
	Y,
	Z,
	Hoge,
};
template<class Idx,class T> using TagedList = std::unordered_map<Idx, T>;//lolololololol you need only name?
template<class Idx,class T> using SoetedTagedList = std::map<Idx, T>;//lolololololol you need only name?
/**/
enum class TagF {
	None=0,
	A,
	B,
	C,
};
template<class T> using TList = TagedList<TagF, T>;
template<class T, class I = std::intmax_t> using FPocket = TList<TagedList<I, T>>;//formmers pocket. are you need [I=enum class]? 

enum class ListX
{
	None,
	A,
	B,
	C,

};
template<class Tag,class T>
class TaggedLinkedList : public std::list<std::pair<Tag, T>> {
public:
/**/
	std::pair<Tag,T>& operator[](Tag E) {
		for (auto& o : *this) {
			if (o.first == E)return o;
		}
		S.push_back({ E,T() });
		return this->back();

	}
	/**/

	std::pair<Tag,T>& back() { return S.back(); }
	std::pair<Tag,T>& front() { return S.front(); }
	void push_back(std::pair<Tag,T>& In) {
		this->push_back(In);
		return;
	}
	void push_front(std::pair<Tag,T>& In) {
		this->push_front(In);
		return;
	}	

protected:
	std::list<std::pair<Tag, T>>& S = *this;

};


/** /
enum class Linked {
	None,
	A,
	B,
	C,

};

template<template<class T,class Idx> class X>
class TagedDoubleLinkedList:public std::list<X<X::T,X::Idx>> {//compiler is die... why??
public:
	template<class Tx,class Idxx>
	struct I{
		Idxx N{0,};
		Tx Item{0,};
	};
	T& operator[](Idx E) {
		for (auto& o : *this) {
			if (o.N == E)return o.Item;
		}
		S.push_back({ E,T() });
		return this->back();

	}
	T& back() { return static_cast<std::list<T,Idx>>(this)->back(); }
	T& front() { return static_cast<std::list<T,Idx>>(this)->front(); }
	void push_back(Idx E, const T& In) {
		this->push_back({ In,E });
	}
	void push_front(Idx E, const T& In) {
		this->push_front({ In,E });
	}

//	typename decltype(*this)::iterator begin(){
//	}

protected:
	//doubleLinkedListX<T, Idx>& S =  *this;
	//std::list<I<T, Idx>>& L = *this;
};

/**/
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

	SortedNamedList<int> NL;

	NL[Names::OreNoNamaeWoItteMiro] = 53;
	for (auto& o : NL) {
		std::cout <<(int)o.first<<':'<< o.second << std::endl;
	}

	TagedList<Tag, int> TL;
	TL[Tag::X] = 10;
	for (auto& o : TL) {
		std::cout <<(int)o.first<<':'<< o.second << std::endl;
	}

	TaggedLinkedList<ListX,int> TLL;
	TLL[ListX::A].second = 11;
	for (auto& o : TLL) {
		std::cout <<(int)o.first<<':'<< o.second << std::endl;
	}

}