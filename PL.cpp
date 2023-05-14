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

    totaloffile = file.getcountss(filename);
   

   

    for (int i = 0; i < totaloffile; ++i) {
        const string& fileLine = fileContents[i];
        vector<string> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();
        

        bool isPlagiarized = false; 

        for (int j = 0; j < corpus.getSize(); ++j) {
            const string& corpusLine = corpus.getLineFromFile(0, j);
            vector<string> corpusWords = extractWords(corpusLine);
            int numberofwordsofcorpus = corpusWords.size();

            int match = 0;
            for (const string& fileWord : fileWords) { 

                
                for (const string& corpusWord : corpusWords) {
                    auto starts = std::chrono::steady_clock::now();
                    match += BR::bruteForceSearch(fileWord, corpusWord);
                    auto ends = std::chrono::steady_clock::now();
                    timetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();
                }
                
               
            }

            if (match >= numberofwordsofline / 2) {
                isPlagiarized = true;
                break;
            }
        }

        if (isPlagiarized) {
            matchingCount++;
            
        }
       

        
    }
    percentage = calculatePercentage();
    cout << timetaken << "  In nano seconds to for a loop of an algorthim" << endl;
    return percentage;
}

double PL::compareUsingRabinKarp(string filename) {
    FL file(filename);
    file.readfile(file.getfilename());
    vector<string>& fileContents = file.getContents();

    totaloffile = file.getcountss(filename);


    for (int i = 0; i < totaloffile; ++i) {
        const string& fileLine = fileContents[i];
        vector<string> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();


        bool isPlagiarized = false;

        for (int j = 0; j < corpus.getSize(); ++j) {
            const string& corpusLine = corpus.getLineFromFile(0, j);
            vector<string> corpusWords = extractWords(corpusLine);
            int numberofwordsofcorpus = corpusWords.size();

            int match = 0;
            for (const string& fileWord : fileWords) {
                for (const string& corpusWord : corpusWords) {
                    if (fileWord.size() > 0 && corpusWord.size() > 0) {
                        auto starts = std::chrono::steady_clock::now();
                        RBK rbk;
                        rbk.rabinkarp(fileWord, corpusWord);
                        match += rbk.getoccur();
                        auto ends = std::chrono::steady_clock::now();
                        timetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();
                    }
                }
            }


            if (match >= numberofwordsofline / 2) {
                isPlagiarized = true;
                break;
            }
        }

        if (isPlagiarized) {
            matchingCount++;

        }



    }



    percentage = calculatePercentage();
    cout << timetaken << "  In nano seconds to for a loop of an algorthim" << endl;
    return percentage;
}



 


double PL::calculatePercentage() {
   
 return (matchingCount/ double(totaloffile)) * 100.0;
    
}
int PL::gettimetaken() {
    return timetaken;
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
