#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Получить день недели (0 = воскресенье ... 6 = суббота)
int get_week(int year, int month, int day) {
    struct tm time_info = { 0 };
    time_info.tm_year = year - 1900;
    time_info.tm_mon = month - 1;
    time_info.tm_mday = day;
    mktime(&time_info);
    return time_info.tm_wday;
}

// Получить количество дней в месяце
int get_month(int year, int month) {
    switch (month) {
    case 2:
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

void get_current(int* year, int* month, int* day) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    *year = st.wYear;
    *month = st.wMonth;
    *day = st.wDay;
}


int main() {
    char input[100];
    printf("Введите дату \nформат: \nгггг.мм.дд \nгггг.мм \nгггг \nnow): ");
    scanf("%99s", input);

    int year, month, day;

    if (strcmp(input, "now") == 0) {
        get_current_date(&year, &month, &day);
        int dow = get_day_of_week(year, month, day);
        char* days[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
        printf("Текущая дата: %04d.%02d.%02d - %s\n", year, month, day, days[dow]);

    }
    else if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
        int dow = get_day_of_week(year, month, day);
        char* days[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
        printf("Дата: %04d.%02d.%02d - %s\n", year, month, day, days[dow]);

    }
    else if (sscanf(input, "%d.%d", &year, &month) == 2) {
        printf("\n  Календарь за %04d.%02d\n", year, month);
        printf(" Пн Вт Ср Чт Пт Сб Вс\n");

        int start_day = get_week(year, month, 1);
        int days_in_month = get_month(year, month);

        for (int i = 0; i < (start_day == 0 ? 6 : start_day - 1); i++) {
            printf("   ");
        }

        for (int d = 1; d <= days_in_month; d++) {
            printf("%3d", d);
            if ((d + (start_day == 0 ? 6 : start_day - 1)) % 7 == 0)
                printf("\n");
        }
        printf("\n");

    }
    else if (sscanf(input, "%d", &year) == 1) {
        for (int m = 1; m <= 12; m++) {
            printf("\n  Календарь за %04d.%02d\n", year, m);
            printf(" Пн Вт Ср Чт Пт Сб Вс\n");

            int start_day = get_week(year, m, 1);
            int days_in_month = get_month(year, m);

            for (int i = 0; i < (start_day == 0 ? 6 : start_day - 1); i++) {
                printf("   ");
            }

            for (int d = 1; d <= days_in_month; d++) {
                printf("%3d", d);
                if ((d + (start_day == 0 ? 6 : start_day - 1)) % 7 == 0)
                    printf("\n");
            }
            printf("\n");
        }

    }
    else {
        printf("Неверный формат. Используй: гггг.мм.дд / гггг.мм / гггг / now\n");
    }

    return 0;
}
