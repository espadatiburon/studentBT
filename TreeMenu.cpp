// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "BadIterator.h"
#include "InvalidTreeArgument.h"
#include "LevelOrderIterator.h"
#include "LevelOrderIterator.cpp"
#include "PreOrderIterator.h"
#include "PreOrderIterator.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "QueueNode.h"
#include "QueueNode.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "BinaryTreeIterator.h"
#include "BinaryTreeIterator.cpp"
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"

using namespace std;
using namespace cs20;

enum CHOICE {MAKEEMPTY, ISEMPTY, SIZE, HEIGHT, QUIT, PRINT, PRINTNODE, LEVELORDER, SETROOT, SETLEFT, SETRIGHT, GOTOROOT, GOLEFT, GORIGHT, ISONRIGHT, FINDMIN, PREORDER };

CHOICE menu();
void printTree( const BinaryTree<int>& t );

int main(int argc, char* argv[]) {
	int value;
	BinaryTree<int> tree;
	BinaryTreeNode<int> * node = nullptr;
	BinaryTree<int> lefttree;
	BinaryTree<int> righttree;
	BinaryTreeNode<int> * leftnode = nullptr;
	BinaryTreeNode<int> * rightnode = nullptr;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			tree.makeEmpty();
			node = nullptr;
			break;
		case ISEMPTY:
			if (tree.isEmpty()) {
				cout << "tree is empty" << endl;
			}
			else {
			cout << "tree is not empty" << endl;
			}
			break;
		case SIZE:
			if (node == nullptr) {
				cout << "You silly... the current node is nullptr!" << endl;
			}
			else {
				cout << "size of current node=" << BinaryTreeNode<int>::size( node ) << endl;
			}
			break;
		case HEIGHT:
			if (node == nullptr) {
				cout << "You silly... the current node is nullptr!" << endl;
			}
			else {
				cout << "height of current node=" << BinaryTreeNode<int>::height( node ) << endl;
			}
			break;
		case PRINT:
			printTree( tree );
			break;
		case PRINTNODE:
			if (node == nullptr) {
				cout << "You silly... the current node is nullptr!" << endl;
			}
			else {
				value = node->getElement();
				cout << "value of current node=" << value << endl;
			}
			break;
		case SETLEFT:
			try {
				cout << "Enter a value for node's leftside: ";
				cin  >> value;
				leftnode = new BinaryTreeNode<int>( value );
				node->setLeftSide( leftnode );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case SETRIGHT:
			try {
				cout << "Enter a value for node's rightside: ";
				cin  >> value;
				rightnode = new BinaryTreeNode<int>( value );
				node->setRightSide( rightnode );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case SETROOT:
			cout << "Enter root value: ";
			cin  >> value;
			// not sure this is too clever...
			tree = BinaryTree<int>( value );
			node = tree.getRoot();
			break;
		case LEVELORDER:
			try {
				LevelOrderIterator<int> iter( tree );
				iter.first();
				while( iter.isValid() ) {
					value = iter.retrieve();
					cout << value << " ";
					iter.advance();
				}
				cout << endl;
			}
			catch( BadIterator bi ) {
				cout << "badIterator exception caught!" << endl;
			}
			break;
		case  PREORDER:
			try{
				PreOrderIterator<int> iter(tree);
				iter.first();
				iter.queueAll();
				while(iter.isValid()){
					value = iter.retrieve();
					cout << value << " ";
					iter.advance();
				}
				cout << endl;
			}
			catch( BadIterator bi) {
				cout << "badIterator exception caught!" << endl;
			}
			break;
		case ISONRIGHT:
			try {
				cout << "Please insert a value: ";
				cin >> value;
				if(tree.isOnRightSide(value))
				{
					cout << "The value was found on the right side!" <<endl; 
				}
				else
				{
					throw(InvalidTreeArgument());
				}
			}
			catch (InvalidTreeArgument inval){
				cout << "InvalidTreeArgument exception caught!" << endl;
			}
			break;
		case FINDMIN:
			try{
				cout << "The smallest value is: " << tree.findMin() << endl;
			}
			catch (InvalidTreeArgument inval){
				cout << "InvalidTreeArgument exception caught!" << endl;
			}
			break;
		case GOTOROOT:
			node = tree.getRoot();			
			break;
		case GOLEFT:
			node = node->getLeftSide();
			break;
		case GORIGHT:
			node = node->getRightSide();
			break;
        case QUIT:
            break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

void printTree( const BinaryTree<int> & t ) {
	t.printTree( cout );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty (I)sEmpty (S)ize (H)eight setRoo(T) set(L)eftSide set(R)ightSide gotoroot(1) gole(F)t gori(G)ht (P)rint printN(O)de le(V)elOrder Pr(E)Order IsOnRight(2) FindMi(N) (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = SIZE;
		break;
	case 'I':
	case 'i':
		result = ISEMPTY;
		break;
	case 'H':
	case 'h':
		result = HEIGHT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'O':
	case 'o':
		result = PRINTNODE;
		break;
	case 'T':
	case 't':
		result = SETROOT;
		break;
	case 'V':
	case 'v':
		result = LEVELORDER;
		break;
	case 'L':
	case 'l':
		result = SETLEFT;
		break;
	case 'R':
	case 'r':
		result = SETRIGHT;
		break;
	case 'F':
	case 'f':
		result = GOLEFT;
		break;
	case 'G':
	case 'g':
		result = GORIGHT;
		break;
	case '2':
		result = ISONRIGHT;
		break;
	case 'N':
	case 'n':
		result = FINDMIN;
		break;
	case '1':
		result = GOTOROOT;
		break;
	case 'e':
	case 'E':
		result = PREORDER;
		break;
	}

	return( result );
}
