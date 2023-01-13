#if defined(_WIN32)
#   define __export         __declspec(dllexport)
#elif defined(__GNUC__) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __export         __attribute__((visibility("default")))
#else
#   define __export
#endif

typedef void* atmmodel_t;

#define MAX_ROW  10
#define MAX_LINE 80

__export atmmodel_t* create_model(int isDev);
__export void destroy_model(atmmodel_t** model);

__export void query_balance(atmmodel_t* model, const char* query, char result[MAX_ROW][MAX_LINE], int* row);
__export void query_deposit(atmmodel_t* model, const char* query, char result[MAX_ROW][MAX_LINE], int* row);
__export void query_withdraw(atmmodel_t* model, const char* query, char result[MAX_ROW][MAX_LINE], int* row);
