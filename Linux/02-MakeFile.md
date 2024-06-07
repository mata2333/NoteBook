a.c:

```c
#include <stdio.h>

// 声明外部函数
void func_b();

int main() {
    func_b();
    return 0;
}

```

b.c:

```c
#include <stdio.h>

void func_b() {
    printf("fdasdfs B\n");
}

```



# Version1

```makefile
# Version1
test: a.c b.c
	gcc -o test a.c b.c
```

# Version2

```makefile
# Version2
CXX = gcc
TARGET = hello
OBJ = a.o b.o
CXXFLAGS = -Wall -c

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

a.o: a.c
	gcc $(CXXFLAGS) -o a.o a.c
b.o: b.c
	gcc $(CXXFLAGS) -o b.o b.c
clean:
	rm -rf $(OBJ) $(TARGET)
```

# Version3

```makefile
# Version3
CXX = gcc
TARGET = hello
OBJ = a.o b.o
CXXFLAGS = -Wall -c

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c
	gcc $(CXXFLAGS) -o $@ $<
clean:
	rm -rf $(OBJ) $(TARGET)
```

