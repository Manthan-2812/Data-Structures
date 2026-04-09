#include <stdio.h>
#include <string.h>

// Function to build LPS array
void computeLPS(char *pat, int m, int *lps) {
    int len = 0;   // length of previous longest prefix suffix
    lps[0] = 0;    // first value is always 0

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fallback
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search Function
void KMPSearch(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // continue searching
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Driver Code
int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    printf("Given Text is :\t");
    for(int i = 0;i<sizeof(txt);i++)
    {
        printf("%c",txt[i]);
    }

    printf("\nChecking pattern is :\t");
    for(int i = 0;i<sizeof(txt);i++)
    {
        printf("%c",pat[i]);
    }
    KMPSearch(txt, pat);

    return 0;
}