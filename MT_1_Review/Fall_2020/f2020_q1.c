#include <stdio.h>
typedef enum {MON, TUE, WED, THUR, FRI, SAT, SUN} weekday;
// assumption: day_of_month is between 1 and 31
weekday get_day(weekday oct1_day_of_week, int day_of_month) {
    // implement function
    int days_diff = day_of_month - 1;
    int result_day = (oct1_day_of_week + days_diff) % 7;
    return(weekday)result_day;
}
int main() {
    printf("test: If oct 1 is monday, then oct 7 is sunday: ");
    if (get_day(MON, 7) == SUN) {
        printf("ok\n");
    } else {
        printf("fail\n");
    }

    printf("test2: if oct 1 is thursday, then oct 20 is tuesday: ");
    if (get_day(THUR, 20) == TUE) {
        printf("ok\n");
    } else {
        printf("fail\n");
    }
    return 0;
}