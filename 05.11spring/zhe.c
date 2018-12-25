#include <stdio.h>  
#include <stdlib.h>  
#include <memory.h>  
#include <pthread.h>  
#include <errno.h>  
#include <math.h> 
#include <unistd.h> 
pthread_mutex_t mutex[6] ;  
void *eat(void *arg);
int main(){  
    pthread_t A,B,C,D,E; //5个哲学家  
  
    int i;  
    for (i = 0; i < 5; i++)  
        pthread_mutex_init(&mutex[i],NULL);  
    pthread_create(&A,NULL, eat, "A");  
    pthread_create(&B,NULL, eat, "B");  
    pthread_create(&C,NULL, eat, "C");  
    pthread_create(&D,NULL, eat, "D");  
    pthread_create(&E,NULL, eat, "E");  
    sleep(1);

    return 0;  
}  

void *eat(void *arg)  
{  
    char name = *(char *)arg;  
    int l,r; //左右筷子的编号  
    l=name-'A';
    r=(l+1)%5;
    while(1){
        usleep(2); //思考
        pthread_mutex_lock(&mutex[l]); //拿起左手的筷子
        printf("%c拿起第%d个筷子\n", name, l);
        if (pthread_mutex_trylock(&mutex[r])!=0){ //拿起右手的筷子
            pthread_mutex_unlock(&mutex[l]); //如果右边筷子被拿走放下左手的筷子
	    printf("%c放下第%d个筷子\n", name, l);
            continue;
        }
        printf("%c拿起第%d个筷子\n", name, r);
        printf("%c开始吃饭\n",name);
        usleep(3); //吃饭
	printf("%c吃完了\n",name);
        pthread_mutex_unlock(&mutex[l]); //放下左手的筷子
        printf("%c放下第%d个筷子\n", name, l);
        pthread_mutex_unlock(&mutex[r]); //放下左手的筷子
        printf("%c放下第%d个筷子\n",name, r);
    }
}  