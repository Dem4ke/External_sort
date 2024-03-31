#include "Sort.h"

void Sort::split(Settings& set, std::string input) {
	// open input file
	input_.open(set.getResourcesPath() + input);

    if (!input_) {
		std::cout << "Cannot open input file\n";
		return;
	}
	
	// create temporary files and write all from input.txt to a few temporary files
	int next = 1;
	int temp = 0;
	int it = 0;

    while (input_) {

		// create temporary file
		output_.open(set.getTemporaryPath() + "temp_" + std::to_string(next));

		// split input tape
		tape_.splitTape(input_, output_, it);

		// close files
		output_.close();
		it = 0;
		++next;
	}

	// close input file
	input_.close();
	count_ = next;
}

void Sort::selectionSort(Settings& set) {
	int next = 1;

	while (count_ != 1) {
		// open file to read to array
		input_.open(set.getTemporaryPath() + "temp_" + std::to_string(next));

		// put input integers in array
		tape_.readTape(input_);

		input_.close();

		// sort array
		tape_.sortTape();

		// open file to write new array
		output_.open(set.getTemporaryPath() + "temp_" + std::to_string(next));

		// write array back in file
		tape_.writeTape(output_);

		// close file and clear RAM
		output_.close();
		tape_.clearTape();
		++next;
		--count_;
	}
	count_ = next - 1;
}

void Sort::merge(Settings& set, std::string output) {
	std::ifstream tempInput;
	int next = 0;
	int filePairs = (count_ + 1);
	int it = count_ + 1;
	int limit = count_;
	
	// create files and write sorted pairs of files in them
	while (filePairs > 1) {
		count_ = filePairs;
		next = it - 1;
		int exeption = next;

		while (count_ > 0) {
			// open needed files
			input_.open(set.getTemporaryPath() + "temp_" + std::to_string(next));
			if ((next - 1) != limit) {
				tempInput.open(set.getTemporaryPath() + "temp_" + std::to_string(next - 1));
			}
			output_.open(set.getTemporaryPath() + "temp_" + std::to_string(it));

			// compare nums and write them in output
			tape_.mergeTwoTapes(input_, tempInput, output_);

			// close files
			input_.close();
			tempInput.close();
			output_.close();
			next -= 2;
			count_ -= 2;
			++it;
		}

        filePairs = (filePairs + 1) / 2;
		limit = exeption;
	}
	
	// write from last temperary file to output.txt
	input_.open(set.getTemporaryPath() + "temp_" + std::to_string(it - 1));
	output_.open(set.getResourcesPath() + output);
	tape_.cloneTape(input_, output_);
	
	// close files
	input_.close();
	output_.close();
}
