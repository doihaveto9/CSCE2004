#include "part.h"

Part::Part()
{
	name = "";
	cost = 0.0;
	stock = 0;
	material = "";
	flammability = "";
}

void Part::set(string s, float c, int num, string m, string f)
{
	name = s;
	cost = c;
	stock = num;
	material = m;
	flammability = f;
}

void Part::get(string &s, float &c, int &num, string &m, string &f)
{
	s = name;
	c = cost;
	num = stock;
	m = material;
	f = flammability;
}

void Part::print()
{
	cout << "Name: " << name << endl;
	cout << "Cost: " << cost << endl;
	cout << "Stock: " << stock << endl;
	cout << "Material: " << material << endl;
	cout << "Flammability: " << flammability << endl;
	cout << " " << endl;
}

void Part::stockprice(int num, float c)
{
	float sp = num * c;
	cout << "Total price of combined stock of this part: " << sp << endl;
}
