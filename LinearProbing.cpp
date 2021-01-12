#include <iostream>

#define SIZE 8
#define MOD SIZE
#define N INT32_MIN

void add(int);
int contains(int);
void fillTable();
void printTable();
void reSize();
void reHash();

int table[SIZE];
int count;

int main()
{
    int item, c, loc;
    //testing
    int keyTable[] = {2,4,84,12,20,28};
    int n = sizeof(keyTable)/sizeof(int);

    printf("\nKey Table: \n");
    for (int i=0; i<n; i++) printf(" %d", keyTable[i]);

    printf("\n\nF = x(MOD%d)\n", MOD);
    
    fillTable();
    printf("\nHash Table:\n");
    for (int i=0; i<n; i++){
        if (keyTable[i]>=0) add(keyTable[i]); 
        printTable(); 
    } 

    printf("\nEnter the element you want to search: ");
    scanf("%d", &item);
    if(item>=0){
        loc=contains((item));
    }
    if (loc!=-1) printf("\nElement '%d' Found at location '%d'\n",item,loc);
}

void add(int hashCode)
{
    int probe=hashCode%MOD; 

    while(table[probe]!=N)
    {
        probe=(probe+1)%MOD;
    }
    table[probe]=hashCode;
    count++;
}

int contains(int x)
{
    if(count==0){
        printf("ERROR: Table is EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int probe=x%SIZE;

    while(table[probe]!=N)
    {
        if(table[probe]==x)
            return probe;
        else 
            probe=(probe+1)%SIZE;
    }
    printf("\nElement '%d' not found.\n", x);
    return -1;
}

void fillTable(){
    for (int i=0; i<SIZE; i++)
    table[i] = N;
}

void printTable()
{
    int i;
    for(i=0;i<SIZE;i++){
        if(table[i]==N)
            printf(" N ");
        else
            printf(" %d ", table[i]);   
    }
    printf("\n");
}

void reSize()
{
    //NOT implemented
}
void reHash()
{
    //NOT implemented
}