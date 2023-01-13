#if defined(_WIN32)
#   define __export         __declspec(dllexport)
#elif defined(__GNUC__) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __export         __attribute__((visibility("default")))
#else
#   define __export
#endif


typedef void* atmctl_t;

//TODO: Issuer Identification Number Check-up
typedef struct {
    unsigned int* number;    
    unsigned int length;
    unsigned int issuing_network;

}Card_t;

//FIXME: Replace hard-coding.
#define MAX_ROW  10
#define MAX_LINE 80

typedef struct {
    char result[MAX_ROW][MAX_LINE];
    int row;

}Balance_t;

typedef struct {
    char result[MAX_ROW][MAX_LINE];
    int* row;

}Deposit_t;

typedef struct {
    char result[MAX_ROW][MAX_LINE];
    int* row;

}Withdraw_t;


__export atmctl_t* create_controller(atmmodel_t*);
__export void destroy_controller(atmctl_t** ctl);

__export int insert_card(atmctl_t* ctl, Card_t*);
__export int check_PIN(atmctl_t* ctl, int i1, int i2, int i3, int i4);
__export int select_account(atmctl_t* ctl, int account_index);

__export int get_balance(atmctl_t* ctl, Balance_t*);
__export int get_deposit(atmctl_t* ctl, Deposit_t*);
__export int get_withdraw(atmctl_t* ctl,Withdraw_t*);



