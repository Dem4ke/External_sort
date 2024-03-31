#pragma once
#include <vector>
#include "Settings.h"
#include <unistd.h>

class Tape {
public:
	Tape() {
		set_.setSettings("settings.txt");
	}

	void moveLeft();
	void moveRight();
	void read(int* ptr);
	void write(int* ptr);

	void splitTape(std::ifstream& input, std::ofstream& output, int it);
	void readTape(std::ifstream& input);
	void writeTape(std::ofstream& output);
	void sortTape();
	void clearTape();
	void mergeTwoTapes(std::ifstream& input1, std::ifstream& input2, std::ofstream& output);
	void cloneTape(std::ifstream& input, std::ofstream& output);

private:
	std::vector<int> curTape_;
	int* curCell_ = 0;

	int temp_ = 0;
	int temp1_ = 0;
	int temp2_ = 0;

	Settings set_;
};
