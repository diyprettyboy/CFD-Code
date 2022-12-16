#include <cstdio>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void FTBS(float domain[], float u[], float un[], float grid, int nt, float c, float dt, float dx)
{
    FILE *fp;
    fp = fopen("FTBS.csv","w");
    int i,j;
    for (j = 0; j < nt; j++)
    {
       for(i=0;i<grid;i++)
        {
            un[i]= u[i];
        }

        for ( i = 1; i<grid; i++)
        {
            u[i] = un[i] - c * dt / dx * (un[i] - un[i-1]);
        }
    }
    for (i=0;i<grid;i++)
    {
        fprintf(fp,"%f,%f\n",domain[i],u[i]);
    }
}

void FTCS(float domain[], float u[], float un[], float grid, int nt, float c, float dt, float dx)
{
    FILE *fp;
    fp = fopen("FTCS.csv","w");
    int i,j;
    for (j = 0; j < nt; j++)
    {
       for(i=0;i<grid;i++)
        {
            un[i]= u[i];
        }
        for ( i = 1; i<grid; i++)
        {
            u[i] = un[i] - c * dt / 2 * dx * (un[i+1] - un[i-1]);
        }
    }
    for (i=0;i<grid;i++)
    {
        fprintf(fp,"%f,%f\n",domain[i],u[i]);
    }
}

void FTFS(float domain[], float u[], float un[], float grid, int nt, float c, float dt, float dx)
{
    FILE *fp;
    fp = fopen("FTFS.csv","w");
    int i,j;
    for (j = 0; j < nt; j++)
    {
       for(i=0;i<grid;i++)
        {
            un[i]= u[i];
        }


        for ( i = 1; i<grid; i++)
        {
            u[i] = un[i] - c * dt / dx * (un[i+1] - un[i]);
        }
    }
    for (i=0;i<grid;i++)
    {
        fprintf(fp,"%f,%f\n",domain[i],u[i]);
    }
}

int main()
{
    int grid = 41,i;
    float dx,nt,dt,c;
    float domain[grid],u[grid], un[grid];
    dx = 2.0/(grid-1);
    dt = 0.025;
    c = 1.0;
    nt = 25;

    for (i=0; i < grid; i++)
    {
        domain[i] = i*dx;
    }

    fill_n(u,grid,1.0);
    fill_n(un,grid,1.0);
    for (i= int(0.5/dx) ; i <= int(1.0/dx+1.0) ; i++ )
    {
        u[i] = 2.0;
    }

    FTBS(domain,u,un,grid,nt,c,dt,dx);
    FTCS(domain,u,un,grid,nt,c,dt,dx);
    FTFS(domain,u,un,grid,nt,c,dt,dx);
}
