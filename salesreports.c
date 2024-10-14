#include <stdio.h>
void monthlysales1(double sales[12]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("Monthly Sales Report for 2024\n");
    printf("\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-15s $%-14.2f\n", months[i], sales[i]);
    }
}
void monthlysales2(double sales[12]) {
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = 0;
    int minIndex = 0;
    int maxIndex = 0;

    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        totalSales += sales[i];
        if (sales[i] < minSales) {
            minSales = sales[i];
            minIndex = i;
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxIndex = i;
        }
    }
    double averageSales = totalSales / 12;

    printf("\nSales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[maxIndex]);
    printf("Average sales: $%.2f\n", averageSales);
    printf("\n");
}
void monthlysales3(double sales[12]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= 6; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }
        printf("%-15s - %-15s $%-14.2f\n", months[i], months[i + 5], sum / 6.0);
    }
}
int main() {
    double monthlySales[12] = {
        23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22
    };
    monthlysales1(monthlySales);
    monthlysales2(monthlySales);
    monthlysales3(monthlySales);
}
