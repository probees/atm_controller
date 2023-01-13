#include "model_remote.h"

#include <string.h>
#include <stdio.h>

void remote_query_balance(const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    static const char _db[1][80] = {
        "BALANCE : 123"
    };

    memcpy(result[0], _db[0], 80*sizeof(char));
    *row = 1;
}

void remote_query_deposit(const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    static char _db[3][80] = {
        "DEPOSIT : 100",
        "DEPOSIT : 200",
        "DEPOSIT : 300"
    };

    memcpy(result[0], _db[0], 80*sizeof(char));
    memcpy(result[1], _db[1], 80*sizeof(char));
    memcpy(result[2], _db[2], 80*sizeof(char));
    *row = 3;
}

void remote_query_withdraw(const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    static char _db[1][80] = {
        "WITHDRAW : 300",
    };

    memcpy(result[0], _db[0], 80*sizeof(char));
    *row = 1;
}
