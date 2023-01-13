#if defined(_WIN32)
#   define __export         __declspec(dllexport)
#elif defined(__GNUC__) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __export         __attribute__((visibility("default")))
#else
#   define __export
#endif

#define MAX_ROW  10
#define MAX_LINE 80

__export void remote_query_balance(const char* query, char result[MAX_ROW][MAX_LINE], int* row);
__export void remote_query_deposit(const char* query, char result[MAX_ROW][MAX_LINE], int* row);
__export void remote_query_withdraw(const char* query, char result[MAX_ROW][MAX_LINE], int* row);

