#include <iostream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include <fstream>
namespace fs = std::filesystem;
using namespace std;


int main() {
	int action;
	bool work = true;

	while (work) {
		cout << "Choose action(0.exit, 1-create file in current directory, 2.delete file in current directory," << endl
			<< " 3.rename file in current directory, 4.move file from current directory to chosen directory," << endl
			<< " 5.print file, 6.create directory, 7.remove directory with all content):";
		cin >> action;

		if (action == 0) {
			work = false;
			exit(-1);
		}

		if (action == 1) {
			string filename;
			cout << "Enter file name(with extension):";
			cin >> filename;
			cout << endl;
			ofstream file(filename);

			if (!file) {
				cout << "Error" << endl;
				work = false;
				exit(-2);
			}
			else {
				cout << filename << " created" << endl;
			}
			file.close();
		}

		if (action == 2) {
			string fname;
			cout << "Enter file name(with extension):";
			cin >> fname;
			fs::remove(fname);
			cout << endl;
			cout << fname << " removed" << endl;
		}

		if (action == 3) {
			string fname1, fname2;
			cout << "Enter name of file to rename(with extension):";
			cin >> fname1;
			cout << "\nEnter new name(with extension):";
			cin >> fname2;
			fs::rename(fname1, fname2);
			cout << fname1 << " renamed to " << fname2 << endl;
		}

		if (action == 4) {
			string fname, userpath, nname;
			cout << "Enter file name(with extension):";
			cin >> fname;
			cout << "\nEnter new path:";
			cin >> userpath;
			cout << "\nEnter new file name(with extension):";
			cin >> nname;
			userpath += "\\" + nname;
			fs::rename(fname, userpath);
			cout << "\nmoved" << endl;
		}

		if (action == 5) {
			string fname;
			cout << "Enter file name(with extension):";
			cin >> fname;
			ifstream file1(fname);
			char buff[50];
			cout << endl;
			while (!file1.eof()) {
				file1.getline(buff, 50);
				cout << buff << endl;
			}
			cout << "\n" << fname << " printed" << endl;
			file1.close();
		}

		if (action == 6) {
			string dname;
			cout << "Enter directory name:";
			cin >> dname;
			fs::create_directory(dname);
			if (fs::exists(dname)) {
				cout << dname << " created" << endl;
			}
			else {
				cout << "Error" << endl;
				exit(-1);
			}
		}

		if (action == 7) {
			string dname;
			cout << "Enter directory name to remove it with all content:";
			cin >> dname;
			if (fs::exists(dname)) {
				cout << "Error" << endl;
					exit(-2);
			}
			else {
				cout << dname << " removed with all content" << endl;
			}

		}

		cout << endl << endl;
	}


}