#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *s = "#include <stdio.h>\\n\
#include <string.h>\\n\
\\n\
int main(int argc, char **argv) {\\n\
    char *s = \"@\";\\n\
    int len = strlen(s);\\n\
    for (int i = 0; i < len; i++) {\\n\
        if (s[i] == 64) {\\n\
            for (int j = 0; j < len; j++) {\\n\
                if (s[j] == 92 && (j + 1 < len) && s[j + 1] == 'n') {\\n\
                    printf(\"%c%cn%c%c\", 92, 92, 92, 10);\\n\
                    j++;\\n\
                } else if (s[j] == 34) {\\n\
                    printf(\"%c%c\", 92, 34);\\n\
                } else {\\n\
                    printf(\"%c\", s[j]);\\n\
                }\\n\
            }\\n\
        } else if (s[i] == 92 && (i + 1 < len) && s[i + 1] == 'n') {\\n\
            printf(\"%c\", 10);\\n\
            i++;\\n\
        } else {\\n\
            printf(\"%c\", s[i]);\\n\
        }\\n\
    }\\n\
    return 0;\\n\
}\\n\
";
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 64) {
            for (int j = 0; j < len; j++) {
                if (s[j] == 92 && (j + 1 < len) && s[j + 1] == 'n') {
                    printf("%c%cn%c%c", 92, 92, 92, 10);
                    j++;
                } else if (s[j] == 34) {
                    printf("%c%c", 92, 34);
                } else {
                    printf("%c", s[j]);
                }
            }
        } else if (s[i] == 92 && (i + 1 < len) && s[i + 1] == 'n') {
            printf("%c", 10);
            i++;
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}
