#include <stdio.h>
#include <string.h>

extern int normal_scenario_test();

int main(int argc, char** argv) {

    //TODO: Replace test runner to Google-Test.
    int ret = 0;
    do {
        ret = normal_scenario_test();
        printf("normal_scenario_test is %s\n", (ret==0)?"pass":"fail");

        //TODO: add unittest of APIs
        

    } while(0);
    

    return ret;
}
