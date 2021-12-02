#include<stdio.h>
#include"my_mat.h"
#define INFINITE 9999999
#define V 10




int mat[V][V];

//the function that gets values from the user 
void userinput(){
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            scanf("%d",&mat[i][j]);
            if (mat[i][j]==0&&i!=j){
                mat[i][j]=INFINITE;
            }
            else if (i==j)
                mat[i][j]=0;
        }
    }
}
//A function that returns the shortest path between two vertices (i and j)
//The function uses Floyd warshall Algorithm 
int Shortest_route (int i , int j)
{
    if (i==j){
        return -1;
    }
    
    int output[V][V];
  
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            output[i][j] = mat[i][j];
  
   
    for (int d = 0; d < V; d++)
    {
        
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                
                if (output[i][d] + output[d][j] < output[i][j])
                    output[i][j] = output[i][d] + output[d][j];
            }
        }
    }
    if (output[i][j]!=0 && output[i][j]!=INFINITE){
        return output[i][j];
    }
    return -1;

}

//A function that returns if there is a path between two vertices (1=True,0=False)
int isconnected(int i,int j){
    if (Shortest_route(i,j)!=-1){
        return 1;
}
    return 0;
}