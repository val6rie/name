#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void chang(int num_of_asks) {
    ofstream fout("answers.txt");
    ifstream fin("asks.txt");
    ofstream faout("asks.txt");
    string s;
    int i = 1, nu, kof = 0;
    vector<string> quest;
    while (getline(fin, s)) {
        if (kof == 0) {
            kof++;
        }
        else {
            cout << i << '.' << s << endl;
            quest.push_back(s);
            i++;
        }
    }
    cout << "Your goal:\n" << "1.Change the question\n2.Delete the question\n3.Add the question\n(enter the num of the desired option)\n";
    cin >> nu;
    if (nu == 1) {
        int chan;
        cout << "Enter the num of question:\n";
        cin >> chan;
        cout << "Print the question (in format " << chan << ". question):\n";
        string j;
        cin >> j;
        getline(cin, s);
        // cout << s << endl;
        // cout << quest[chan - 1];
        quest[chan - 1] = s.substr(1, s.length());
    }
    else if (nu == 2) {
        int del;
        cout << "Enter the num of question:\n";
        cin >> del;
        quest.erase(quest.begin() + del - 1);
        // cout << quest[del - 1];
    }
    else if (nu == 3) {
        cout << "Print the question (in format " << quest.size() + 1 << ". question):\n";
        string j;
        cin >> j;
        getline(cin, s);
        quest.push_back(s.substr(1, s.length()));

    }

    faout << quest.size() << endl;
    for (int f = 0; f < quest.size(); f++) {
        faout << quest[f] << endl;
    }

    fout << 0;
}


void outp(int num_of_asks, int weii) {
    string s, as, popul;
    int num_of_pe, num_of_ask, i = 0, ia = 0, maxp = 0;
    ifstream fin("answers.txt");
    ifstream fain("asks.txt");
    vector<string> pops;
    fain >> num_of_asks;

    while (getline(fain, as)) {
        if (ia == 0) {
            ia++;
        }
        else {
            if (weii > as.length()) {
                cout << as.substr(0, as.length() - 1) << ' ';
                for (int p = 0; p < weii - as.length(); p++) {
                    cout << " ";
                }
            }
            else {
                cout << as.substr(0, weii - 4) << "... ";
            }

        }
    }

    cout << endl;
    fin >> num_of_pe;


    while (getline(fin, s)) {
        if (i % num_of_asks == 0 and i != 0) {
            if (weii > s.length()) {
                cout << s.substr(0, s.length() - 1) << ' ';
                for (int p = 0; p < weii - s.length(); p++) {
                    cout << " ";
                }
                cout << endl;
            }
            else {
                cout << s.substr(0, weii - 4) << "..." << endl;
            }
            pops.push_back(s);
            i = -1;
        }
        else if (i != 0) {
            if (weii > s.length()) {
                cout << s.substr(0, s.length() - 1) << ' ';
                for (int p = 0; p < weii - s.length(); p++) {
                    cout << " ";
                }
            }
            else {
                cout << s.substr(0, weii - 4) << "... ";
            }
        }
        i++;
    }



    for (int j = 0; j < num_of_pe; j++) {
        int nowp = 0;
        string nowl = pops[j];
        for (int r = 0; r < num_of_pe; r++) {
            if (nowl == pops[r]) {
                nowp++;
            }
        }
        if (nowp > maxp) {
            maxp = nowp;
            popul = nowl;
        }
    }

    cout << endl << "statistic:" << endl << "the survey was conducted by " << num_of_pe << " people" << endl;
    cout << "the most popular answer to the last question is: " << popul << endl;
}





int main() {
    int num, num_of_asks, num_of_pe;
    string  ans, as, s;
    ifstream fin("asks.txt");
    fin >> num_of_asks;
    cout << "Your goal:" << endl << "1.Conduct a survey" << endl << "2.Output saved results" << endl << "3.Edit test questions" << endl << "(enter the num of the desired option)" << endl;
    cin >> num;

    if (num == 1) {
        ifstream fanin("answers.txt");
        fanin >> num_of_pe;
        vector<string> aaas;


        while (getline(fanin, as)) {
            aaas.push_back(as);
        }

        ofstream fout("answers.txt");
        int line = 0;
        while (getline(fin, s)) {
            cout << s << endl;
            getline(cin, ans);
            aaas.push_back(ans);

        }
        num_of_pe++;
        fout << num_of_pe;
        for (int i = 0; i < aaas.size(); i++) {
            fout << aaas[i] << endl;

        }
    }
    else if (num == 2) {
        cout << "Enter the weigth of the desired table (at least " << num_of_asks * 6 << "): ";
        int wei;
        cin >> wei;
        outp(num_of_asks, wei / num_of_asks);
    }
    else if (num == 3) {
        chang(num_of_asks);
    }
}