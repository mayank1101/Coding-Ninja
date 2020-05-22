#include<vector>
using namespace std;

template <typename T>

class Node
{
public:

	T data;
	vector<Node<T>*> children;

	Node(T data)
	{
		this->data = data;
	}

	~Node()
	{
		for(int i=0;i<children.size();i++){
			delete children.at(i);
		}
		cout << data <<  " deleted !" << "\n";
	}
};