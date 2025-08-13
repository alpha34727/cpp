#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <iomanip>

using namespace std;

long long PLAYER_COUNT = 2;

#define TEST_COUNT 100000

#define CARD_COUNT 52*100

#define DEBUG false
#define DEBUG_PRINT_STATE_EVERYTIME_OUTPUT false

#define OUTPUT_RESULT_TO_CSV true

#if DEBUG
#define PRINT_DEBUG(msg) cout << msg;
    #if DEBUG_PRINT_STATE_EVERYTIME_OUTPUT
        #define PRINT_DEBUG(msg) cout << msg; print_state();
    #else
        #define PRINT_DEBUG(msg) cout << msg;
    #endif
#else
#define PRINT_DEBUG(msg);
#endif

struct Combination{
    long long c1, c2, c3, c4;
    uint8_t op1, op2, op3; // 0b00: +, 0b01: -, 0b10: *, 0b11: /
};

struct Player{
    Combination comb;
    long long chips = 1000000000;
    long long bet = 0;

    long long st_chips = 1000000000;
    long long en_chips;
};

Player players[10000];
Player banker;
bool card_deck[CARD_COUNT];

random_device rd;
mt19937 generator(rd());
long long rand_int(long long min, long long max);
long long rand_pick_card();

void game_reset();
bool check_if_has_maximum_bet();
long long calc_combination(long long player_id);

void print_state();
string get_comb_str(long long index);

bool run_a_round();

int main()
{
    for (PLAYER_COUNT = 2; PLAYER_COUNT <= 1300; PLAYER_COUNT++){
        #if OUTPUT_RESULT_TO_CSV
        ofstream out;
        out.open("result.csv", ios_base::app);
        #endif

        banker = { {0, 0, 0, 0, 0b1000, 0b1000, 0b1000}, 1000000000, 0, 1000000000, 0};
        for (long long i = 0; i < PLAYER_COUNT; i++){
            players[i] = { {0, 0, 0, 0, 0b1000, 0b1000, 0b1000}, 1000000000, 0, 1000000000, 0};
        }

        // 遊戲開始
        PRINT_DEBUG("遊戲開始\n");
        game_reset();

        // 支付入場費
        for (long long i = 0; i < PLAYER_COUNT; i++){
            PRINT_DEBUG("玩家" << i << "支付入場費：100回憶幣\n");
            players[i].chips -= 100;
        }

        for (long long test = 0; test < TEST_COUNT; test++){
            if (!run_a_round()){
                break;
            }
        }

        #if OUTPUT_RESULT_TO_CSV
        out << PLAYER_COUNT << "," << -banker.st_chips + banker.en_chips << ",";
        for (long long i = 0; i < PLAYER_COUNT; i++){
            out << -players[i].st_chips + players[i].en_chips << ",";
        }
        out << endl;
        #endif

        #if OUTPUT_RESULT_TO_CSV
        out.close();
        #endif

        if (PLAYER_COUNT % 10 == 0) {
            cout << "已完成 " << PLAYER_COUNT << " 名玩家的測試。" << endl;
        }
    }

    return 0;
}

