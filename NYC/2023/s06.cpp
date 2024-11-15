#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TEAM_SIZE 11

// 선수 구조체 정의
struct Player {
    string position;
    int overall;
    int price;
    int salary;
    string name;

    Player(string pos, int over, int pri, int sal, string nm)
        : position(pos), overall(over), price(pri), salary(sal), name(nm) {}
};

// 조건 정의
const int total_price_limit = 60;
const int total_salary_limit = 120;
const int required_gk = 1;
const int required_df_min = 3;
const int required_df_max = 5;
const int required_mf_min = 2;
const int required_mf_max = 5;
const int required_fw_min = 1;
const int required_fw_max = 4;

// 선수 데이터
vector<Player> players = {
    {"GK", 20, 3, 5, "na"},
    {"GK", 30, 5, 10, "nb"},
    {"DF", 10, 2, 5, "nc"},
    {"DF", 10, 3, 5, "nc"},
    {"DF", 15, 3, 10, "nd"},
    {"DF", 15, 4, 10, "ne"},
    {"DF", 20, 5, 15, "nf"},
    {"DF", 20, 6, 15, "ng"},
    {"MF", 15, 2, 5, "nh"},
    {"MF", 15, 2, 5, "ni"},
    {"MF", 20, 3, 10, "nj"},
    {"MF", 20, 4, 15, "nk"},
    {"MF", 20, 5, 15, "nl"},
    {"MF", 20, 6, 20, "nl"},
    {"FW", 20, 10, 20, "nm"},
    {"FW", 30, 15, 30, "nm"}
};

// 조합의 유효성 검사
int is_valid_combination(const vector<Player>& combination) {
    int position_count[4] = {0}; // GK, DF, MF, FW
    int total_price = 0;
    int total_salary = 0;
    int total_overall = 0;

    for (const Player& p : combination) {
        if (p.position == "GK") {
            position_count[0]++;
        } else if (p.position == "DF") {
            position_count[1]++;
        } else if (p.position == "MF") {
            position_count[2]++;
        } else if (p.position == "FW") {
            position_count[3]++;
        }
        total_price += p.price;
        total_salary += p.salary;
        total_overall += p.overall;
    }

    if (total_price > total_price_limit || total_salary > total_salary_limit) {
        return 0;
    }
    if (position_count[0] != required_gk ||
        position_count[1] < required_df_min || position_count[1] > required_df_max ||
        position_count[2] < required_mf_min || position_count[2] > required_mf_max ||
        position_count[3] < required_fw_min || position_count[3] > required_fw_max) {
        return 0;
    }
    return total_overall;
}

// 조합 생성
void find_best_combination(int start, vector<Player>& combination, int& best_overall) {
    if (combination.size() == TEAM_SIZE) { // 정확히 11명 선수가 필요
        int current_overall = is_valid_combination(combination);
        if (current_overall > best_overall) {
            best_overall = current_overall;
        }
        return;
    }

    for (int i = start; i < players.size(); i++) {
        combination.push_back(players[i]);
        find_best_combination(i + 1, combination, best_overall);
        combination.pop_back();
    }
}

int main() {
    vector<Player> combination;
    int best_overall = 0;

    find_best_combination(0, combination, best_overall);

    cout << "최대 오버롤의 합: " << best_overall << endl;

    return 0;
}
