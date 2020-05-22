template <typename T>

class stackUsingArray
{
	//private attributes of class stackUsingArray
	T *data;
	int capacity;
	int nextIndex;

public:

	//constructor
	stackUsingArray(int s)
	{
		data = new T[s];
		capacity = s;
		nextIndex = 0;
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
			cout << "Stack Full !\n";
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	//return top element
	T top()
	{
		if(isEmpty()){
			cout << "Stack Empty !" << "\n";
			return 0;
		}
		return data[nextIndex-1];
	}

	//delete top element
	T pop()
	{
		if(isEmpty())
		{
			cout << "Stack Empty !" << "\n";
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}
};

