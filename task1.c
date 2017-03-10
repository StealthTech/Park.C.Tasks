#include <stdio.h>
#include <malloc.h>
#include <stddef.h>
#include <memory.h>

#define ERROR "[error]"

void filterMax(int* data, size_t size, size_t count);
int compare(const int*, const int*);
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int main() {
    // Ввод размера массива
    size_t n = 0;
    if (scanf("%zu", &n) != 1) {
        // Ошибка в случае неверного ввода;
        printf(ERROR);
        return 0;
    }
    if (n == 0) { return 0; }

    // Ввод элементов массива
    int* data = (int*)malloc(sizeof(int) * n);
    for (ptrdiff_t i = 0; i < n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            printf(ERROR);
            free(data);
            return 0;
        }
    }

    // Ввод количества максимумов
    size_t m = 0;
    if (scanf("%zu", &m) != 1 || m > n) {
        // Ошибка в случае неверного ввода;
        // если требуемое количество максимумов больше размера массива
        printf(ERROR);
        free(data);
        return 0;
    }
    if (n == 0) { return 0; }

    filterMax(data, n, m);

    for (ptrdiff_t i = 0; i < m; i++) {
        printf("%d ", data[i]);
    }

    free(data);
    return 0;
}

int compare(const int *i, const int *j) {
    // Функция для сравнения двух элементов массива
    return *j - *i;
}

void filterMax(int data[], size_t size, size_t count) {
    // Функция для фильтрации максимальных значений массива
    // Стандартная функция сортировки quicksort
    qsort(data, size, sizeof(int), (int(*) (const void *, const void *)) compare);

    int* output_data = (int*)malloc(sizeof(int) * count);
    for (ptrdiff_t i = 0; i < count; i++) {
        output_data[i] = data[i];
    }

    memcpy(data, output_data, count);
    free(output_data);
}