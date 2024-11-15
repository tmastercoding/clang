#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 16

typedef struct {
    char position[3];
    int overall;
    int price;
    int salary;
    char name[3];
} Player;

// 선수 데이터
Player players[MAX_PLAYERS] = {
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

// constraints
int total_price_limit = 60;
int total_salary_limit = 120;
int required_gk = 1;
int required_df_min = 3;
int required_df_max = 5;
int required_mf_min = 2;
int required_mf_max = 5;
int required_fw_min = 1;
int required_fw_max = 4;

// 조합의 유효성 검사
int is_valid_combination(Player combination[], int size) {
    int position_count[4] = {0}; // GK, DF, MF, FW
    int total_price = 0;
    int total_salary = 0;
    int total_overall = 0;

    for (int i = 0; i < size; i++) {
        Player p = combination[i];
        if (strcmp(p.position, "GK") == 0) {
            position_count[0]++;
        } else if (strcmp(p.position, "DF") == 0) {
            position_count[1]++;
        } else if (strcmp(p.position, "MF") == 0) {
            position_count[2]++;
        } else if (strcmp(p.position, "FW") == 0) {
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
void find_best_combination(int start, Player combination[], int size, int *best_overall) {
    for (int i = start; i < MAX_PLAYERS; i++) {
        combination[size] = players[i];
        int current_overall = is_valid_combination(combination, size + 1);
        if (current_overall > *best_overall) {
            *best_overall = current_overall;
        }
        find_best_combination(i + 1, combination, size + 1, best_overall);
    }
}

int main() {
    Player combination[MAX_PLAYERS];
    int best_overall = 0;

    find_best_combination(0, combination, 0, &best_overall);

    printf("최대 오버롤의 합: %d\n", best_overall);

    return 0;
}
