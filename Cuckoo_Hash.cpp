#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#define TABLES 2
#define SIZE 8
#define MOD SIZE
#define N INT32_MIN

void add(int,int);
int contains(int);
void fillTables();
void printHashTables();
void reSize();
void reHash();

int cuckooTable[TABLES][SIZE];
int count;

int main()
{
    //testing
    int keyTable[] = {2,4,84,12,20,28};
    int n = sizeof(keyTable)/sizeof(int);

    printf("\nKey Table: \n");
    for (int i=0; i<n; i++) printf(" %d", keyTable[i]);

    printf("\n\nF2 = x(MOD%d)\n", MOD);
    printf("F2 = (x/%d)%(MOD%d)\n", MOD);
   
    fillTables();
    printf("\nHash Tables:\n");
    for (int i=0; i<n; i++){
        if (keyTable[i]>=0) add(keyTable[i], 0); //adding keys
        printHashTables();
    }
}

void add(int hashCode, int table)
{
    int tempHash;
    int probe;
    switch(table)
    {
        case 0:
            probe=hashCode%MOD;
        break;

        case 1:
            probe=(hashCode/MOD)%MOD;
        break;  
    }
    tempHash = cuckooTable[table][probe];  
    cuckooTable[table][probe] = hashCode;
    if(tempHash != N) 
        add(tempHash, (table+1)%TABLES); 
    count++;
}

int contains(int x)
{
    int probe1=x%MOD;
    int probe2=(x/MOD)%MOD;
    if(count==0){
        printf("ERROR: Table is EMPTY\n");
        exit(EXIT_FAILURE);
    }
    if (cuckooTable[0][probe1] == x){ 
        return probe1;
    }
    if (cuckooTable[1][probe2] == x){ 
        printf("\nTable1");
        return probe2;
    }
    return -1;
}

void fillTables()
{
    for (int j=0; j<MOD; j++)
        for (int i=0; i<TABLES; i++)
            cuckooTable[i][j] = N;
}

void printHashTables()
{
    for (int i=0; i<TABLES; i++)
    {
        int k=i+1;
        
        for (int j=0; j<MOD; j++)
        {
            if(cuckooTable[i][j]==N)
                printf(" N ");
            else
                printf(" %d ",cuckooTable[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void reSize(){
    //NOT implemented
}
void reHash(){
    //NOT implemented
}