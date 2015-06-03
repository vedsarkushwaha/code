#include <stdio.h>
#include <pthread.h>

void *fun(void * arg){
  int i;
  for(i=1; i<1000; i++){
    if(i%10==0)
    printf("tt\n");
  }
  //return (void *)10;
}

void *fun2(void * arg){
  int i;
  for(i=0; i<1000; i++)
  if(i%10==0)
    printf("jj\n");
  //return (void *)11;
}

int main(){
  pthread_t t1, t2;
  //void *ii,*jj;
  pthread_create(&t1, NULL, &fun, NULL);
  pthread_create(&t2, NULL, &fun2, NULL);
  
  pthread_join(	t1, NULL);
  pthread_join(	t2, NULL);
    //printf("\nii = %d\n jj = %d", (int) ii, (int) jj);
  //printf("\nMain ends\n");  
return 0;
}
