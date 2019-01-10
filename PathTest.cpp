#include<iostream>
#include"Path.h"
#include"Pose.h"
using namespace std;
int main() {
	Path path;
	Pose pose;
	int secim;
	while (1) {
		cout << "Konum eklemek icin bire basiniz" << endl;
		cout << "Yazdirmak icin 2" << endl;
		cout << "Konum kaldirmak icin 3 basiniz" << endl;
		cout << "Insert position icin 4 basiniz" << endl;
		cout << "Elemani bulmak icin 5 e basiniz" << endl;
		cout << "Get posu calistirmak icin 6'ya basiniz" << endl;
		cout << "Cikmak icin 7" << endl;
		cin >> secim;
		if (secim == 1) {
			int konum;
			float x, y, th;
			cout << "Konum giriniz" << endl;
			cin >> x >> y >> th;
			pose.setX(x);
			pose.setY(y);
			pose.setTh(th);
			path.addPos(&pose);
		}
		if (secim == 2) {
			path.print();
		}
		if (secim == 3) {
			int pozisyon;
			cout << "hangi pozisyonu kaldirmak istiyorsunuz" << endl;
			cin >> pozisyon;
			path.removePos(pozisyon);
		}
		if (secim == 4) {
			int index;
			float x, y, th;
			cout << "Hangi indexe eklemek istersiniz" << endl;
			cin >> index;
			cout << "Hangi konumu eklemek istersiniz" << endl;
			cin >> x >> y >> th;
			pose.setX(x);
			pose.setY(y);
			pose.setTh(th);
			path.insertPos(index, pose);
		}
		if (secim == 5) {
			int index;
			cout << "Hangi indexteki degeri istiyorsunuz" << endl;
			cin >> index;
			path.operator[](index);
		}
		if (secim == 6) {
			int index;
			cout << "Hangi indexteki degeri istiyorsunuz" << endl;
			cin >> index;
			path.getPos(index);
		}
		if (secim == 7) {
			exit(0);
		}
	}
	system("pause");
}