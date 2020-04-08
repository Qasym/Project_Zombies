#pragma once
#include"Zombies.h"

bool in(char arr[], char chr) {
	for (int i = 0; i < 10; i++) {
		if (arr[i] == chr) return true;
	}
	return false;
}

Zombie* readerAndMaker(string& str) {
	string typeNum = "";
	string name = "";
	string speed = "";
	bool space = false;

	Zombie* zombie = new Zombie();

	char arr[10] = { '0', '1', '2', '3', '4' , '5', '6' , '7', '8', '9' };

	for (unsigned int i = 0; i < str.size(); i++) {
		if (in(arr, str.at(i)) && !space)
			typeNum += str.at(i);
		else if (str.at(i) == ' ')
			space = true;
		else if (!in(arr, str.at(i)) && space)
			name += str.at(i);
		else if (in(arr, str.at(i)) && space)
			speed += str.at(i);
	}

	int type = stoi(typeNum);

	if (type == 0) {
		zombie = new Zombie(name, stoi(speed));
	}
	else if (type == 1) {
		zombie = new LadderZombie(name, stoi(speed));
	}
	else if (type == 2) {
		zombie = new NewspaperZombie(name, stoi(speed));
	}
	else if (type == 3) {
		zombie = new DancingZombie(name, stoi(speed));
	}
	return zombie;
}

int readerForCake(string line) {
	bool space = false;
	string cake = "";
	for (unsigned int i = 0; i < line.size(); i++) {
		if (line.at(i) == ' ') space = true; //needed to ignore number of participants
		else if (space) cake += line.at(i);
	}
	return stoi(cake);
}

void writeOut(int num, string answer) {
	string address = "code outputs\\output" + to_string(num) + ".txt"; //file location may be different, in my case I've created separata directory for storing outputs
	ofstream outputs;
	outputs.open(address);
	outputs << answer;
	outputs.close();
}

void process(int num) {
	string data;
	string adress;
	ifstream listOfZombies;
	adress = "inputs\\i" + to_string(num) + ".txt"; //directory may be different if you download my code
	
	listOfZombies.open(adress);
	
	if (!listOfZombies.is_open()) {
		cout << "You did not open file. Try again.\n";
		exit(1);
	}

	getline(listOfZombies, data);
	int type = stoi(data);

	if (type == 1) {
		getline(listOfZombies, data);
		writeOut(num, readerAndMaker(data)->toString());
	}
	else if(type == 2){
		getline(listOfZombies, data);
		int massOfCake = readerForCake(data);
		int index = 0;
		vector<int> results;
		vector<Zombie*> zombies;

		while(getline(listOfZombies, data)){
			zombies.push_back(readerAndMaker(data));
			results.push_back(zombies[index++]->whoIsTheWinner(massOfCake));
		}
		int min = results[0];
		for (unsigned int i = 0; i < results.size(); i++) {
			if (results[i] < min) min = results[i];
		}
		for (unsigned int i = 0; i < results.size(); i++) {
			if (results[i] == min) {
				string answer = "Competition with " + to_string(massOfCake) + " grams of cake:\n" + zombies[i]->toString();
				writeOut(num, answer);
				break;
			}
		}	
	}
	listOfZombies.close();
}

void test() {
	vector<string> correctOutputs;
	vector<string> codeOutputs;
	string data;
	ifstream outputFile;
	
	for (int i = 0; i < 13; i++) {
		outputFile.open("correct outputs\\o" + to_string(i) + ".txt");
		while (getline(outputFile, data)) correctOutputs.push_back(data);
		outputFile.close();
	}
	for (int i = 0; i < 13; i++) {
		outputFile.open("code outputs\\output" + to_string(i) + ".txt");
		while (getline(outputFile, data)) codeOutputs.push_back(data);
		outputFile.close();
	}

	if (correctOutputs.size() != codeOutputs.size()) {
		cout << "Sizes are not equal! You did something wrong!\n";
		cout << "Test cases are failed\n";
		return;
	}
	for (int i = 0; i < correctOutputs.size(); i++) {
		if (correctOutputs[i] != codeOutputs[i]) {
			cout << "Test #: " << i << " failed.\n" << "You should have: " << correctOutputs[i] << "\nHowever you have: " << codeOutputs[i];
		}
		else {
			cout << "Test #: " << i << " completed succesfully!\n";
		}
	}
	return;
}
