#include "Settings.h"
#include "Sort.h"

int main() {
	Settings settings("settings.txt");
	Sort sort;

	// ask to input and output files
	settings.setFiles();

	// make parts of files from input.txt
	sort.split(settings, settings.getInputFile());
	
	// sort temporary files
	sort.selectionSort(settings);
	
	// merge pairs of files in one
	sort.merge(settings, settings.getOutputFile());
	
	return 0;
}
