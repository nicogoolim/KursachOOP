#include <fstream>
#include <string>
#include <vector>
using namespace std;


template <class T>
class FileWorker {
private:
	string path;
public:
	FileWorker(string userPath) : path(userPath) {}
	vector<T> read() {
		T cur;
		vector<T> arr1;
		ifstream fin(path);
		while (true) { 
			if (fin.eof()) break;
			fin >> cur;
			arr1.push_back(cur);
		}
		fin.close();
		return arr1;
	}
	void write(string str) {

	}
};

/**/
