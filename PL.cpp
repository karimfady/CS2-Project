#include "PL.h"
#include "BR.h"
#include "RBK.h"
#include <string>
#include <fstream>
#include <sstream>
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
                    match += BR::bruteForceSearch(fileWord, corpusWord);
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
                        match += RBK::search(fileWord, corpusWord);
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
    return percentage;
}



 


double PL::calculatePercentage() {
   
 return (matchingCount/ double(totaloffile)) * 100.0;
    
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