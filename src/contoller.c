
#include "model_proxy.h"
#include "controller.h"
#include "bank_api.h"
#include <stdlib.h>

struct _ctl_context {
    atmmodel_t* model;
    int isPassedPIN;
    int selcted_account_index;
    Card_t* card;
};

static int is_valid(struct _ctl_context* ctx) {
    if( ctx->card == 0 || ctx->isPassedPIN == 0)
        return 0; 

    return 1;
}

atmctl_t* create_controller(atmmodel_t* model) {
    //TODO: error handling
    atmctl_t* ctl;
    struct _ctl_context* ctx = (struct _ctl_context*)malloc(sizeof(struct _ctl_context));
    ctx->model = model;
    ctl = (atmctl_t*)ctx;

    return ctl;

}

void destroy_controller(atmctl_t** ctl) {
    //TODO: error handling
    struct _ctl_context* ctx = (struct _ctl_context*)*ctl;
    free(ctx);
    *ctl = 0;
}

int insert_card(atmctl_t* ctl, Card_t* card) {
    //TODO: error handling

    //TODO: Validation Check - Card

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;
    ctx->card = card;

    return 0;
}

int select_account(atmctl_t* ctl, int account_index) {
    //TODO: error handling

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;

    //TODO: check the index in range.
    ctx->selcted_account_index = account_index;
    return 0;
}

int check_PIN(atmctl_t* ctl, int i1, int i2, int i3, int i4) {
    //TODO: error handling

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;
    if(BANK_CHECK_PIN(i1, i2, i3, i4) == 0) {
        ctx->isPassedPIN = 1;
        return 0;
    }

    return -1;
}

int get_balance(atmctl_t* ctl, Balance_t* balance) {
    //TODO: error handling

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;
    if(is_valid(ctx) != 1) return -1;

    //FIXME: put in your CARD_ID
    query_balance(ctx->model, "SELECT * FROM Balance WHERE CARD_ID=XX, ACCOUNT_IDX=selcted_account_index", balance->result, &balance->row);
    return 0;
}

int get_deposit(atmctl_t* ctl, Deposit_t* deposit) {
    //TODO: error handling

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;
    if(is_valid(ctx) != 1) return -1;

    //FIXME: put your CARD_ID!
    //FIXME: put your Selected Account!
    query_deposit(ctx->model, "SELECT * FROM Deposit WHERE CARD_ID=XX, ACCOUNT_IDX=selcted_account_index", deposit->result, &deposit->row);
    return 0;
}

int get_withdraw(atmctl_t* ctl, Withdraw_t* withdraw) {
    //TODO: error handling

    struct _ctl_context* ctx = (struct _ctl_context*)ctl;
    if(is_valid(ctx) != 1) return -1;

    //FIXME: put in your CARD_ID
    query_withdraw(ctx->model, "SELECT * FROM Withdraw WHERE CARD_ID=XX, ACCOUNT_IDX=selcted_account_index", withdraw->result, &withdraw->row);
    return 0;
}