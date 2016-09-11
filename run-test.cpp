#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>

using namespace std;

void reset_stream(stringstream&);

int main(int argc, char* argv[]) {
	string programName(argv[1]);
	string programFile = programName + ".cpp";
	string executeFile = programName + ".out";
	int numberTest = atoi((const char*)argv[2]);
	stringstream command;
	command << "g++ " << programFile << " -o " << executeFile;
	system(command.str().c_str());
	for (int i = 0; i < numberTest; ++i) {
		reset_stream(command);
		command << "./" << executeFile << " " << programName << ".i" << i;
		cout << command.str() << endl;
		system(command.str().c_str());
		reset_stream(command);
		command << "diff -ys out.txt " << programName << ".o" << i;
		cout << command.str() << endl;
		system(command.str().c_str());
		cout << "=======================================================================";
	}
	return 0;
}

void reset_stream(stringstream& ss) {
	ss.str("");
	ss.clear();
}