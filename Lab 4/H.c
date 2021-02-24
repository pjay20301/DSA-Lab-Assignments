#include <stdio.h>


int max_count[7] = {0};

int _atoi(char c) { return c - 'A'; }

int main() {
    int n, max_distinct;
    scanf("%d", &n);

    char str[100005];
    scanf("%s%*c", str);

    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = _atoi(str[i]);

    for (int i = 0; i < n; i++) {
        if (!max_count[arr[i]]) {
            max_distinct++;
            max_count[arr[i]] = 1;
        }
    }

    int start = 0, start_index = -1, min_len = n;
    int count[7] = {0};
    int distinct_found = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;

        if (count[arr[i]] == 1) {
            distinct_found++;
        }

        if (distinct_found == max_distinct) {
            while (count[arr[start]] > 1) {
                count[arr[start]]--;

                start++;
            }

            int window_size = i - start + 1;

            if (min_len > window_size) {
                min_len = window_size;
                start_index = start;
            }
        }
    }

    printf("%d", min_len);

    return 0;
}