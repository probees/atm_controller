#include "model_proxy.h"
#include "model_local.h"
#include "model_remote.h"

#include <stdlib.h>

struct _model_context {
    int isDev;
};

atmmodel_t* create_model(int isDev) {
    atmmodel_t* model;
    struct _model_context* ctx = (struct _model_context*)malloc(sizeof(struct _model_context));
    ctx->isDev = isDev;
    model = (atmmodel_t*)ctx;
    return model;
}

void destroy_model(atmmodel_t** model) {
    struct _model_context* ctx = (struct _model_context*)*model;
    free(ctx);
    *model = 0;
}

void query_balance(atmmodel_t* model,const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    struct _model_context* ctx = (struct _model_context*)model;
    if(ctx->isDev) {
        return local_query_balance(query, result, row);
    }
    return remote_query_balance(query, result, row);
}
void query_deposit(atmmodel_t* model, const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    struct _model_context* ctx = (struct _model_context*)model;
    if(ctx->isDev) {
        return local_query_deposit(query, result, row);
    }
    return remote_query_deposit(query, result, row);
}

void query_withdraw(atmmodel_t* model, const char* query, char result[MAX_ROW][MAX_LINE], int* row) {
    struct _model_context* ctx = (struct _model_context*)model;
    if(ctx->isDev) {
        return local_query_withdraw(query, result, row);
    }
    return remote_query_withdraw(query, result, row);
}
