#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#define STATS_FILE "stats.txt"

static const int sec_per_min = 60;

void increment_stats() {
    FILE *f = fopen(STATS_FILE, "r+");
    if (!f) {
        f = fopen(STATS_FILE, "w");
        if (!f) return;
        fprintf(f, "%d\n", 1);
        fclose(f);
        return;
    }

    int count = 0;
    if (fscanf(f, "%d", &count) != 1) {
        count = 0;
    }
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d\n", count + 1);
    fclose(f);
}

void show_stats() {
    FILE *f = fopen(STATS_FILE, "r");
    if (!f) {
        printf("Ещё нет завершённых рабочих интервалов.\n");
        return;
    }
    int count = 0;
    if (fscanf(f, "%d", &count) != 1) {
        count = 0;
    }
    fclose(f);
    printf("Завершено рабочих интервалов: %d\n", count);
}

void show_help(const char *progname) {
    printf("Использование:\n");
    printf("  %s -w <work_minutes> -r <rest_minutes>\n", progname);
    printf("  По умолчанию: 25 минут работы и 5 минут отдыха\n\n");
    printf("Дополнительно:\n");
    printf("  %s stats    - показать статистику\n", progname);
    printf("  %s --help   - показать эту справку\n\n", progname);
    printf("Пример:\n");
    printf("  %s -w 50 -r 10\n", progname);
}

void countdown(int minutes, const char *interval_name) {
    int total_seconds = minutes * sec_per_min;
    for (int i = total_seconds; i > 0; i--) {
        printf("\r Осталось %s: %d секунд    ", interval_name, i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n%s завершён!\a\n", (strcmp(interval_name, "работать") == 0) ? "Рабочий интервал" : "Отдых");
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "stats") == 0) {
        show_stats();
        return 0;
    }

    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        show_help(argv[0]);
        return 0;
    }

    int opt;
    int work_minutes = 25;
    int rest_minutes = 5;

    while ((opt = getopt(argc, argv, "w:r:")) != -1) {
        switch (opt) {
            case 'w':
                work_minutes = atoi(optarg);
                break;
            case 'r':
                rest_minutes = atoi(optarg);
                break;
            default:
                show_help(argv[0]);
                return 1;
        }
    }

    printf("Рабочий интервал: %d минут\n", work_minutes);
    printf("Отдыхательный интервал: %d минут\n", rest_minutes);

    countdown(work_minutes, "работать");
    increment_stats();
    countdown(rest_minutes, "отдыхать");
}
