#pragma once
#include<iostream>
#include<PioneerRobotAPI.h>
#include"Node.h";
using namespace std;
/**
* @brief Linked list formunda yol planini yonetmeyi saglayan siniftir
*/
class Path
{
	friend ostream &operator<<(ostream& out, Node);
	friend istream &operator >> (istream& in, Pose &pose);
public:
	Path();
	~Path();
	/**
	* @brief Linked liste konum eklenmesi icin gereken siniftir.
	* @param Eklenmesi gereken konum bilgileri
	*/
	void addPos(Pose*); 
	/**
	* @brief Linked listeyi yazdirmak icin gereken siniftir.
	*/
	void print(); 
	/**
	* @brief Verilen index'teki konum bilgilerini dondurmek icin gereken siniftir.
	* @param Konumu dondurulmesi gereken index.
	*/
	Pose operator[](int);
	/**
	* @brief Verilen index'teki konum bilgilerini dondurmek icin gereken siniftir.
	* @param Konumu dondurulmesi gereken index.
	*/
	Pose getPos(int);
	/**
	* @brief Linked List'deki konumlari silmek icin gereken siniftir..
	* @param Silinecek konumun index degeridir.
	*/
	bool removePos(int);
	/**
	* @brief Verilen index'ten bir sonraya eleman eklenmesi icin gereken siniftir.
	* @param Eklenecek konum bilgilerini icerir.
	*/
	bool insertPos(int, Pose);
	Node* gethead();
private:
	Node* tail = new Node;
	Node* head = NULL;
	int number;
};