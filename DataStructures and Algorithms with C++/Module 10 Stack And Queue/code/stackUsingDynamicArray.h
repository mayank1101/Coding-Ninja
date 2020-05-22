//stack using dynamic array

template <typename T>

class stackUsingDynamicArray
{
	T *data;
	int nextIndex;
	int capacity;

public:

	stackUsingDynamicArray(int size)
	{
		data = new T[size];
		nextIndex = 0;
		capacity = size;
	}

	//return stack size
	int size()
	{
		return nextIndex;
	}

	//check for stack empty
	bool isEmpty()
	{
		return nextIndex == 0;
	}

	//check for stack full
	bool isFull()
	{
		return nextIndex == capacity;
	}


	//insert element into stack
	void push(T element)
	{
		if(isFull()){
			cout << "Stack is Full ! Dyamically doubling the size of the array\n";
			T *newData = new T[2*capacity];
			for(int i=0;i<capacity;i++){
				newData[i] = data[i];
			}

			delete [] data;
			data = newData;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	//get the top element from stack
	T top()
	{
		if(isEmpty()){
			cout << "Stack Empty !\n";
			return 0;
		}
		return data[nextIndex-1];
	}


	//delete element from stack
	T pop()
	{
		if(isEmpty())
		{
			cout << "Stack Empty !\n";
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}

};