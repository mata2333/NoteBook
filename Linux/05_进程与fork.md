```cpp
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<cstdio>
#include<cstdlib>
#include<cerrno>

int main()
{

    pid_t pid;/*pid 进程id号*/

    pid=fork();/*创建一个新进程*/

    if(pid==0) /*返回0为子进程*/
    {
        printf("Return pid is %d\n",pid);
        printf("This is son process!  pid is:%d\n",getpid());

    }
    else if(pid>0)/*返回大于0为父进程*/
    {
        printf("Return pid is %d\n",pid);
        printf("This is parent process!  pid is:%d\n",getpid());
        waitpid(pid,nullptr,0);/*等待子进程退出*/
    }
    else
    {
        perror("fork() error!");
        exit;
    }
}
```

代码含义如下所示

![未命名文件](D:\WSL\NoteBook\Linux\assets\未命名文件.png)

需要注意：子进程会从父进程中继承执行状态，包括寄存器中的值、栈的状态以及程序计数器的值等。这意味着子进程将从创建它的父进程的当前指令处继续执行。