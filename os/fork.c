#include <stdio.h>
#include <unistd.h>
int main()
{
int k;
k=fork();
fork() && fork() || fork();
fork();
//fork()&&fork();
//printf("%d\n",k);
printf("forked\n");
return 0;
}