bool run_a_round(){
    for (long long i = 0; i < PLAYER_COUNT; i++){
        if (players[i].chips < 50){
            return false;
        }
    }

    // 回合開始
    game_reset();
    PRINT_DEBUG("回合開始\n");

    // 莊家每個人發4張數字牌
    PRINT_DEBUG("莊家每個人發4張數字牌\n");
    for (long long i = 0; i < PLAYER_COUNT; i++){
        players[i].comb.c1 = rand_pick_card();
        players[i].comb.c2 = rand_pick_card();
        players[i].comb.c3 = rand_pick_card();
        players[i].comb.c4 = rand_pick_card();
        PRINT_DEBUG("玩家" << i << "的牌：\n" << players[i].comb.c1 << ", " << players[i].comb.c2 << ", " << players[i].comb.c3 << ", " << players[i].comb.c4 << "\n");
    }
    
    // 玩家下注（最低50）
    PRINT_DEBUG("玩家下注（最低50）\n");
    while (true){
        long long bet;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            if (players[i].chips >= 500){
                bet = rand_int(50, 500) / 50 * 50;
            }
            else{
                bet = rand_int(50, players[i].chips) / 50 * 50;
            }
            
            players[i].chips -= bet;
            players[i].bet = bet;
        }

        if (check_if_has_maximum_bet()){
            for (long long i = 0; i < PLAYER_COUNT; i++){
                PRINT_DEBUG("玩家" << i << "下注" << players[i].bet << "回憶幣\n");
            }

            break;
        }
        else{
            PRINT_DEBUG("沒有玩家下注達到最大下注額，重新下注\n");
            for (long long i = 0; i < PLAYER_COUNT; i++){
                players[i].chips += players[i].bet;
                players[i].bet = 0;
            }
        }
    }

    PRINT_DEBUG("玩家抽3張符號牌\n");
    for (long long i = 0; i < PLAYER_COUNT; i++){
        players[i].comb.op1 = rand_int(0, 3);
        players[i].comb.op2 = rand_int(0, 3);
        players[i].comb.op3 = rand_int(0, 3);
        PRINT_DEBUG("玩家" << i << "的數字及符號牌：" << get_comb_str(i) << "\n");
    }

    PRINT_DEBUG("開始計時30秒\n");

    PRINT_DEBUG("玩家將數字符號組合蓋在桌上\n");

    PRINT_DEBUG("公開「賭大」或「睹小」\n");

    bool is_bet_small = rand_int(0, 1);
    if (is_bet_small){
        PRINT_DEBUG("玩家「賭大」\n");
        PRINT_DEBUG("玩家公開數字符號組合\n");

        long long bet_min = 13 * 13 * 13 * 13 + 1;
        long long bet_min_count = 0;
        long long comb_result;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            comb_result = calc_combination(i);
            if (comb_result < bet_min) {
                bet_min = comb_result;
                bet_min_count = 1;
            }
            else if (comb_result == bet_min) {
                bet_min_count++;
            }
        }

        long long prize = -100;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            prize += players[i].bet;
        }
        banker.chips += prize;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            if (calc_combination(i) == bet_min){
                PRINT_DEBUG("玩家" << i << "贏了");
                players[i].chips += prize;
                banker.chips -= prize;
            }
            else {
                PRINT_DEBUG("玩家" << i << "輸了\n");
            }
        }
        PRINT_DEBUG("莊家獲得100回憶幣\n");
        banker.chips += 100;
    }
    else {
        PRINT_DEBUG("玩家下注「賭小」\n");
        PRINT_DEBUG("玩家公開數字符號組合\n");

        long long bet_max = 1 - 13 * 13 * 13;
        long long bet_max_count = 0;
        long long comb_result;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            comb_result = calc_combination(i);
            if (comb_result > bet_max) {
                bet_max = comb_result;
                bet_max_count = 1;
            }
            else if (comb_result == bet_max) {
                bet_max_count++;
            }
        }

        long long prize = -100;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            prize += players[i].bet;
        }
        banker.chips += prize;
        for (long long i = 0; i < PLAYER_COUNT; i++){
            if (calc_combination(i) == bet_max){
                PRINT_DEBUG("玩家" << i << "贏了\n");
                players[i].chips += prize;
                banker.chips -= prize;
            }
            else {
                PRINT_DEBUG("玩家" << i << "輸了\n");
            }
        }
        PRINT_DEBUG("莊家獲得100回憶幣\n");
        banker.chips += 100;
    }

    #if DEBUG
    print_state();
    #endif

    for (long long i = 0; i < PLAYER_COUNT; i++){
        players[i].en_chips = players[i].chips;
    }
    banker.en_chips = banker.chips;

    return true;
}

