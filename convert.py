content = ""
with open("main.c", "r") as f:
    content = f.read()
output = ""
for c in content:
    if c == "\n":
        output += "\\\\n\\\n"
    elif c == '"':
        output += '\\"'
    else:
        output += c
with open("out.txt", "w") as f:
    f.write(output)
