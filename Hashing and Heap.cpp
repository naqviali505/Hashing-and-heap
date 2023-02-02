#include <iostream>
using namespace std;
template<class T>
class HashItem {
public:
	int Key;
	T value;
	int status;
	HashItem()
	{
		Key = -1;
		value = -1;
		status = 0;
	}
	void set_key(int key, int value)
	{
		this->Key = key;
		this->value = value;
	}
};
template<class T>
class HashMap {
private:
	HashItem<T>* HashTable;
	int capacity;
	int capacity_occupied;
	int getNextCandidateIndex(int key, int i);
public:
	HashMap();
	HashMap(int const capacity);
	void insert(HashItem<T> i);
	int HashFunction(HashItem<T> obj);
	bool deleteItem(HashItem<T> i);
	bool search(HashItem<T> obj);
	void print();
};
template<class T>
HashMap<T>::HashMap()
{
	HashTable = NULL;
	capacity_occupied = 0;
	capacity = 0;

}
template<class T>
HashMap<T>::HashMap(int capacity)
{
	HashTable = new HashItem<T>[capacity];

	this->capacity = capacity;
}
template<class T>
void HashMap<T>::insert(HashItem<T> has)
{
	int index = HashFunction(has);
	int nextcandidate = getNextCandidateIndex(has.Key, index);
	has.status = 2;
	HashTable[nextcandidate] = has;
}
template<class T>
int HashMap<T>::HashFunction(HashItem<T> has) {
	int i = 0;     //evaluate your HashFunction here

	i = has.Key % capacity;

	return i;

}
template<class T>
int HashMap<T>::getNextCandidateIndex(int key, int i) {
	while (HashTable[i].status != 0)
	{
		i++;
	}
	return i;
}
template<class T>
bool HashMap<T>::deleteItem(HashItem<T> i)
{
	if (search(i) == true)
	{
		int j = i.Key % capacity;
		if (HashTable[j].value == i.value)
		{
			HashTable[j].value = -1;
			HashTable[j].status = 0;
			return true;
		}
		else
		{
			for (int itr = j; itr < capacity; itr++) {
				if (HashTable[itr].value == i.value)
				{
					HashTable[itr].value = -1;
					HashTable[itr].status = 0;
					return true;
				}
			}
		}
	}
	return false;
}
template<class T>
bool HashMap<T>::search(HashItem<T> i)
{
	int j = i.Key % capacity;
	if (HashTable[j].value == i.value)
		return true;
	else {
		for (int itr = j; itr<capacity; itr++)
		{
			if (HashTable[itr].value == i.value)
				return true;
		}
	}
	return false;
}
template<typename T>
void HashMap<T>::print()
{
	for (int i = 0; i < capacity; i++)
	{
		if (HashTable[i].value != -1)
			cout << HashTable[i].value << " ";
	}
	cout << endl;
}
int main()
{
	int arr[12] = { 2,4,6,8,10,12,14,16,18,48,24 };
	HashMap<int> map(24);
	HashItem<int> item1;
	for (int i = 0; i < 11; i++)
	{
		item1.set_key(arr[i], arr[i]);
		map.insert(item1);
	}
	map.print();
	item1.set_key(6, 6);
	if (map.search(item1) == true)
	{
		cout << "value found" << endl;
	}
	else cout << "value not found" << endl;
	item1.set_key(10, 10);
	map.deleteItem(item1);
	cout << "after deletion\n";
	map.print();
	return 0;
}