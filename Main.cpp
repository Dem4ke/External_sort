#include "Settings.h"
#include "Tape.h"
#include "Sort.h"

int main() {
	extSort::Settings settings{ "settings.txt" };
	extSort::Tape tape{ settings };
	extSort::Sort sort{ tape };

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
