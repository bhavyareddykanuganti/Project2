// Computing Structures Fall 2022
// DSA 5005
// Bhavya Reddy Kanuganti

#include <iostream>
#include <string>
using namespace std;

// class node to store one node's details
template <class DT>//template
class Node
{
protected:
	int nodeNumber;  // field to store node's number
	string nodeInfo; // field to store node's information
	DT yearCreated;  // field to store the year of the node created
	string location; // field to store the location

public:
	Node(); // default constructor

	// getters
	string getNodeInfo();
	int getNodeNumber();
	DT getYearCreated();
	string getLocation();

	// setters
	void setNodeInfo(string newInfo);
	void setNodeInfo(string newInfo, DT newYearCreated, string newLoc); // V2: updated
	void setNodeNumber(int newNum);
	void setYearCreated(DT newYearCreated);
	void setLocation(string newLocation);

	void display(); // display node details

	~Node(); // destructor
};
template <class DT>
Node<DT>::Node()
{
	nodeNumber = 0;
	nodeInfo = "";
	yearCreated = 0;
	location = "";
}
//getters
template <class DT>
string Node<DT>::getNodeInfo()//getter to return node info
{
	return nodeInfo;
}
template <class DT>
int Node<DT>::getNodeNumber()//getter to return node number
{
	return nodeNumber;
}
template <class DT>
DT Node<DT>::getYearCreated()//getter to return year created
{
	return yearCreated;
}
template <class DT>
string Node<DT>::getLocation()//getter to return location
{
	return location;
}
template <class DT>
void Node<DT>::setNodeInfo(string newInfo)//setting node info
{
	nodeInfo = newInfo;

}
template <class DT>
void Node<DT>::setNodeInfo(string newInfo, DT newYearCreated, string newLoc)//setting node info, year created and location
{
	nodeInfo = newInfo;
	yearCreated = newYearCreated;
	location = newLoc;

}
template <class DT>
void Node<DT>::setNodeNumber(int newNum)//setting node number
{
	nodeNumber = newNum;
}

