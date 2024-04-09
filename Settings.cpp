#include "Settings.h"

namespace extSort {

	Settings::Settings(const std::string& settingsFile) {
		setSettings(settingsFile);
	}

	// set settings from file
	void Settings::setSettings(const std::string& settings) {
		// open settings file
		inputSettings_.open(resourcesPath_ + settings);

		if (!inputSettings_) {
			std::cerr << "Cannot open settings file\n";
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
	void Settings::setFiles() {
		std::cout << "Enter name of input file: ";
		std::cin >> inputFile_;
		std::cout << "Enter name of output file: ";
		std::cin >> outputFile_;
	}

	std::string Settings::getResourcesPath() const {
		return resourcesPath_;
	}

	std::string Settings::getTemporaryPath() const {
		return temporaryPath_;
	}

	std::string Settings::getInputFile() const {
		return inputFile_;
	}

	std::string Settings::getOutputFile() const {
		return outputFile_;
	}

	int Settings::getSetArray(int input) const {
		return setArray_[input];
	}
}
