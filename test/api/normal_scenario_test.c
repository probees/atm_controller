#include "model_proxy.h"
#include "controller.h"
#include <stdio.h>
#include <string.h>

int normal_scenario_test() {

    //TODO: Replace test runner to Google-Test.

    atmmodel_t* model;
    atmctl_t* controller;

    model = create_model(1);
    controller = create_controller(model);

    int ret = 0;

    do {
        //1. Insert Card
        Card_t card = {
            "1234567812345678",
            16,
            101
        };
        
        ret = insert_card(controller, &card);
        if(ret != 0) break;

        //2. PIN number
        ret = check_PIN(controller, 1, 2, 3, 4);
        if(ret != 0) break;

        //3. Select Account
        //TODO: add api to get index range of account
        ret = select_account(controller, 0);
        if(ret != 0) break;

        //4. See. 
        Balance_t balance;
        memset(&balance, 0, sizeof(balance));
        get_balance(controller, &balance);

        printf("balance : %d\n", balance.row);
        for(int i=0 ; i<balance.row ; i++) {
            printf("[%d] %s\n", i, balance.result[0]);
        }

        Deposit_t deposit;
        memset(&deposit, 0, sizeof(deposit));
        get_deposit(controller, &deposit);

        printf("deposit : %d\n", deposit.row);
        for(int i=0 ; i<deposit.row ; i++) {
            printf("[%d] %s\n", i, deposit.result[i]);
        }

        Withdraw_t withdraw;
        memset(&withdraw, 0, sizeof(withdraw));
        get_withdraw(controller, &withdraw);

        printf("withdraw : %d\n", withdraw.row);
        for(int i=0 ; i<withdraw.row ; i++) {
            printf("[%d] %s\n", i, withdraw.result[i]);
        }

    }while(0);


    destroy_controller(&controller);
    destroy_model(&model);


    return ret;
}
