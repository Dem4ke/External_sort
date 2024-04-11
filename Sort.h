#pragma once
#include <string>
#include "Tape.h"
#include "Settings.h"

namespace extSort {

	class Sort {
	public:
		Sort(Tape& tape) : tape_(tape) {}
		// make parts
		void split(Settings& set, std::string input);
		// sort a temporary files until they done
		void selectionSort(Settings& set);
		// merge temporary files in output.txt
		void merge(Settings& set, std::string output);

	private:
		Tape& tape_;

		int count_ = 0;
	};
}
