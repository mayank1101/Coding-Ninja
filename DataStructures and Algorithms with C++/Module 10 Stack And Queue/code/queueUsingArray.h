template <typename T>

class queueUsingArray
{
	T *data;
	int nextIndex,firstIndex; //rear and front 
	int capacity;
	int size;

public:
	queueUsingArray(int n)
	{
		data = new T[n];
		capacity = n;
		size = 0;
		nextIndex=0;
		firstIndex=-1;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return (size == 0);
	}

	bool isFull()
	{
		return (size == capacity);
	}

	void enqueue(T element)
	{
		if(isFull()){
			cout << "Queue FUll !\n";
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex+1) % capacity;
		size++;
		if(firstIndex == -1){
			firstIndex = 0;
		}
		return;
	}

	T front()
	{
		if(isEmpty()){
			cout << "Queue Empty ! \n";
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue()
	{
		if(isEmpty()){
			cout << "Queue Empty !\n";
			return 0;
		}
		T element = data[firstIndex];
		firstIndex = (firstIndex+1) % capacity;
		size--;
		if(isEmpty()){
			firstIndex = -1;
			nextIndex = 0;
		}
		return element;
	}

};