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
	void write(vector<T> cur) {
		ofstream fout(path);
		for (int i = 0; i < cur.size(); i++) {
			fout << cur[i];
			if (i!=cur.size()-1)
			{
				fout << "\n";
			}
		}
		fout.close();
	}
};
