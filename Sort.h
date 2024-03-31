#pragma once
#include <vector>
#include <string>
#include "Tape.h"
#include "Settings.h"

class Sort {
public:
	// make parts
	void split(Settings& set, std::string input);
	// sort a temporary files until they done
	void selectionSort(Settings& set);
	// merge temporary files in output.txt
	void merge(Settings& set, std::string output);

private:
	Tape tape_;
	std::ifstream input_;
	std::ofstream output_;

	std::vector<int> nums_;
	int count_ = 0;
};
