# C Quine

一个自复制的程序，输出自己的源代码。

## 文件说明

- `main.c` - C语言实现的Quine
- `convert.py` - 用于转义/引用源代码的实用脚本
- `AGENTS.md` - 智能编码助手的指南

## 快速开始

```bash
# 编译并运行
gcc -std=c99 -o main main.c && ./main

# 验证Quine属性
gcc -std=c99 -o main main.c && ./main > output.c && diff main.c output.c
```

## 实现细节

### main.c

Quine由两部分组成：
1. 字符串`s`，包含源代码（经过转义处理）
2. 打印逻辑，当遇到`@`（ASCII 64）时标记字符串本身需要以带引号的形式打印

### convert.py

读取`main.c`并生成用于C字符串字面量的转义版本。

## 可优化项

### 1. 更简洁的Quine实现

当前实现使用ASCII码（64='@', 92='\\', 34='"'），虽然清晰但冗长。使用printf格式字符串的更短写法：

```c
main(){char*s="main(){char*s=%c%s%c;printf(s,34,s,34);}";printf(s,34,s,34);}
```

更易读的版本：

```c
#include <stdio.h>

int main(void) {
    char *s = "#include <stdio.h>\n\nint main(void) {\n    char *s = %c%s%c;\n    printf(s, 34, s, 34);\n    return 0;\n}\n";
    printf(s, 34, s, 34);
    return 0;
}
```

### 2. 改进convert.py

当前版本只处理了`\n`和`\"`。应支持更多转义序列：

| 字符 | C字符串 | convert.py输出 |
|------|---------|----------------|
| `\` | `\\` | `\\\\` |
| `"` | `\"` | `\"` |
| `\n` | `\\n` | `\\n` |
| `%` | `%%` | `%%` |
| `?` | `\?` | `\?` |
| `'` | `\'` | `\'` |
| `\t` | `\\t` | `\\t` |
| `\r` | `\\r` | `\\r` |
| `\a` | `\\a` | `\\a` |
| `\b` | `\\b` | `\\b` |
| `\f` | `\\f` | `\\f` |
| `\v` | `\\v` | `\\v` |

### 3. convert.py增强功能

- 使用ESCAPE_MAP字典提高可读性
- 添加命令行参数支持输入/输出文件
- 添加文件操作错误处理
- 添加文档字符串和注释

## 参考资料

- [Quine（计算）- Wikipedia](https://en.wikipedia.org/wiki/Quine_%28computing%29)
- [IOCCC Quine作品](https://www.ioccc.org/)
