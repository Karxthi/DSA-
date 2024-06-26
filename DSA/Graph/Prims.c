#include <stdio.h>    
#include <limits.h>    
#define vertices 5  //macros  
int minkey(int k[], int mst[])    
{  
    int minimum  = INT_MAX, min,i;    
      
     
    for (i = 0; i < vertices; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    // finding mininmum
    return min;    
}    

void prim(int g[vertices][vertices])    
{    
   
    int parent[vertices];   //parent node arr 
    
    int k[vertices];       
    int mst[vertices];      
    int i, count,edge,v; 
    {  
        k[i] = INT_MAX;  //initializing
        mst[i] = 0;    
    }  
    k[0] = 0;
    parent[0] = -1;   
    for (count = 0; count < vertices-1; count++)    
    {    
        
        edge = minkey(k, mst);    
        mst[edge] = 1;    
        for (v = 0; v < vertices; v++)    
        {  
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])//similar to djkistra    
            {  
                parent[v]  = edge, k[v] = g[edge][v];    // changing new source
            }  
        }  
     }    
     //Printing the mst edge and wegith/  
     printf("\n Edge \t  Weight\n");  
     for (i = 1; i < vertices; i++)    
     printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
      
}    
int main()    
{    
    int g[vertices][vertices] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };   
    prim(g);    
    return 0;  
}  