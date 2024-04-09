#include "Tape.h"

namespace extSort {

	Tape::Tape() {
		set_.setSettings("settings.txt");
	}

	void Tape::moveLeft() {
		sleep(set_.getSetArray(1));
		--curCell_;
	}

	void Tape::moveRight() {
		sleep(set_.getSetArray(1));
		++curCell_;
	}

	void Tape::read(int* ptr) {
		sleep(set_.getSetArray(1));
		temp_ = *ptr;
	}

	void Tape::write(int* ptr) {
		sleep(set_.getSetArray(0));
		*ptr = temp_;
	}

	void Tape::splitTape(std::ifstream& input, std::ofstream& output, int it) {
		while (input >> temp_) {
			sleep(set_.getSetArray(1));
			output << temp_ << " ";
			sleep(set_.getSetArray(0));
			++it;
			if (it == (set_.getSetArray(3) / 4)) {
				break;
			}
		}
	}

	void Tape::readTape(std::ifstream& input) {
		while (input >> temp_) {
			sleep(set_.getSetArray(2)); // read
			sleep(set_.getSetArray(0)); // write
			sleep(set_.getSetArray(1)); // move
			curTape_.push_back(temp_);
		}

	}

	void Tape::writeTape(std::ofstream& output) {
		for (int& i : curTape_) {
			sleep(set_.getSetArray(2)); // read
			sleep(set_.getSetArray(0)); // write
			sleep(set_.getSetArray(1)); // move
			output << i << " ";
		}
	}

	void Tape::sortTape() {
		curCell_ = &curTape_[0];
		int length = curTape_.size();
		temp_ = 0;
		int counter = 0;
		while (length != 0) {
			int maxIndex = 0;
			for (int i = 0; i < curTape_.size() - 1; ++i) {
				read(curCell_);
				moveRight();
				if (temp_ > *curCell_) {
					sleep(set_.getSetArray(2));
					temp1_ = *curCell_;
					moveLeft();
					sleep(set_.getSetArray(2));
					temp2_ = *curCell_;
					sleep(set_.getSetArray(0));
					*curCell_ = temp1_;
					moveRight();
					sleep(set_.getSetArray(0));
					*curCell_ = temp2_;

					maxIndex = i;
				}
				++counter;
			}
			while (counter > 0) {
				moveLeft();
				--counter;
			}
			length = maxIndex;
		}
	}

	void Tape::clearTape() {
		curTape_.clear();
	}

	void Tape::mergeTwoTapes(std::ifstream& input1, std::ifstream& input2, std::ofstream& output) {
		input1 >> temp1_;
		sleep(set_.getSetArray(2)); // read
		sleep(set_.getSetArray(0)); // write
		sleep(set_.getSetArray(1)); // move
		input2 >> temp2_;
		sleep(set_.getSetArray(2)); // read
		sleep(set_.getSetArray(0)); // write
		sleep(set_.getSetArray(1)); // move

		while (input1 && input2) {

			if (temp1_ < temp2_) {
				output << temp1_ << " ";
				input1 >> temp1_;
				sleep(set_.getSetArray(2)); // read
				sleep(set_.getSetArray(0)); // write
				sleep(set_.getSetArray(1)); // move
			}
			else {
				output << temp2_ << " ";
				input2 >> temp2_;
				sleep(set_.getSetArray(2)); // read
				sleep(set_.getSetArray(0)); // write
				sleep(set_.getSetArray(1)); // move
			}
		}

		// if one of files is less that other we need to read the longer one
		while (input1) {
			output << temp1_ << " ";
			input1 >> temp1_;
			sleep(set_.getSetArray(2)); // read
			sleep(set_.getSetArray(0)); // write
			sleep(set_.getSetArray(1)); // move
		}
		while (input2) {
			output << temp2_ << " ";
			input2 >> temp2_;
			sleep(set_.getSetArray(2)); // read
			sleep(set_.getSetArray(0)); // write
			sleep(set_.getSetArray(1)); // move
		}
	}

	void Tape::cloneTape(std::ifstream& input, std::ofstream& output) {
		while (input >> temp1_) {
			output << temp1_ << " ";
			sleep(set_.getSetArray(2)); // read
			sleep(set_.getSetArray(0)); // write
			sleep(set_.getSetArray(1)); // move
		}
	}
}