template <class DT>
void Node<DT>::setYearCreated(DT newYearCreated)//setting year created
{
	yearCreated = newYearCreated;
}
template <class DT>
void Node<DT>::setLocation(string newLocation)//setting location
{
	location = newLocation;
}
template <class DT>
void Node<DT>::display()//displaying node details
{
	cout << nodeNumber << ": " << nodeInfo << ", " << yearCreated << ", " << location << endl;
}
template <class DT>
Node<DT>::~Node()//destructor
{
	//nodeNumber = 0;
	//nodeInfo = "";
	//yearCreated = 0;
	//location = "";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store one edge's details
template <class DT>//template
class Edge
{
protected:
	Node<DT>* u;     // field to store source node pointer
	Node<DT>* v;     // field to store destination node pointer
	string edgeInfo; // field to store edge information
	DT yearsKnown;   // u and v - years known

public:
	Edge(); // default constructor
	// getters
	Node<DT>* getu();
	Node<DT>* getv();
	string getEdgeInfo();
	DT getYearsKnown();

	// setters
	void setu(Node<DT>* newu);
	void setv(Node<DT>* newv);
	void setEdgeInfo(string newInfo);
	void setEdgeInfo(string newInfo, DT newYearsKnown); // V2: updated
	void setYearsKnown(DT newYear);                     // V2: updated

	void display(); // display edge details

	~Edge(); // destructor
};
template <class DT>
Edge<DT>::Edge()
{
	u = NULL;
	v = NULL;
	edgeInfo = "";
	yearsKnown = 0;
}
//getters
template <class DT>
Node<DT>* Edge<DT>::getu()//getter to return node u
{
	return u;
}
template <class DT>
Node<DT>* Edge<DT>::getv()//getter to return node v
{
	return v;
}
template <class DT>
string Edge<DT>::getEdgeInfo()//getter to return edge info
{
	return edgeInfo;
}
template <class DT>
DT Edge<DT>::getYearsKnown()//getter to return years known
{
	return yearsKnown;
}
//setters
template <class DT>
void Edge<DT>::setu(Node<DT>* newu)//setting node u
{
	u = newu;
}
template <class DT>
void Edge<DT>::setv(Node<DT>* newv)//setting node v
{
	v = newv;
}
template <class DT>
void Edge<DT>::setEdgeInfo(string newInfo)//setting edge info
{
	edgeInfo = newInfo;
}
template <class DT>
void Edge<DT>::setEdgeInfo(string newInfo, DT newYearsKnown)//setting edge info and years known
{
	edgeInfo = newInfo;
	yearsKnown = newYearsKnown;
}
template <class DT>
void Edge<DT>::setYearsKnown(DT newYear)// setting years known
{
	yearsKnown = newYear;
}
template <class DT>
void Edge<DT>::display()//displaying edge details
{
	if ((u != NULL) && (v != NULL))
		cout << u->getNodeInfo() << " - " << v->getNodeInfo() << " " << edgeInfo << ", " << yearsKnown << endl;
}
template <class DT>
Edge<DT>::~Edge()//destructor
{
	//delete u;
	//delete v;
	//edgeInfo = "";
//	yearsKnown = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store the graph
template <class DT>
class GraphDB
{
	// TODO: ostream operator for displaying myNodes and myEdges
protected:
	Node<DT>* myNodes; // array of nodes
	Edge<DT>* myEdges; // array of edges
	int numNodes;      // number of nodes
	int numEdges;      // number of edges
	int maxEdges;      // store the max number of edges (array size)

public:
	GraphDB(int nNodes, int nEdges); // non-default constructor
	// setters
	void setNode(Node<DT>& newNode);
	void setEdge(Edge<DT>& newEdge);
	void setNodeInfo(int u, string newInfo, DT newYear, string newLoc);
	void setEdgeInfo(int u, int v, string newInfo, DT newYearsKnown);
	// getters
	Node<DT>* getNode(int nodeNum);
	string getNodeInfo(int nodeNum);
	Edge<DT>* getEdgeInfo(int u, int v);
	

	// operations
	bool isAnEdge(int u, int v);     // is this edge existent
	void addEdge(Edge<DT>& newEdge); // add an edge
	void deleteEdge(int u, int v);   // delete the edge
	void display();                  // display the contents of the two arrays

	int* findNeighbours(int u);      // returns an integer array of neighbours' nodeNum
	friend ostream& operator << (ostream& s, GraphDB<DT>& g)//ostream operator
	{
		g.display();//display myNodes and myEdges
		return s;//
	}

	~GraphDB(); // destructor
};
template <class DT>
GraphDB<DT>::GraphDB(int nNodes, int nEdges)//parameterized constructor
{
	numNodes = nNodes;
	maxEdges = nEdges;
	myNodes = new Node<DT>[numNodes]; // allocating memory for the myNodes array
	myEdges = new Edge<DT>[maxEdges]; // allocating memory for the myEdges array
	numEdges = 0; // to keep count of the number of edges currently present
}

// display for the nodes and edges of graphDB
template <class DT>
void GraphDB<DT>::display()
{
	cout << "Displaying myNodes: " << endl;
	for (int i = 0; i < numNodes; i++)
		myNodes[i].display(); // calling the Node class display

	cout << "Displaying myEdges: " << endl;
	for (int i = 0; i < numEdges; i++)
		myEdges[i].display(); // calling the Edge class display
}

// setter for node object
template <class DT>
void GraphDB<DT>::setNode(Node<DT>& newNode)//setting node details
{
	myNodes[newNode.getNodeNumber()].setNodeNumber(newNode.getNodeNumber());
	myNodes[newNode.getNodeNumber()].setNodeInfo(newNode.getNodeInfo());
	myNodes[newNode.getNodeNumber()].setYearCreated(newNode.getYearCreated());
	myNodes[newNode.getNodeNumber()].setLocation(newNode.getLocation());
	// myNodes[newNode.getNodeNumber()] = newNode;

}

// getter for a specific node from myNodes
template <class DT>
Node<DT>* GraphDB<DT>::getNode(int nodeNum)
{
	return &myNodes[nodeNum];
}
template <class DT>
string GraphDB<DT>::getNodeInfo(int nodeNum)//getter to return node info of particular node
{
	return myNodes[nodeNum].getNodeInfo();
}
template <class DT>
Edge<DT>* GraphDB<DT>::getEdgeInfo(int u, int v)//getter for edge info
{
	for (int i = 0; i < numEdges; i++) // loop through the myEdges array
	{
		if (myEdges[i].getu()->getNodeNumber() == u &&
			myEdges[i].getv()->getNodeNumber() == v) // check nodeNums
		{
			return &myEdges[i];
		}
	}
}
template <class DT>
void GraphDB<DT>::setEdge(Edge<DT>& newEdge)// setter to set an edge
{
	if (numEdges >= maxEdges) // to allocate  memory
	{
		Edge<DT>* tempArrayEdges = new Edge<DT>[maxEdges + (maxEdges / 2)]; // create a new temp array


		for (int i = 0; i < numEdges; i++) // copy old values - deep copy
			tempArrayEdges[i] = myEdges[i];
		tempArrayEdges[numEdges].setu((newEdge.getu()));
		tempArrayEdges[numEdges].setv((newEdge.getv()));
		tempArrayEdges[numEdges].setEdgeInfo(newEdge.getEdgeInfo());
		tempArrayEdges[numEdges].setYearsKnown(newEdge.getYearsKnown());
		delete[] myEdges; // delete the pointer to the old values

		myEdges = tempArrayEdges; // re point the pointer to the new memory location
		numEdges++;
		maxEdges = maxEdges + (maxEdges / 2); // update the value of maxEdges


	}
	else if(numEdges<maxEdges)
	{
		myEdges[numEdges] = newEdge;
		numEdges++;
	}

}
template <class DT>
void GraphDB<DT>::deleteEdge(int u, int v)//operation to delete an edge
{
	if (isAnEdge(u, v)) // check if the edge is existent
	{
		for (int i = 0; i < numEdges; i++)
		{
			if (myEdges[i].getu()->getNodeNumber() == u && // loop through and find the edge
				myEdges[i].getv()->getNodeNumber() == v)
			{
				// setting the values to NULL (edge to be deleted)
				Node<DT>* t = NULL; // temp dummy node
				myEdges[i].setu(t);
				myEdges[i].setv(t);
				myEdges[i].setEdgeInfo("");
				myEdges[i].setYearsKnown(0);
				for (int j = i; j < numEdges - 1; j++) // left shift all the edges
				{
					myEdges[j].setu(myEdges[j + 1].getu());
					myEdges[j].setv(myEdges[j + 1].getv());
					myEdges[j].setEdgeInfo(myEdges[j + 1].getEdgeInfo());
					myEdges[j].setYearsKnown(myEdges[j + 1].getYearsKnown());
				}
				numEdges = numEdges - 1; // decrement the numEdges
				break;
			}
		}
	}
	else
	{
		cout << "Edge does not exist to be deleted" << endl; // this could be an exception
	}
}

// set the information of node u
template <class DT>
void GraphDB<DT>::setNodeInfo(int u, string newInfo, DT newYear, string newLoc)
{
	for (int i = 0; i < numNodes; i++) // loop through the myNodes array
	{
		if (myNodes[i].getNodeNumber() == u) // check nodeNum
		{
			myNodes[i].setNodeInfo(u,newInfo,newYear,newLoc);
		}
	}
}


// set the information of edge u-v
template <class DT>
void GraphDB<DT>::setEdgeInfo(int u, int v, string newInfo,DT newYearsKnown)
{
	for (int i = 0; i < numEdges; i++) // loop through the myEdges array
	{
		if (myEdges[i].getu()->getNodeNumber() == u &&
			myEdges[i].getv()->getNodeNumber() == v) // check nodeNums
		{
			myEdges[i].setEdgeInfo(newInfo);
			myEdges[i].setYearsKnown(newYearsKnown);
		}
	}
}

// check the existence of an edge
template <class DT>
bool GraphDB<DT>::isAnEdge(int u, int v)
{
	for (int i = 0; i < numEdges; i++) // loop through the myEdges array
	{
		if (myEdges[i].getu()->getNodeNumber() == u &&
			myEdges[i].getv()->getNodeNumber() == v) // check nodeNums
		{
			return true; // return true if found
		}
	}
	return false; // else false
}
template <class DT>
void GraphDB<DT>::addEdge(Edge<DT>& newEdge)//operation to add an edge
{
	setEdge(newEdge);//setting a new edge
}
template <class DT>
int* GraphDB<DT>::findNeighbours(int u)//finding neighbors of node u
{
	int* Neighbour = new int[numEdges];//array of neighbours
	int index = 0;//neighbour index
	
	for (int i = 0; i < numEdges; i++)
	{
		if (myEdges[i].getu()->getNodeNumber() == u)//checking if the node u matches with the given node
		{
			Neighbour[index] = myEdges[i].getv()->getNodeNumber();//assigning node v to neighbour
				index++;//increment index
		}

		else if (myEdges[i].getv()->getNodeNumber() == u)//checking if the node v matches with the given node
		{
			Neighbour[index] = myEdges[i].getu()->getNodeNumber();//assigning node u to neighbor
				index++;//increment index
		}
	}
	cout << "Neighbours of " << u << ": ";//displaying neighbors of nnode u
		for (int i = 0; i < index; i++)
		{
			cout << Neighbour[i] <<" ";
		}
		cout << endl;
	return Neighbour;
}


template <class DT>
GraphDB<DT>::~GraphDB()//destructor
{
//	numNodes = 0;
	//maxEdges = 0;
	//delete[] myNodes; // allocating memory for the myNodes array
	//delete[] myEdges; // allocating memory for the myEdges array
	//numEdges = 0; // to keep count of the number of edges currently present
}

class ExceptionNode{};//node exception
class ExceptionEdge{};//edge exception
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	int numNodes; // temp variable to store numNodes from input
	int maxEdges; // temp variable to store numEdges from input
	int nodeNumber;
	string nodeString;
	int nodeYear;
	string nodeloc;
	 // pointer object of GraphDB class

	int inputU, inputV;
	string edgeString;
	int inputYear;
	cin >> numNodes >> maxEdges; // read the numN<odes and numEdges from redirected input
	GraphDB<int>* masterGraph = new GraphDB<int>(numNodes, maxEdges);
	// display the values read in
	cout << "numNodes: " << numNodes << endl;
	cout << "maxEdges: " << maxEdges << endl << endl;

	masterGraph = new GraphDB<int>(numNodes, maxEdges); // allocate memory by calling non-default constructor
	// read in the information from the input
	Node<int> tempNode;

	for(int i = 0; i < numNodes; i++)
	{
		cin >> nodeNumber >> nodeString >> nodeYear >> nodeloc; // read in the node details
		// cout << nodeNumber << ": " << nodeString << endl;
		tempNode.setNodeNumber(nodeNumber); // create the temp object
		tempNode.setNodeInfo(nodeString,nodeYear,nodeloc);
		masterGraph->setNode(tempNode); // insert the temp object
	}

	char command; // variable to receive the command
	Edge<int> tempEdge;

	while (cin >> command)
	{
		switch (command)
		{
		case 'I':
		{
			cin >> inputU >> inputV >> edgeString >> inputYear; // read in the edge details
			cout << "Inserting " << inputU << " " << inputV << ": " << edgeString << ", " << inputYear << endl;

			try//try catch exception handling
			{
				if (inputU > numNodes || inputV > numNodes) throw ExceptionNode();

				tempEdge.setu(masterGraph->getNode(inputU)); // create the temp edge
				tempEdge.setv(masterGraph->getNode(inputV));
				tempEdge.setEdgeInfo(edgeString);
				tempEdge.setYearsKnown(inputYear);
				masterGraph->setEdge(tempEdge); // set temp edge to the myEdges array
			}
			catch (ExceptionNode myNodeException)
			{
				cout << "Node not a part of the graph" << endl;//Output if the node is not a part of the given graph
			}
			break;
		}
		case 'R':
		{
			cin >> inputU >> inputV; // read in the edge details
			cout << "Removing the item " << inputU << " " << inputV << endl;
			try//try catch exception
			{
				if (!(masterGraph->isAnEdge(inputU, inputV))) throw ExceptionEdge();
				masterGraph->deleteEdge(inputU, inputV); // delete the edge in myEdges array
			}
			catch (ExceptionEdge myEdgeException)
			{
				cout << "Edge does not exist to be deleted" << endl;//Output if the edge doesnot exist
			}
			break;
		}
		case 'D':
		{
			cout<< *masterGraph; // display of graphDB
			//masterGraph->display();
			break;
		}
		case 'E':
		{
			cin >> inputU >> inputV; // read in the edge details

			bool flag = masterGraph->isAnEdge(inputU, inputV);//checking if the edge exists between u and v
			if (flag == true)
				cout << "Edge exists between " << masterGraph->getNode(inputU)->getNodeInfo() << " and " << masterGraph->getNode(inputV)->getNodeInfo() << endl;
			// cout << "true" << endl;
			else
				cout << "No edge exists between " << masterGraph->getNode(inputU)->getNodeInfo() << " and " << masterGraph->getNode(inputV)->getNodeInfo() << endl;
			break;
		}
		case 'N':
		{
			cin >> inputU;//read in node details
			masterGraph->findNeighbours(inputU);//calling findneighbours of GraphDB	
			break;
		}
		default:
			cout << "Command not recognized" << endl;//default case
			break;
		}
		cout << endl;
	}

	return 0;
	}

	//Reference-Project 1 by Adithya Narsimhan