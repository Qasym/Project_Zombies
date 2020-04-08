#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;  //it is essential since I did not specify identifiers' location, for instance I wrote cout<<, not std::cout<<

#include"Functions.h"
#include"Zombies.h"


int main() {
	for (int i = 0; i < 13; i++)
		process(i);
	test();
}