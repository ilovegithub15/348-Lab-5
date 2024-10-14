#include <stdio.h>
//prints the first required output
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
//prints the second required output
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
    printf("\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[maxIndex]);
    printf("Average sales: $%.2f\n", averageSales);
    printf("\n");
}
//prints the third required output
void monthlysales3(double sales[12]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Six-Month Moving Average Report:\n");
    printf("\n");
    for (int i = 0; i <= 6; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }
        printf("%-15s - %-15s $%-14.2f\n", months[i], months[i + 5], sum / 6.0);
    }
}
//prints the fourth required output
void monthlysales4(double sales[12]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (sales[indices[j]] < sales[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-15s $%-14.2f\n", months[indices[i]], sales[indices[i]]);
    }
}
int main() {
    //reads the input.txt file and adds each line to monthlySales
    double monthlySales[12];
    FILE *file = fopen("input.txt", "r");
    for (int i = 0; i < 12; i++) {
        fscanf(file, "%lf", &monthlySales[i]);
    }
    //runs all 4 functions
    monthlysales1(monthlySales);
    monthlysales2(monthlySales);
    monthlysales3(monthlySales);
    monthlysales4(monthlySales);
    return 0;
}
