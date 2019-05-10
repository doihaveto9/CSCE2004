#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Part
{
public:
	Part();
	void set(string s, float c, int num, string m, string f);
	void get(string &s, float &c, int &num, string &m, string &f);
	void print();
        void stockprice(int num, float c);
private:
	string name;
	float cost;
	int stock;
	string material;
	string flammability;
};
