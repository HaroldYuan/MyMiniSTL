#include "iostream"
using namespace std;

template <typename Item>
class Vector{

public:
	class iterator{
	public:
		iterator():current(NULL){}

		const Item& operator*() const{
			return *current;
		}

		iterator& operator++(){
			current++;
			return *this;
		}

		iterator operator++(int){
			iterator old=*this;
			++(*this);
			return old;
		}

		iterator operator--(){
			current--;
			return *this;
		}

		iterator operator--(int){
			iterator old=*this;
			--(*this);
			return old;
		}
		
		bool operator==(const iterator& iter){
			return this->current==iter.current;
		}

		bool operator!=(const iterator& iter){
			return !(this->current==iter.current);
		}

	private:
		Item* current;

		iterator(Item* p):current(p){}

		friend class Vector<Item>;
	};

public:
	Vector(int size=0):size(size),capacity(size+space_capacity){
		items =new Item[capacity];
	}

	Vector(const Vector& vec):items(NULL){
		operator=(vec);
	}

	~Vector(){
		delete []items;
	}

	const Vector& operator=(const Vector& vec){
		if (this!=&vec){
			delete []items;
		    size=vec.getsize();
		    capacity=vec.getcapacity();
		    items=new Item[capacity];
		    for (int i = 0; i < size ; i++){
			items[i]=vec.items[i];
			}
			return *this;
	    } 
	}

	int getsize() const{
		return size;
	}

	int getcapacity() const{
		return capacity;
	}

	void resize(int newsize){
		if (newsize>capacity){
		reserve(newsize*2+1);
		}
		size=newsize;
	}

	void reserve(int newcapacity){
		if(newcapacity<size)
		return;
		Item* olditems=items;
		items=new Item[newcapacity];
		for (int i = 0; i < size ; i++){
			items[i]=olditems[i];
		}
		capacity=newcapacity;
		delete []olditems;
	}

	Item& operator[](int index){
		return items[index];
	}

	bool isEmpty(){
		return size==0;
	}

	void push_back(Item item){
	if (size==capacity){
		reserve(2*capacity+1);
		}
		items[size]=item;
		size++;
	}

	void pop_back(){
		size--;
	}

	iterator begin(){
		return iterator(items);
	}

	iterator end(){
		return iterator(&items[size]);
	}

	enum {space_capacity=20};
	
private:
	int size;
	int capacity;
	Item* items;
};
