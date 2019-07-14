#include <iostream>
#include<string>
#include<cstdlib>
#include <ctime>
using namespace std;

class Avengers
{
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
		dead = 0;
	}
	~Avengers() {}

	virtual void set(string _name, int _attack, int _defense, int _health)
	{
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	
	virtual int attack()
	{
		return 0;
	}
	
	virtual void defense(int _attack_point)
	{
		int damage = _attack_point - defense_point;
		health -= damage;
	}
	
	virtual void print_info()
	{
		cout << "Name : " << name << endl;
		cout << "Attack_Point : " << attack_point << endl;
		cout << "Defense_Point : " << defense_point << endl;
		cout << "Health : " << health << endl;
	}
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
};

class Character : public Avengers
{
public:
	
	int get_health() { return health; }

	int attack() override 
	{
		return attack_point;
	}
};

int main()
{
	Character my_char;
	Character enemy_char;
	string user_input;
	int check = 1;
	int random_input = rand()% 3+1;

	while (check) {
		cout << "Choose your character(IronMan, CaptainAmerica, Thor) : ";
		cin >> user_input;
		if (user_input == "IronMan" || user_input == "ironman") {
			my_char.set("IronMan", 70, 40, 100);
			check = 0;
		}
		else if (user_input == "CaptainAmerica" || user_input == "captainamerica") {
			my_char.set("CaptainAmerica", 60, 50, 100);
			check = 0;
		}
		else if (user_input == "Thor" || user_input == "thor") {
			my_char.set("Thor", 80, 30, 100);
			check = 0;
		}
		if (random_input == 1) {
			enemy_char.set("IronMan", 70, 40, 100);
		}
		if (random_input == 2) {
			enemy_char.set("CaptainAmerica", 60, 50, 100);
		}
		if (random_input == 3) {
			enemy_char.set("Thor", 80, 30, 100);
		}
		else {
			cout << "Invalid input of your character Please write again" << endl;
			continue;
		}
			
	}

	cout << "\n--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life:" << enemy_char.get_health() << endl;
	int attack_time = 3;
	while (1)
	{
		if (my_char.get_health() <= 0 || enemy_char.get_health() <= 0) {
			if (my_char.get_health() <= 0) {
				cout << "My Life: 0" << "    " << "Enemy Life: " << enemy_char.get_health() << endl;
				cout << "Enemy wins!!!" << endl;
			}
			else {
				cout << "My Life: " << my_char.get_health() << "    " << "Enemy Life: 0" << endl;
				cout << "You win!!!" << endl;
			}
			
			break;
		}
		if (attack_time % 2 == 1) {
			enemy_char.defense(my_char.attack());
		}
		if (attack_time % 2 == 0) {
			my_char.defense(enemy_char.attack());
		}
		if(my_char.get_health() > 0 && enemy_char.get_health() >0)
			cout << "My Life: " << my_char.get_health() << "    " << "Enemy Life: " << enemy_char.get_health() << endl;
		++attack_time;
	}
	return 0;
}
