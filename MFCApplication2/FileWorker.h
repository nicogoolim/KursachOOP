#include <fstream>
#include <string>
#include <vector>
using namespace std;


template <class T>
class FileReader {
private:
	string path;
public:
	FileReader(string userPath) : path(userPath) {}
	vector<T> read() {
		vector<T> arr1;
		ifstream fin(path);
		while (true) { 
			if (fin.eof()) break;
			T cur;
			fin >> cur;
			arr1.push_back(cur);
		}
		fin.close();
		return arr1;
	}
	void write(string str) {

	}
};
