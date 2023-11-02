#include <iostream>
#include <Windows.h>



using namespace std;



string question[9] = { "Який фрукт є символом Ньютона?",

                       "Який фрукт має червоний і жовтий різновид і використовується в салатах?",

                       "Який фрукт вирощується на пальмі і використовується для виробництва олії?",

                       "Який фрукт зазвичай використовується для приготування апельсинового соку?",

                       "Який фрукт дуже кислий і використовується для приготування лимонаду?",

                       "Який фрукт зазвичай використовується для приготування гуакамоле?",

                       "Який фрукт є символом тропіків і часто зображується на обкладинках журналів?",

                       "Який фрукт має тверду кірку і соковите рожеве м'ясо з чорним насінням усередині?",

                       "Який фрукт, що має гострий смак, часто використовується в суші та японській кухні?" };

string answer[9] = { "Яблуко", "", "Кокос", "Апельсин", "Лимон", "Авокадо", "Пальма", "Гранат", "Імбір" };





class Tables {
private:

    string question[9];
    string answer[9];
    bool finish = false;


public:

    //--------------------------------------------------------------------------

    void createGraphicsTable(string answer[]) {

        int spaceCout = 0;

        int findingChar = 0;

        for (int i = 0; i < answer[0].length(); i++) {

            for (int j = 0; j < answer[1].length(); j++) {

                if (answer[0][i] == answer[1][j]) {

                    spaceCout = i;

                    findingChar = j;

                    for (int k = j; k != 0; k--) {

                        for (int q = 0; q < spaceCout; q++) {

                            cout << "   ";

                        }

                        cout << "| |" << endl;

                    }

                    break;

                }

            }

        }

        for (int i = 0; i < answer[0].length(); i++) {
            cout << '|' << " " << '|';
        }
        cout << endl;
        for (int i = answer[1].length(); i > findingChar + 1; i--) {
            for (int q = 0; q < spaceCout; q++) {
                cout << "   ";
            }
            cout << "| |" << endl;

        }

        //--------------------------------------------------------------------------

    }

    bool Start() {
        bool isFinish = false;
        for (int i = 0; i < 9; i++){
            if (this->question[i] != "") {
                return  isFinish;
            }
        
        }
        return !isFinish;
    }

    void getQuestion() {
        for (int i = 0; i < 9; i++) {
            cout << this->question[i] << endl;
        }
        cout << "\n\n\n\n";
    }

    void setQuestionOfNumber(int number) {
        this->question[number] = "";
    }

    void numberOfQuerstion() {
        cout << "Number question:";
        int numberQ;
        cin >> numberQ;
        if (numberQ > 0 && numberQ < 10) {
            cout << this->question[numberQ - 1] << endl;
        }
        cout << "Enter answer";
        string userAnswer;
        cin >> userAnswer;
        if (userAnswer == this->answer[numberQ - 1]) {
            setQuestionOfNumber(numberQ - 1);
            cout << "Good" << endl;
        }
        else {
            cout << "Not good" << endl;
        }
    }


    Tables(string question[], string answer[]) {
        for (int i = 0; i < 9; i++) {
            this->question[i] = question[i];
            this->answer[i] = answer[i];
        }

        this->finish = Start();
        while(!this->finish){
            /*this->createGraphicsTable(answer);*/
            this->getQuestion();
            this->numberOfQuerstion();
            this->finish = this->Start();

            }
    }


};



int main()

{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tables game{ question,answer };

    //game.getQuestion();

}
