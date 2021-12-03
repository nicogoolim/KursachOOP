#include <fstream>
#include <string>

using namespace std;

class FileWorker {
private:
	string path;
public:
	FileWorker(string userPath) : path(userPath) {}

	int read() {
		ifstream fin(path);
		while (fin)
		{

		}
		fin.close();

	}

	void write(string str) {

	}
};