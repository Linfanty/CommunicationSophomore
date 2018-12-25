#include<windows.h>
#include<iostream>
#include<cstdio>

const unsigned short SIZE_OF_BUFFER=10; //the length of buffer
unsigned short buffer[SIZE_OF_BUFFER]={0}; //create space for buffer
unsigned short in=0;                   //the mark of position entering the space
unsigned short out=0;                  //the mark of position leaving the space
unsigned short Product_ID=0;           //the ID of product,from 1 to 10,not for count
unsigned short Consume_ID=0;           //the ID of consume product_ID in the buffer
unsigned int produce_sum=0;            //the total produce number
unsigned int consume_sum=0;            //the total consume number
HANDLE mutex;                          //the mutex between threads
HANDLE Full_Semaphore;                 //the resource semaphore: buffer is full
HANDLE Empty_Semaphore;                //the resource semaphore: buffer is empty
const unsigned short p_count=20;        //the number of produce one time
const unsigned short c_count=6;        //the number of consumer one time
const unsigned short s_count=p_count+c_count;  //the sum number of threads
HANDLE threads[s_count];               //the handle of every thread
DWORD Producer_ID[p_count];            //the mark of producer thread
DWORD Consumer_ID[c_count];            //the mark of consumer thread
unsigned short control=1;              //control the program run or stop


DWORD WINAPI producer(LPVOID);         //the producer thread
DWORD WINAPI consumer(LPVOID);         //the consumer thread
void produce();                                           
void consume();
void Create_P_Threads();               //create producer thread
void Create_C_Threads();               //create consumer thread
void Product_Sum();                    //print the total of remain product number and print the buffer
void info();                           //info


void Product_Sum()
{
 int i,sum=0;
 for(i=0;i<SIZE_OF_BUFFER;i++)
 {
  if(buffer[i]!=0)
   sum++;
 }
 std::cout<<"  "<<sum<<"         ";
 for(i=0;i<SIZE_OF_BUFFER;i++)
 {
  std::cout<<buffer[i]<<" ";
 }
 printf("\n");
}


void produce()
{
 int i;
 std::cout<<"produce";
 if(Product_ID>=10)
  Product_ID=0;
 Product_ID++;
 produce_sum++;
 buffer[in]=Product_ID;
 printf(" buffer[%d]=%d    ",in,Product_ID);
 in=(in+1)%SIZE_OF_BUFFER;
    Product_Sum();
}

void consume()
{
 int i;
 std::cout<<"consume";
 consume_sum++;
 Consume_ID=buffer[out];
 printf(" buffer[%d]=%d    ",out,Consume_ID);
 buffer[out]=0;
 out=(out+1)%SIZE_OF_BUFFER;
 Product_Sum();
}

DWORD WINAPI producer(LPVOID)                               //producer thread
{
 while(control)
 {
  WaitForSingleObject(Full_Semaphore,INFINITE);       //resource semaphore P operation
        WaitForSingleObject(mutex,INFINITE);                //the mutex P operation
  produce();
  Sleep(100);
  ReleaseMutex(mutex);                                //resource semaphore P operation
  ReleaseSemaphore(Empty_Semaphore,1,NULL);            //the mutex P operation
 }
 return 0;
}

DWORD WINAPI consumer(LPVOID)                              //consumer thread
{
 while(control)
 {
  WaitForSingleObject(Empty_Semaphore,INFINITE);
  WaitForSingleObject(mutex,INFINITE);
  consume();
  Sleep(100);
  ReleaseMutex(mutex);
  ReleaseSemaphore(Full_Semaphore,1,NULL);
 }
 return 0;
}

void Create_P_Threads()                                  //create producer thread
{
 for(int i=0;i<p_count;i++)
 {
  threads[i]=CreateThread(NULL,0,producer,NULL,0,&Producer_ID[i]);
  if(threads[i]==NULL)
   control=0;
 }
}


void Create_C_Threads()
{
 for(int i=p_count;i<s_count;i++)
 {
  threads[i]=CreateThread(NULL,0,consumer,NULL,0,&Consumer_ID[i-p_count]);
  if(threads[i]==NULL)
   control=0;
 }
}

 
/*
void info()
{
 std::cout<<"\n"<<std::endl;
 std::cout<<"**********I did refer to the program on the web."<<std::endl;
    std::cout<<"*******and I simplify some things and make it more powful!"<<std::endl;
    std::cout<<"**But it is really a word a word knocked out by me based on understanding\n"<<std::endl;
 std::cout<<"produce/consume    remain_total  buffer_state(from 0 to 9)"<<std::endl;
}
*/

int main()
{
 // info();
 mutex=CreateMutex(NULL,FALSE,NULL);
 Full_Semaphore=CreateSemaphore(NULL,SIZE_OF_BUFFER,SIZE_OF_BUFFER,NULL);
 Empty_Semaphore=CreateSemaphore(NULL,0,SIZE_OF_BUFFER,NULL);
 Create_P_Threads();
 Create_C_Threads();
 while(control)
 {
  if(getchar())
  {
   std::cout<<std::endl;
   std::cout<<"the total produce product number is "<<produce_sum<<std::endl;
   std::cout<<"the total consume product number is "<<consume_sum<<std::endl;
   control=0;
  }
 }
 return 0;
}