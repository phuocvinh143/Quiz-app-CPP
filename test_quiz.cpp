#include<bits/stdc++.h>

using namespace std;

vector<string> ques[107], options;
string name_chapter, chapter_user_want;

void Intro(){
    ifstream input("Quiz.txt");
    //freopen("Quizz.txt", "r", stdin);
    while (getline(input, name_chapter)) {
        if (name_chapter[0] == 'C' && name_chapter[6] == ':') cout << name_chapter << endl;
    }
    input.close();
    cout << "Which chapter do you want to test? (1 -> 7) ";
    cin >> chapter_user_want;
}

void put_sentence(int k, int n) {
    string tmp = "";
    for (int i = 3; i < ques[k][n].size(); ++i) {
        if (i == 3 && ques[k][n][3] == '*') {
            tmp += ques[k][n][i];
            continue;
        }
        tmp += ques[k][n][i];
        cout << ques[k][n][i];
    }
    options.push_back(tmp);
    cout << endl;
}

int check_ans() {
    for (int i = 0; i < 4; ++i) {
        if (options[i][0] == '*') return i;
    }
}

int main(){
    srand(time(NULL));
    while (1) {
        Intro();
        int iQuest = 0;
        system("CLS");
        ifstream input_ques("Quiz.txt");
        while (true) {
            string name_chapter;
            getline(input_ques, name_chapter);
            int correct;
            if (name_chapter.size() > 5 && name_chapter[0] == 'C' && name_chapter[5] == chapter_user_want[0]) {
                while (getline(input_ques, name_chapter)) {
                    if (name_chapter.size() > 5 && name_chapter[5] != chapter_user_want[0] && (name_chapter[5] >= '1' && name_chapter[5] <= '9')) {
                        break;
                    }
                    if (ques[iQuest].size() > 4) {
                        ++iQuest;
                    }
                    ques[iQuest].push_back(name_chapter);
                }

                //print question
                correct = 0;
                for (int i = 0; i <= iQuest; ++i) {
                    options.clear();
                    cout << ques[i][0] << endl;
                    //random question
                    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
                    if (ques[i][4].size() > 10) {
                        if ((ques[i][4][3] == 'a' && ques[i][4][4] == 'l' && ques[i][4][5] == 'l') ||
                            (ques[i][4][3] == '*' && ques[i][4][4] == 'a' && ques[i][4][5] == 'l' && ques[i][4][6] == 'l')) n4 = 4;
                        else n4 = rand()%4 + 1;
                    }
                    else n4 = rand()%4 + 1;
                    do {n1 = rand()%4 + 1;} while (n1 == n4);
                    do {n2 = rand()%4 + 1;} while (n2 == n1 || n2 == n4);
                    n3 = 10 - n1 - n2 - n4;

                    //seed question
                    cout << "a. "; put_sentence(i, n1);
                    cout << "b. "; put_sentence(i, n2);
                    cout << "c. "; put_sentence(i, n3);
                    cout << "d. "; put_sentence(i, n4);

                    int ans = check_ans();
                    string choice;
                    cout << "\nYour choice is: "; cin >> choice; cout << endl;
                    int k = choice[0] % 'a';
                    if (k == ans) cout << "CORRECT!\n\n", ++correct;
                    else cout << "INCORRECT!\nThe answer is " << (char)('a' + ans) << "\n\n";
                    system("pause");
                    system("CLS");
                }
                printf("You have %d/%d correct answer!\n", correct, iQuest+1);
                break;
            }
        }
        input_ques.close();
        string user_choice;
        cout << "Wanna try again? y/n "; cin >> user_choice;
        if (user_choice == "y") {
            system("CLS");
            for (int i = 0; i <= iQuest; ++i) ques[i].clear();
            continue;
        }
        else break;
    }
}
