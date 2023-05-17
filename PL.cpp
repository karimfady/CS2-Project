#include "PL.h"
#include "BR.h"
#include "RBK.h"
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

double PL::compareUsingBruteForce(string filename) {
    FL file(filename);
    file.readfile(file.getfilename());
    vector<string>& fileContents = file.getContents();

    btotaloffile = file.getcountss(filename);

    for (int i = 0; i < btotaloffile; ++i) {
        const string& fileLine = fileContents[i];
        vector<string> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();
        vector<bool> isrp(numberofwordsofline, false);

        for (int z = 0; z < numberofwordsofline; z++) {
            for (int a = z + 1; a < numberofwordsofline; a++) {
                if (fileWords[z] == fileWords[a] && !isrp[a]) {
                    isrp[a] = true;
                }
            }
        }

        bool isPlagiarized = false;

        for (int j = 0; j < corpus.getSize(); ++j) {
            const string& corpusLine = corpus.getLineFromFile(j);
            int match = 0;
            int totalWords = 0;
            int count = 0;
            for (int b = 0; b < numberofwordsofline; b++) {
            
                if (isrp[b]) {
                    count++;
                }
                else {
                    const string& fileWord = fileWords[b];
   
                        auto starts = std::chrono::steady_clock::now();
                        match += BR::bruteForceSearch(fileWord, corpusLine);
                        auto ends = std::chrono::steady_clock::now();
                        btimetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();
                    
                }
            }

            if (match >= numberofwordsofline / 2) {
                isPlagiarized = true;
                break;
            }
        }

        if (isPlagiarized) {
            bmatchingCount++;
        }
    }

    bpercentage = bcalculatePercentage();
    cout << btimetaken << " In nanoseconds for a loop of an algorithm" << endl;
    return bpercentage;
}






double PL::compareUsingRabinKarp(string filename) {
    FL file(filename);
    file.readfile(file.getfilename());
    vector<string>& fileContents = file.getContents();

    rtotaloffile = file.getcountss(filename);

    for (int i = 0; i < rtotaloffile; ++i) {
        const string& fileLine = fileContents[i];
        vector<string> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();
        vector<bool> isrp(numberofwordsofline, false);

        for (int z = 0; z < numberofwordsofline; z++) {
            for (int a = z + 1; a < numberofwordsofline; a++) {
                if (fileWords[z] == fileWords[a] && !isrp[a]) {
                    isrp[a] = true;
                }
            }
        }

        bool isPlagiarized = false;

        for (int j = 0; j < corpus.getSize(); ++j) {
            const string& corpusLine = corpus.getLineFromFile(j);
            int match = 0;
            int totalWords = 0;
            int count = 0;
            for (int b = 0; b < numberofwordsofline; b++) {

                if (isrp[b]) {
                    count++;
                }
                else {
                    const string& fileWord = fileWords[b];
                    auto starts = std::chrono::steady_clock::now();
                    match += RBK::rkcheckPattern(fileWord, corpusLine);
                    auto ends = std::chrono::steady_clock::now();
                    rtimetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();

                }
            }

            if (match >= numberofwordsofline / 2) {
                isPlagiarized = true;
                break;
            }
        }

        if (isPlagiarized) {
            rmatchingCount++;
        }
    }

    rpercentage = rcalculatePercentage();
    cout << rtimetaken << " In nanoseconds for a loop of an algorithm" << endl;
    return rpercentage;
}



 


double PL::rcalculatePercentage() {
   
 return (rmatchingCount/ double(rtotaloffile)) * 100.0;
    
}
int PL::rgettimetaken() {
    return rtimetaken;
}
double PL::bcalculatePercentage() {

    return (bmatchingCount / double(btotaloffile)) * 100.0;

}
int PL::bgettimetaken() {
    return btimetaken;
}

vector<string> PL:: extractWords(const string& line) {
    vector<string> words;
    istringstream iss(line);
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}
