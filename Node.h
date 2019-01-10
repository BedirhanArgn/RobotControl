#pragma once
#include"PioneerRobotAPI.h"
#include"Pose.h"
using namespace std;
/**
* @brief Path sinifi icin kullanilacak Linked list.
* 
*/

class Node
{
public:
	Node();
	~Node();
	Node* next;
	Pose _pose;
};

