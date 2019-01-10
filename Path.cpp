#include "Path.h"
using namespace std;

Node *temp;
Path::Path()
{
}
Path::~Path()
{
}

void Path::addPos(Pose *pos)
{
	Node *element = new Node;
	element->_pose = *pos;
	element->next = NULL;
	if (head == NULL) {
		head = element;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = element;
	}
}

void Path::print()
{
	temp = head;
	if (head == NULL) {
		cout << "Konum yok" << endl;
	}
	else {
		while (temp->next != NULL) {
			cout << "Konumlar: " << temp->_pose.getX() << "," << temp->_pose.getY() << "," << temp->_pose.getTh() << endl;
			temp = temp->next;
		}
		cout << "Konumlar: " << temp->_pose.getX() << "," << temp->_pose.getY() << "," << temp->_pose.getTh() << endl;
	}
}

Pose Path::operator[](int index)
{
	Node* aranan = new Node;
	aranan = head;
	Node *aranan2 = new Node;
	aranan2 = head;
	int count = 0;
	Node* bulunan = new Node;
	while (aranan->next != NULL) {
		if (count == index) {
			bulunan = aranan;
			break;
		}
		count++;
		aranan = aranan->next;
	}
	return bulunan->_pose;
}
Pose Path::getPos(int index)
{
	int sayac = 0;
	Node *element = new Node;
	element->next = NULL;
	element = head;
	while (element != NULL) {
		if (sayac == index) {
			return element->_pose;
		}
		element = element->next;
		sayac++;
	}
}
bool Path::removePos(int index)
{
	Node* dizitut = new Node;
	dizitut = head;
	Node* silgecici = new Node;
	if (index == 0) {
		silgecici = dizitut;
		dizitut = dizitut->next;
		free(silgecici);
		head = dizitut;
	}
	else if (index > 0) {
		Node* elemansay = new Node;
		elemansay = head;
		int count = 0;
		while (elemansay->next->next != NULL) {
			if (count == index - 1) {
				break;
			}
			count++;
			elemansay = elemansay->next;
		}
		if (elemansay->next->next != NULL) {
			Node *temp1 = new Node;
			temp1 = elemansay->next->next;
			Node *temp2 = new Node;
			temp2 = elemansay;
			free(elemansay->next);
			temp2->next = temp1;
		}
		else {
			Node* temp = new Node;
			temp = elemansay->next;
			delete(temp);
			elemansay->next = NULL;
		}
	}
	return true;
}
bool Path::insertPos(int index, Pose pose)
{
	Node *temp;
	temp = head;
	Node *data = new Node;
	data->_pose = pose;
	Node *element = new Node;
	Node *temp2 = new Node;
	int sayac = 0;
	if (index == 0) {
		element->_pose = pose;
		temp2 = head;
		element->next = temp2;
		head = element;
	}
	else {
		while (temp != NULL) {
			if (index == sayac) {
				break;
			}
			temp = temp->next;
			sayac++;
		}
		Node *tmp2 = new Node;
		tmp2 = temp->next;
		temp->next = data;
		data->next = tmp2;
		return true;
	}
}
Node* Path::gethead()
{
	return head;
}
ostream & operator<<(ostream & out, Node node)
{
	out << node._pose.getX() << "," << node._pose.getY() << "," << node._pose.getTh() << endl;
	return out;
}
istream & operator >> (istream & in, Pose &pose)
{
	float x, y, th;
	in >> x >> y >> th;
	pose.setPose(x, y, th);
	return in;
}