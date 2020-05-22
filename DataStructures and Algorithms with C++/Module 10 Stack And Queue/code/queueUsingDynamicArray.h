template <typename T>

class queueUsingDynamicArray
{
	T *data;
	int nextIndex;
	int firstIndex;
	int capacity;
	int size;

public:

	queueUsingDynamicArray(int n)
	{
		data = new T[n];
		capacity = n;
		size = 0;
		nextIndex = 0;
		firstIndex = -1;
	}

	bool isEmpty()
	{
		return (size == 0);
	}

	int getSize()
	{
		return size;
	}

	bool isFull()
	{
		return (size == capacity);
	}

	void enqueue(T element)
	{
		if(isFull()){
			T *newData = new T[2 * capacity];
			int k=0;
			for(int i=firstIndex;i<capacity;i++){
				newData[k++] = data[i];
			}
			for(int i=0;i<firstIndex;i++)
			{
				newData[k++] = data[i];
			}
			delete [] data;
			nextIndex = capacity;
			firstIndex = 0;
			data = newData;
			capacity = 2 * capacity;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity;
		if(firstIndex == -1){
			firstIndex = 0;
		}
		size++;
	}


	T front()
	{
		if(isEmpty())
		{
			cout << "Queue Empty !\n";
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