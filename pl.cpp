#include "PL.h"
#include "BR.h"
#include "RBK.h"
#include <QVector>
#include <QString>
#include <QStringList>
#include <chrono>

double PL::compareUsingBruteForce(QString filename) {
    FL file(filename);
    file.readfile(file.getfilename());
    QVector<QString> fileContents = file.getContents();


    btotaloffile = file.getcountss(filename);
    int wordThreshold = 0.5 * btotaloffile;

    for (int i = 0; i < btotaloffile; ++i) {
         QString fileLine = fileContents[i];
        QVector<QString> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();


        bool isPlagiarized = false;

        for (int j = 0; j < corpus.getSize(); ++j) {
            QString corpusLine = corpus.getLineFromFile(j);
            int match = 0;


            for (int b = 0; b < numberofwordsofline; b++) {



                    QString fileWord = fileWords[b];
                    auto starts = std::chrono::steady_clock::now();
                    match += BR::bruteForceSearch(fileWord, corpusLine);
                    auto ends = std::chrono::steady_clock::now();
                    btimetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();

            }

            if (match >= wordThreshold) {
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


double PL::compareUsingRabinKarp(QString filename) {
    FL file(filename);
    file.readfile(file.getfilename());
    QVector<QString> fileContents = file.getContents();


    rtotaloffile = file.getcountss(filename);
    int wordThreshold = 0.5 * rtotaloffile;

    for (int i = 0; i < btotaloffile; ++i) {
         QString fileLine = fileContents[i];
        QVector<QString> fileWords = extractWords(fileLine);
        int numberofwordsofline = fileWords.size();


        bool isPlagiarized = false;

        for (int j = 0; j < corpus.getSize(); ++j) {
            QString corpusLine = corpus.getLineFromFile(j);
            int match = 0;


            for (int b = 0; b < numberofwordsofline; b++) {



                    QString fileWord = fileWords[b];
                    auto starts = std::chrono::steady_clock::now();
                    match += RBK::rkcheckPattern(fileWord, corpusLine);
                    auto ends = std::chrono::steady_clock::now();
                    rtimetaken = std::chrono::duration_cast<std::chrono::nanoseconds>(ends - starts).count();

            }

            if (match >= wordThreshold) {
                            isPlagiarized = true;
                            break;
                        }
        }

        if (isPlagiarized) {
            rmatchingCount++;
        }
    }

    rpercentage = bcalculatePercentage();
    cout << rtimetaken << " In nanoseconds for a loop of an algorithm" << endl;
    return rpercentage;
}


double PL::rcalculatePercentage() {
    return (rmatchingCount / double(rtotaloffile)) * 100.0;
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

QVector<QString> PL::extractWords(QString& line) {
    QVector<QString> words = line.split(' ');
    return words;
}
