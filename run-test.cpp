#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
	string programFile(argv[1]);
	string programName = programFile.substr(0, programFile.find('.'));
	int numberTest = atoi((const char*)argv[2]);
	stringstream command;
	command << "g++ " << programFile << " -o " << programName << ".o";
	cout << command.str() << endl;
	system(command.str().c_str());
	for (int i = 0; i < numberTest; ++i) {
		command.str("");
		command.clear();
		command << "./" << programName << ".o " << programName << ".i" << i;
		cout << command.str() << endl;
	}
	return 0;
}