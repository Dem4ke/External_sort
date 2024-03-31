#pragma once
#include <iostream>
#include <fstream>

class Settings {
public:
	Settings() {}
	Settings(std::string settingsFile) {
		setSettings(settingsFile);
	}
	// set settings from file
	void setSettings(std::string settings) {
		// open settings file
		inputSettings_.open(resourcesPath_ + settings);

		if (!inputSettings_) {
			std::cout << "Cannot open settings file\n";
			return;
		}

		// input settings in array
		for (int i = 0; i < 4; ++i) {
			inputSettings_ >> setArray_[i];
		}

		// close settings file
		inputSettings_.close();
	}

	// set input and output files
	void setFiles() {
		std::cout << "Enter name of input file: ";
		std::cin >> inputFile_;
		std::cout << "Enter name of output file: ";
		std::cin >> outputFile_;
	}

	std::string getResourcesPath() const { return resourcesPath_; }
	std::string getTemporaryPath() const { return temporaryPath_; }
	std::string getInputFile() const { return inputFile_; }
	std::string getOutputFile() const { return outputFile_; }
	int getSetArray(int input) const { return setArray_[input]; }

private:
	const std::string resourcesPath_ = "Resources/";
	const std::string temporaryPath_ = "tpm/";
	std::string inputFile_;
	std::string outputFile_;

	float  setArray_[4] = { 0, 0, 0, 0 }; // 0 - write delay, 1 - move delay, 2 - read delay, 3 - max of RAM

	std::ifstream inputSettings_;
};