void game_reset(){
    for (long long i = 0; i < PLAYER_COUNT; i++){
        players[i].comb.c1 = 0;
        players[i].comb.c2 = 0;
        players[i].comb.c3 = 0;
        players[i].comb.c4 = 0;
        players[i].comb.op1 = 0b1000;
        players[i].comb.op2 = 0b1000;
        players[i].comb.op3 = 0b1000;
        players[i].bet = 0;
    }

    for (long long i = 0; i < CARD_COUNT; i++){
        card_deck[i] = true;
    }
}

long long rand_int(long long min, long long max){
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

long long rand_pick_card(){
    long long card = rand_int(0, CARD_COUNT - 1);

    while (card_deck[card] == false){
        card = rand_int(0, CARD_COUNT - 1);
    }

    card_deck[card] = false;
    return card;
}

bool check_if_has_maximum_bet(){
    long long max_bet = 0;
    long long max_bet_count = 0;
    for (long long i = 0; i < PLAYER_COUNT; i++){
        if (players[i].bet > max_bet){
            max_bet = players[i].bet;
            max_bet_count = 0;
        }
        else if (players[i].bet == max_bet){
            max_bet_count++;
        }
    }

    return max_bet_count == 0;
}

long long calc_combination(long long player_id){
    Combination &comb = players[player_id].comb;
    long long c1 = comb.c1 % 13 + 1;
    long long c2 = comb.c2 % 13 + 1;
    long long c3 = comb.c3 % 13 + 1;
    long long c4 = comb.c4 % 13 + 1;

    long long operand = (comb.op1 << 4) | (comb.op2 << 2) | comb.op3;

    switch (operand){
    case 0b000000:
        return c1 + c2 + c3 + c4;
    case 0b000001:
        return c1 + c2 + c3 - c4;
    case 0b000010:
        return c1 + c2 + c3 * c4;
    case 0b000011:
        return c1 + c2 + c3 / c4;
    case 0b000100:
        return c1 + c2 - c3 + c4;
    case 0b000101:
        return c1 + c2 - c3 - c4;
    case 0b000110:
        return c1 + c2 - c3 * c4;
    case 0b000111:
        return c1 + c2 - c3 / c4;
    case 0b001000:
        return c1 + c2 * c3 + c4;
    case 0b001001:
        return c1 + c2 * c3 - c4;
    case 0b001010:
        return c1 + c2 * c3 * c4;
    case 0b001011:
        return c1 + c2 * c3 / c4;
    case 0b001100:
        return c1 + c2 / c3 + c4;
    case 0b001101:
        return c1 + c2 / c3 - c4;
    case 0b001110:
        return c1 + c2 / c3 * c4;
    case 0b001111:
        return c1 + c2 / c3 / c4;
    case 0b010000:
        return c1 - c2 + c3 + c4;
    case 0b010001:
        return c1 - c2 + c3 - c4;
    case 0b010010:
        return c1 - c2 + c3 * c4;
    case 0b010011:
        return c1 - c2 + c3 / c4;
    case 0b010100:
        return c1 - c2 - c3 + c4;
    case 0b010101:
        return c1 - c2 - c3 - c4;
    case 0b010110:
        return c1 - c2 - c3 * c4;
    case 0b010111:
        return c1 - c2 - c3 / c4;
    case 0b011000:
        return c1 - c2 * c3 + c4;
    case 0b011001:
        return c1 - c2 * c3 - c4;
    case 0b011010:
        return c1 - c2 * c3 * c4;
    case 0b011011:
        return c1 - c2 * c3 / c4;
    case 0b011100:
        return c1 - c2 / c3 + c4;
    case 0b011101:
        return c1 - c2 / c3 - c4;
    case 0b011110:
        return c1 - c2 / c3 * c4;
    case 0b011111:
        return c1 - c2 / c3 / c4;
    case 0b100000:
        return c1 * c2 + c3 + c4;
    case 0b100001:
        return c1 * c2 + c3 - c4;
    case 0b100010:
        return c1 * c2 + c3 * c4;
    case 0b100011:
        return c1 * c2 + c3 / c4;
    case 0b100100:
        return c1 * c2 - c3 + c4;
    case 0b100101:
        return c1 * c2 - c3 - c4;
    case 0b100110:
        return c1 * c2 - c3 * c4;
    case 0b100111:
        return c1 * c2 - c3 / c4;
    case 0b101000:
        return c1 * c2 * c3 + c4;
    case 0b101001:
        return c1 * c2 * c3 - c4;
    case 0b101010:
        return c1 * c2 * c3 * c4;
    case 0b101011:
        return c1 * c2 * c3 / c4;
    case 0b101100:
        return c1 * c2 / c3 + c4;
    case 0b101101:
        return c1 * c2 / c3 - c4;
    case 0b101110:
        return c1 * c2 / c3 * c4;
    case 0b101111:
        return c1 * c2 / c3 / c4;
    case 0b110000:
        return c1 / c2 + c3 + c4;
    case 0b110001:
        return c1 / c2 + c3 - c4;
    case 0b110010:
        return c1 / c2 + c3 * c4;
    case 0b110011:
        return c1 / c2 + c3 / c4;
    case 0b110100:
        return c1 / c2 - c3 + c4;
    case 0b110101:
        return c1 / c2 - c3 - c4;
    case 0b110110:
        return c1 / c2 - c3 * c4;
    case 0b110111:
        return c1 / c2 - c3 / c4;
    case 0b111000:
        return c1 / c2 * c3 + c4;
    case 0b111001:
        return c1 / c2 * c3 - c4;
    case 0b111010:
        return c1 / c2 * c3 * c4;
    case 0b111011:
        return c1 / c2 * c3 / c4;
    case 0b111100:
        return c1 / c2 / c3 + c4;
    case 0b111101:
        return c1 / c2 / c3 - c4;
    case 0b111110:
        return c1 / c2 / c3 * c4;
    case 0b111111:
        return c1 / c2 / c3 / c4;
    default:
        return 0;
        break;
    }
}

string get_comb_str(long long index){
    string result = "";
    Combination &comb = players[index].comb;
    result += to_string(comb.c1 % 13 + 1);
    switch (comb.op1) {
        case 0:
            result += "+";
            break; // 0b00
        case 1:
            result += "-";
            break; // 0b01
        case 2:
            result += "*";
            break; // 0b10
        case 3:
            result += "/";
            break; // 0b11
        default:
            result += "?"; // Invalid operator
    }
    result += to_string(comb.c2 % 13 + 1);
    switch (comb.op2) {
        case 0:
            result += "+";
            break; // 0b00
        case 1:
            result += "-";
            break; // 0b01
        case 2:
            result += "*";
            break; // 0b10
        case 3:
            result += "/";
            break; // 0b11
        default:
            result += "?"; // Invalid operator
    }
    result += to_string(comb.c3 % 13 + 1);
    switch (comb.op3) {
        case 0:
            result += "+";
            break; // 0b00
        case 1:
            result += "-";
            break; // 0b01
        case 2:
            result += "*";
            break; // 0b10
        case 3:
            result += "/";
            break; // 0b11
        default:
            result += "?"; // Invalid operator
    }
    result += to_string(comb.c4 % 13 + 1);
    return result;
}

void print_state(){
    cout << "------------------------------------" << endl;

    cout << "莊家回憶幣：" << banker.chips << endl;

    cout << "------------------------------------" << endl;
    cout << "　　　　玩家  |";
    for (long long i = 0; i < PLAYER_COUNT; i++){
        cout << setw(14) << "#" << i+1 << " |";
    }
    cout << endl;

    cout << "　　　回憶幣  |";
    for (long long i = 0; i < PLAYER_COUNT; i++){
        cout << setw(15) << players[i].chips << " |";
    }
    cout << endl;

    cout << "　　　　下注  |";
    for (long long i = 0; i < PLAYER_COUNT; i++){
        cout << setw(15) << players[i].bet << " |";
    }
    cout << endl;

    cout << "　　　　組合  |";
    for (long long i = 0; i < PLAYER_COUNT; i++){
        cout << setw(15) << get_comb_str(i) << " |";
    }
    cout << endl;
    cout << "------------------------------------" << endl;

    cout << endl;
}