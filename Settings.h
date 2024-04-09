#pragma once
#include <iostream>
#include <fstream>

namespace extSort {

	class Settings {
	public:
		Settings() {}
		Settings(const std::string& settingsFile);

		void setSettings(const std::string& settings);
		void setFiles();

		std::string getResourcesPath() const;
		std::string getTemporaryPath() const;
		std::string getInputFile() const;
		std::string getOutputFile() const;
		int getSetArray(const int input) const;

	private:
		const std::string resourcesPath_ = "Resources/";
		const std::string temporaryPath_ = "tpm/";
		std::string inputFile_;
		std::string outputFile_;

		float setArray_[4] = { 0, 0, 0, 0 }; // 0 - write delay, 1 - move delay, 2 - read delay, 3 - max of RAM

		std::ifstream inputSettings_;
	};
}
