#pragma once

class Zombie {
protected:
	string _name;
	int _speed;
	int superPower = INT_MAX;
	int powerTime = INT_MAX;
	int drawback = INT_MAX;
public:
	Zombie() {}
	Zombie(string name, int speed) {
		_name = name;
		_speed = speed;
	}
	virtual string toString() {
		string result;
		result = _name + " is the winner! Ancient Zombies are the best!";
		return result;
	}
	int whoIsTheWinner(int massOfCake) {
		int i = 0;
		while(massOfCake > 0) {
			i++;
			if (i % drawback == 0)
				continue;
			else if (i % powerTime == 0) {
				massOfCake -= superPower;
			}
			
			massOfCake -= _speed;

		}
		return i;
	}
};

class LadderZombie : public Zombie {
public:
	LadderZombie() {}
	LadderZombie(string name, int speed) : Zombie(name, speed) {
		superPower = 20;
		powerTime = 4;
	}
	string toString() override {
		string result;
		result = _name + " is the winner! Ladder Zombies are the best!";
		return result;
	}
};

class DancingZombie : public Zombie {
public:
	DancingZombie() {}
	DancingZombie(string name, int speed) : Zombie(name, speed) {
		superPower = 25;
		powerTime = 3;
		drawback = 7;
	}
	string toString() override {
		string result;
		result = _name + " is the winner! Dancing Zombies are the best!";
		return result;
	}
};

class NewspaperZombie : public Zombie {
public:
	NewspaperZombie() {}
	NewspaperZombie(string name, int speed) : Zombie(name, speed) {
		superPower = 30;
		powerTime = 6;
		drawback = 10;
	}
	string toString() override {
		string result;
		result = _name + " is the winner! Newspaper Zombies are the best!";
		return result;
	}
};
