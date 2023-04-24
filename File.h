#include <string>
using namespace std;
class File {
protected:
    string filename;
    int count;
public:
    string* contents;
    File(string fname);
    File();
    void readfile(string fname);
    int getcount(string fname);
    string getfilename();
};

