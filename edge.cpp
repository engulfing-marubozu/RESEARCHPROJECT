#include<iostream>
#include<fstream>
using namespace std;

class triangle
{  public:
    int a;
    int b;
    int c;                             // CLASS TO STORE TRIANGLE DATA FROM FILE
    int d;
} triangle[1000];

class edge
{
    public:
    int e;                            // CLASS TO STORE THE EDGES 
    int f;
} edge[100];

int main()

  
{   ifstream fin;
    ofstream fout;
   int c=0,z=0,maxedge=0,index=1,g=0,k=0;
    fin.open("Sphere1500.msh");
    fout.open("Sphere1500edgess.txt");
    while(!fin.eof())
    {   
        fin>>triangle[c].a;
        fin>>triangle[c].b;
        if(triangle[c].b>maxedge)
         maxedge=triangle[c].b;
        fin>>triangle[c].c;
        if(triangle[c].c>maxedge)
         maxedge=triangle[c].c;                          // READING DATA FROM FILE
        fin>>triangle[c].d;
        if(triangle[c].d>maxedge)
         maxedge=triangle[c].d;
        g++;
        c++;
        } 
for(int l=1; l<=maxedge; l++)
{        k=0;
       for(int i=0; i<g-1; i++)
       { 
         if(triangle[i].b==l||triangle[i].c==l||triangle[i].d==l){
    
          
        if((triangle[i].b==l||triangle[i].c==l))
         { edge[z].e=triangle[i].b;
        edge[z++].f=triangle[i].c;
        k++;
        
         }

        if((triangle[i].c==l||triangle[i].d==l))                  // EXTRACTNG PAIR OF EDGES FROM TRIANGLE
        {edge[z].e=triangle[i].c;
        edge[z++].f=triangle[i].d;
        k++;
        
        }
        
        if((triangle[i].d==l||triangle[i].b==l))
        {edge[z].e=triangle[i].d;
        edge[z++].f=triangle[i].b;
        k++;
        
        }

        

        
        
        } } int globalmax=1000,m;
        for(int i=0;i<k/2;i++)
        {   int localmax=0;
            for(int j=0;j<k;j++)
            {
                if(edge[j].e+ edge[j].f < globalmax && edge[j].e+ edge[j].f>localmax)
                 {                                                                                 // FILTERING OUT THE REPEATED EDGES
                     m=j;
                    localmax=edge[j].e+ edge[j].f; 
                }
            
            } z=0; 
               globalmax=edge[m].e+ edge[m].f;
               if(edge[m].e>=l && edge[m].f>=l)
               {cout<<index<<"-        "<<edge[m].e<<"   "<<edge[m].f<<"\n";
                fout<<index++<<"-        "<<edge[m].e<<"   "<<edge[m].f<<"\n";
               }
        }
        
}      
    cout<<"COMPLETED \nTotal number of edges = "<<index-1<<"\n"<<"THANK YOU";
    fout<<"COMPLETED \nTotal number of edges = "<<index-1<<"\n"<<"THANK YOU";           //WRITING OUTPUT THE FILR AND TERMINAL
    fin.close();
    fout.close();

    return 0;
}