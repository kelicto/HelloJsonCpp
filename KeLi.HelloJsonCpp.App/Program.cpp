// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <json.h>
#include <string>

using namespace std;
using namespace Json;

void read_json1()
{
	ifstream ifs;

	ifs.open("test1.json");

	if (!ifs.is_open())
		return;

	Reader reader;
	Value root;

	if (!reader.parse(ifs, root, false))
		return;

	const int size = root.size();

	cout << "--- Total " << size << " elements ---" << endl;

	for (auto i = 0; i < size; ++i)
	{
		auto name = root[i]["name"].asString();
		const auto age = root[i]["age"].asInt();

		cout << "name: " << name << ", age: " << age << endl;
	}
}

void read_json2()
{
	ifstream ifs;

	ifs.open("test2.json");

	if (!ifs.is_open())
		return;

	Reader reader;
	Value root;

	if (!reader.parse(ifs, root, false))
		return;

	cout << "--- China City GDP ---" << endl;
	cout << "beijing-gdp: " << root["beijing"]["gdp"].asInt() << endl;
	cout << "beijing-population: " << root["beijing"]["population"].asInt() << endl;
	cout << "shanghai-gdp: " << root["shanghai"]["gdp"].asInt() << endl;
	cout << "shanghai-population: " << root["shanghai"]["population"].asInt() << endl;
}

void write_json(const string& file_path)
{
	Value root;
	FastWriter writer;
	Value person;

	person["age"] = 28;
	person["name"] = "XiGua";
	person["items"][0]["id"] = 11;
	person["items"][0]["name"] = "Test1";

	person["items"][1]["id"] = 22;
	person["items"][1]["name"] = "Test2";

	root.append(person);

	const auto content = writer.write(root);

	ofstream ofs;

	ofs.open(file_path);

	if (!ofs.is_open())
		return;

	ofs << content;
}

int main()
{
	try
	{
		read_json1();

		cout << endl;

		read_json2();

		cout << endl;

		write_json("test3.json");
	}
	catch (...)
	{
		cout << "Application error has occurred!" << endl;

		return -1;
	}

	return 0;
}
