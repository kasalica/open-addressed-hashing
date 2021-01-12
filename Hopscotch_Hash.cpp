#include <iostream>

#define SIZE 8
#define MOD SIZE
#define N INT32_MIN
#define H 3 //max distance

void add(int);
int contains(int);
void fillTable();
void printTable();
void reSize();
void reHash();

int32_t table[SIZE];
int count;

int main()
{
    int item, c, loc;
    //testing
    int keyTable[] = {2,4,84,12,20};
    int n = sizeof(keyTable)/sizeof(int);

    printf("\nKey Table: \n");
    for (int i=0; i<n; i++) printf(" %d", keyTable[i]);

    printf("\n\nF = x(MOD%d)\n", MOD);
    printf("H = %d        //max_distance\n", H);
    
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
    int tempHash;
    int probe=hashCode%MOD; 

    while(table[probe]!=N)
    {
        probe=(probe+1)%MOD;
    }

    if(probe-(hashCode%MOD) < H){
        table[probe]=hashCode;
    }
    else {
        for(int i= probe-H+1; i<probe; i++){
            if(table[i]%SIZE >= probe - H){
                //swap
                table[probe] = table[i];  //move
                table[i] = N;             //empty
                printf("swap: ");
                printTable(); 
                add(hashCode);
                break;
            } 
        }
    }
    count++;
}

int contains(int x)
{
    if(count==0){
        printf("ERROR: Table is EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int probe=x%SIZE;
    for(int i=probe; i<(probe+H); i++){
        if( table[i] == x) return i;
    
    }
   
    printf("\nElement '%d' not found.\n", x);
    return -1;
}

void fillTable(){
    for (int i=0; i<SIZE; i++)
    table[i] = N;
}

void printTable(){
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(table[i]==N)
                printf(" N ");
            else
                printf(" %d ", table[i]);   
    }
    printf("\n");
}

void reSize(){
    //NOT implemented
}
void reHash(){
    //NOT implemented
}