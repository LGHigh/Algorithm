#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
#include <time.h>
#include <map>
using namespace std;
map<string, int>Hoffman;
vector<string>text;
ofstream Hoff("Hoff.out");
bool IsPrime(int t) {
	int max = (int)sqrt(t) + 1;
	for (int i = 2; i < max; i++) {
		if (t % i == 0)return false;
	}
	return true;
}

int NextPrime(int t) {
	while (1) {
		if (IsPrime(t))return t;
		else t++;
	}
}

class HeapClass;
struct ListNode;
typedef struct ListNode* Position;
class HashTbl;
typedef class HashTbl* HashTable;

class HashTbl {
	friend class HeapClass;
public:
	HashTbl(int TableSize);
	int Hash(string Key, int TableSize);
	Position Find(string Key);
	void Insert(string Key);
	ListNode* BuildHoff(HeapClass* m);			//构建Hoffman树
private:
	int TableSize;
	ListNode** TheLists;
};

struct ListNode {
	string Element;
	int size;
	int num;
	ListNode* Left;
	ListNode* Right;
	ListNode() = default;
	ListNode(ListNode* t1, ListNode* t2) {
		size = t1->size + t2->size;
		Left = t1; Right = t2; Element = "";
		num = 0;
	}
};


class HeapClass {
public:
	HeapClass(int MaxElements);
	void Insert(ListNode* X);
	ListNode* DeleteMin();
private:
	int Capacity;
	int Size;
	ListNode** Elements;
};

//--------------------------------------------------//
//------------------HASHTBL-------------------------//
HashTbl::HashTbl(int TableSize) {
	this->TableSize = NextPrime(TableSize);
	TheLists = new ListNode*[this->TableSize];
	for (int i = 0; i < this->TableSize; i++) {
		TheLists[i] = new ListNode;
		TheLists[i]->size = 0;
		TheLists[i]->Left = TheLists[i]->Right = nullptr;
	}
}

int HashTbl::Hash(string Key, int TableSize) {
	int seed = 131;
	int hash = 0;
	int len = Key.length();
	for (int i = 0; i < len; i++) {
		hash = (hash*seed + Key[i]) % this->TableSize;
	}
	return hash;
}

Position HashTbl::Find(string Key) {
	int hash = Hash(Key, this->TableSize);
	Position P = this->TheLists[hash];
	if (P->size == 0) {
		//cout << hash << endl;
		return P;
	}
	else {
		if (P->Element == Key) {
			//cout << hash << endl;
			return P;
		}
		else {
			int i = 1; int Tmp = (hash + i*i) % this->TableSize;
			while (this->TheLists[Tmp]->size != 0 && this->TheLists[Tmp]->Element != Key) {
				i++;
				Tmp = (hash + i*i) % this->TableSize;
			}
			//cout << Tmp << endl;
			return (this->TheLists[Tmp]);
		}
	}
}

void HashTbl::Insert(string Key) {
	Position Pos = Find(Key);

	if (Pos->size == 0) {
		Pos->Element = Key;
		Pos->size = 1;
	}
	else Pos->size++;
}

ListNode* HashTbl::BuildHoff(HeapClass* m) {					//构建Hoffman树
	int num = 0;
	for (int i = 0; i < this->TableSize; i++) {
		if (this->TheLists[i]->size) {
			m->Insert(this->TheLists[i]);						//构建最小堆
			num++;
		}
	}
	for (int i = 0; i < num - 1; i++) {							//构建Hoffman树
		ListNode* t1 = m->DeleteMin();
		ListNode* t2 = m->DeleteMin();
		ListNode* tmp = new ListNode(t1, t2);
		m->Insert(tmp);
	}
	return m->DeleteMin();
}

//----------------HASHTBL END-----------------------//
//--------------------------------------------------//

//--------------------------------------------------//
//------------------HEAPCLASS-----------------------//
HeapClass::HeapClass(int MaxElements) {
	Elements = new ListNode*[MaxElements];
	for (int i = 0; i < MaxElements; i++) {
		Elements[i] = new ListNode;
	}

	Capacity = MaxElements;
	Size = 0;
	Elements[0]->size = 0;
}

void HeapClass::Insert(ListNode* X) {
	int i;
	for (i = ++this->Size; this->Elements[i / 2]->size > X->size ; i /= 2)
		this->Elements[i] = this->Elements[i / 2];
	this->Elements[i] = X;
}

ListNode* HeapClass::DeleteMin() {
	int i, Child;
	ListNode* MinElement, *LastElement;

	MinElement = this->Elements[1];
	LastElement = this->Elements[this->Size--];

	for (i = 1; i * 2 <= this->Size; i = Child) {
		Child = i * 2;
		if (Child != this->Size && this->Elements[Child + 1]->size < this->Elements[Child]->size)
			Child++;

		if (LastElement->size > this->Elements[Child]->size)
			this->Elements[i] = this->Elements[Child];
		else  break;
	}

	this->Elements[i] = LastElement;

	return MinElement;
}
//---------------HEAPCLASS END----------------------//
//--------------------------------------------------//

void MakeHoffman(ListNode* root, int bit) {						//用DFS将Hoffman树中的每一个字符串赋值	
	if (root->Element != "") {									//当访问到叶节点，将其字符串和值放入map中
		Hoffman[root->Element] = root->num;
		Hoff << root->Element << " " << root->num << endl;
		return;
	}
	root->Left->num = root->num + 0 * bit;						//对根的左节点赋值
	root->Right->num = root->num + 1 * bit;						//对根的右节点赋值
	MakeHoffman(root->Left, bit * 2); MakeHoffman(root->Right, bit * 2);
}

int main() {							//O(n)
	clock_t start, end;

	fstream in("input.txt");
	ofstream out("data.out");
	string tmp, buf;
	HashTbl* cnt = new HashTbl(100000);
	HeapClass* t = new HeapClass(100000);
	while (in >> tmp) {
		int len = tmp.length();
		for (int i = 0; i < len; i++) {
			if (isalpha(tmp[i]))tmp[i] = tolower(tmp[i]);
			else if (tmp[i] != '-' && tmp[i] != '\'')tmp[i] = ' ';
		}
		stringstream ss(tmp);
		while (ss >> buf)
			text.push_back(buf);
			cnt->Insert(buf);
	}
	ListNode* HoffmanTree = cnt->BuildHoff(t); HoffmanTree->num = 0;//构建Hoffman树
	MakeHoffman(HoffmanTree, 1);									//为每个字符串赋值
	int len = text.size();
	for (int i = 0; i < len; i++) {									//对文本进行编码
		out << Hoffman[text[i]] ;
	}
	cout << Hoffman.size() << endl;
	return 0;
}
