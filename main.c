#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *s = "#include <stdio.h>\n\
#include <string.h>\n\
\n\
int main(int argc, char **argv) {\n\
    char *s = \"@\";\n\
    for (int i = 0; i < strlen(s); i++) {\n\
        if (s[i] == 64) {\n\
            printf(\"%s\", s);\n\
        } else if (s[i] == 92) {\n\
            printf(\"%c\", 92);\n\
        } else {\n\
            printf(\"%c\", s[i]);\n\
        }\n\
    }\n\
    return 0;\n\
}\n\
";
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 64) {
            printf("%s", s);
        } else if (s[i] == 92) {
            printf("%c", 92);
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}
