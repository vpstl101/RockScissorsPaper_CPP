#include <iostream>
#include <random>

using namespace std;

class Human
{
private:
    int input_num;
    int cnt;

public:
    Human() : input_num(0), cnt(0) {}

    enum class Player
    {
        ROCK,     // 0
        SCISSORS, // 1
        PAPER,    // 2
    };

    static void Ready()
    {
        cout << "=== AI vs Human ===" << endl;
        cout << "1.주먹 2.가위 3.보" << endl;
        cout << "숫자 입력: ";
    }

    int Action()
    {
        cin >> input_num;
        cin.ignore();

        switch (input_num)
        {
        case 1:
            cout << "Player '주먹' vs";
            return (int)Player::ROCK;
        case 2:
            cout << "Player '가위' vs";
            return (int)Player::SCISSORS;
        case 3:
            cout << "Player '보' vs";
            return (int)Player::PAPER;
        default:
            break;
        }
    }
};

class AI
{
private:
    int auto_ai;

public:
    AI() : auto_ai(0) {}

    enum class BetaGo
    {
        ROCK,
        SCISSORS,
        PAPER,
    };

    BetaGo Random()
    {
        random_device Ai; // c++용 랜덤
        mt19937 gen(Ai());
        uniform_int_distribution<int> Ai_Rand(0, 2);
        // cout << "랜덤값 확인용 0~2 : " << Ai_Rand(gen) << endl; //출력확인

        auto_ai = Ai_Rand(gen);
        return (BetaGo)auto_ai;
    }

    int AutoAi()
    {
        BetaGo Auto_ai = Random();
        switch (Auto_ai)
        {
        case BetaGo::ROCK:
            cout << " BetaGo '주먹'" << endl;
            return 0;
        case BetaGo::SCISSORS:
            cout << " BetaGo '가위'" << endl;
            return 1;
        case BetaGo::PAPER:
            cout << " BetaGo '보'" << endl;
            return 2;
        default:
            break;
        }
    }
};

class Battle
{
public:
    string match[3];
    int player;
    int ai;
    int result;

    Battle(Human Hu, AI Ai) // Human vs AI 변수 선언
    {
        match[0] = "Player Win";
        match[1] = "Player Lose";
        match[2] = "Player Draw";
        result=0;
        player = Hu.Action(); // Human Act함수 끌어오기
        ai = Ai.AutoAi();     // AI Auto함수 끌어오기
    }

    int Match() 
    {
        if (player == ai)
            cout << match[2] << endl;
        else if (player == 0)
        {
            if (ai == 1)
            {
                cout << match[0] << endl;
                return 1;
            }
            else if (ai == 2)
                cout << match[1] << endl;
        }
        else if (player == 1)
        {
            if (ai == 0)
                cout << match[1] << endl;
            else if (ai == 2)
            {
                cout << match[0] << endl;
                return 1;
            }                
        }
        else if (player == 2)
        {
            if (ai == 0)
            {
                cout << match[0] << endl;
                return 1;
            }
            else if (ai == 1)
                cout << match[1] << endl;
        }
        cout << '\n';
    }
   /* void Result()
    {
        result += Match();
        if(result >= 2)
            cout <<"결과: "<< match[0] << endl;
        else if (result < 2)
            cout << "결과: " << match[1] << endl;
        else if(!result)
            cout <<"결과: "<< match[2] << endl;
    }*/
};

int main()
{
    int cnt = 3;

    Human _1p; // class 변수
    AI betaGo;

    while (0 < cnt--)
    {
        Human::Ready();             // 1.출력문 함수 static은 이렇게 바꿔서?
        Battle battle(_1p, betaGo); // 2. 사람 vs 컴터
        battle.Match();             // 3. 쌈 -> 승 패 결과가 없음
        /*if (0 == cnt)
            battle.Result();*/
    }

    return 0;
}