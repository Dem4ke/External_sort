#pragma once
#include <vector>
#include "Settings.h"
#include <unistd.h>

namespace extSort {

	class Tape {
	public:
		Tape(Settings& set) : set_(set) {}

		void tapeDelay();
        	void moveLeft();
		void moveRight();
		void read(int* ptr);

		void splitTape(std::ifstream& input, std::ofstream& output, int it);
		void readTape(std::ifstream& input);
		void writeTape(std::ofstream& output);
		void sortTape();
		void clearTape();
		void mergeTwoTapes(std::ifstream& input1, std::ifstream& input2, std::ofstream& output);
		void cloneTape(std::ifstream& input, std::ofstream& output);

	private:
		std::vector<int> curTape_;
		int* curCell_ = nullptr;

		int temp_ = 0;
		int temp1_ = 0;
		int temp2_ = 0;

		Settings& set_;
	};
}
