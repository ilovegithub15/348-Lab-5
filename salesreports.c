#include <stdio.h>
void monthlysalesreport(double sales[12]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("Monthly Sales Report for 2024\n");
    printf("\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("%-15s $%-14.2f\n", months[i], sales[i]);
    }
}