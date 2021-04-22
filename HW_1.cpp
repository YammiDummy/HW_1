#include <iostream>
#include <string>
#include <optional>
#include <tuple>

using namespace std;

struct Person {

	string m_surname;
	string m_name;	
	optional<string> m_lastname;

	Person(string name, string surname) :
		m_surname(surname), m_name(name)  {}

	friend bool operator <(const Person& t1, const Person& t2);

	friend bool operator ==(const Person& t1, const Person& t2);

	friend ostream& operator<< (ostream& out, struct Person& person);
};

bool operator < (const Person& t1, const Person& t2){

	return tie(t1.m_surname, t1.m_name, t1.m_lastname) <
		   tie(t2.m_surname, t2.m_name, t2.m_lastname);
};

bool operator == (const Person& t1, const Person& t2){

	return tie(t1.m_surname, t1.m_name, t1.m_lastname) ==
		   tie(t2.m_surname, t2.m_name, t2.m_lastname);
};


ostream& operator<< (ostream& out, struct Person& person) {
	out << person.m_surname << " " << person.m_name << endl;
	return out;
};

int main() {
	Person p1("Yamilov", "Damir");
	Person p2("Davletbakova", "Aidina");
	cout << boolalpha << (p2 < p1) << endl;
	cout << boolalpha << (p1 == p2) << endl;
}