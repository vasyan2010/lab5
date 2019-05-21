
#include  <stdio.h>
#include  <windows.h>
#include  <conio.h>
#include  <stdlib.h>
#include  <ctype.h>
#include  <string.h>
#include  <iostream>
using namespace std;
const int NONE=1000*10000; 
const int maxSizeNodeName=30;
const int startMatrixSize=20;
const int stepChangeMatrixSize=2;

char S = 'S';
char T = 'T';

class GR{   
	private:
		struct node
		{
			node *next; 
			char name[maxSizeNodeName];		
			unsigned int nameSize;
		};
		
		node* nodeHead;			
		int * matrixH;			
		int * matrixE;
		int ** matrixC;				
		int ** matrixF;				
		unsigned int nodeListSize;
		unsigned int matrixSize;	
	public:		
		GR()		
		{ 
			nodeHead=NULL;	
			matrixC = new int*[startMatrixSize]; 
    		for (unsigned int i = 0; i < startMatrixSize; i++) 
    		{
    			matrixC[i] = new int[startMatrixSize];
    			for(unsigned int j = 0; j < startMatrixSize; j++)
       					matrixC[i][j]=0;
			}
			matrixF=NULL;
			matrixH=NULL;
			matrixE=NULL;
       		nodeListSize=0;
       		matrixSize=startMatrixSize;
		};
		~GR(){};
			
		bool parser(char * str) 
		{
			bool errorInput= false;
			cout<<str;
			unsigned int nowPoint=0;
			
			
			int searchResult1;
			unsigned int node1NameSize;
			char node1Name[maxSizeNodeName]; 			
			for (node1NameSize=0;(str[node1NameSize+nowPoint]!=' ')&&(!errorInput);node1NameSize++)			
				if ((str[node1NameSize+nowPoint]=='\n')||(str[node1NameSize+nowPoint]=='\0'))
					errorInput=true;
			if (!errorInput)
			{
				memcpy(node1Name, str+nowPoint, node1NameSize); 
				node1Name[node1NameSize]='\0';
				searchResult1=search(node1Name,node1NameSize);
				if (searchResult1==NONE) 
				{
					addNewnode(node1Name, node1NameSize);
					searchResult1=nodeListSize-1;
				}	
				nowPoint+=node1NameSize+1; 
				
			
				int searchResult2;
				unsigned int node2NameSize;
				char node2Name[maxSizeNodeName]; 			
				for (node2NameSize=0;(str[node2NameSize+nowPoint]!=' ')&&(!errorInput);node2NameSize++){};
					if ((str[node2NameSize+nowPoint]=='\n')||(str[node2NameSize+nowPoint]=='\0'))
						errorInput=true;
				if (!errorInput)
				{
					memcpy(node2Name, str+nowPoint, node2NameSize); 
					node2Name[node2NameSize]='\0';
					searchResult2=search(node2Name,node2NameSize);
					if (searchResult2==NONE)
					{
						addNewnode(node2Name, node2NameSize);
						searchResult2=nodeListSize-1;
					}		
					nowPoint+=node2NameSize+1; 
					
					
					unsigned int costSize;
					char cost[12]; 
					for (costSize=0;(str[costSize+nowPoint]!='\0')&&(str[costSize+nowPoint]!='\n');costSize++)
						if (str[costSize+nowPoint]==' ')
							errorInput=true;
					if (!errorInput)
					{	
						memcpy(cost, str+nowPoint, costSize);
						cost[costSize]='\0';
						matrixC[searchResult1][searchResult2]=atoi(cost);
						if (atoi(cost)<=0) 
							errorInput=true;
						
						if ((node1NameSize==0)||(node2NameSize==0))
							errorInput=true;
					}
				}	
			}		
			return errorInput;
		}
		void printNodes()
		{
			cout<<"List of node:\n";
			node * tmp = nodeHead;
			
			for(unsigned int nodeNum=nodeListSize;tmp!=NULL;nodeNum--)
			{
				cout<<nodeNum;
				cout<<") "<<tmp->name<<endl;
				tmp=tmp->next;
			}
		}
		void printMatrix()
		{
			if (matrixC!=NULL)
			{
				cout<<"Matrix C:\n";
				for (unsigned int i = 0; i < nodeListSize; i++) 
				{
					for(unsigned int j = 0; j < nodeListSize; j++)
						printf("%3d",matrixC[i][j]);
					cout<<endl;
				}
    				
			}
			else
				cout<<"matrixC = NULL\n";
				
			if (matrixF!=NULL)
			{
				cout<<"Matrix F:\n";
				for (unsigned int i = 0; i < nodeListSize; i++) 
				{
					for(unsigned int j = 0; j < nodeListSize; j++)
						printf("%3d",matrixF[i][j]);
					cout<<endl;
				}
			}
			else
				cout<<"matrixF = NULL\n";
				
			if (matrixH!=NULL)
			{
				cout<<"Matrix H:\n";
				for (unsigned int i = 0; i < nodeListSize; i++) 
					printf("%3d",matrixH[i]);	
				cout<<endl;
			}
			else
				cout<<"matrixH = NULL\n";	
				
			if (matrixE!=NULL)
			{
				cout<<"Matrix E:\n";
				for (unsigned int i = 0; i < nodeListSize; i++) 
					printf("%3d",matrixE[i]);	
				cout<<endl;
			}
			else
				cout<<"matrixE = NULL\n";
		cout<<endl;		
		}
		int search(char * nodeName, unsigned int nameSize) 
		{
			node * search=nodeHead;
			bool found=false;
			int numInList=nodeListSize;
			while ((search!=NULL)&&(!found))
			{	
				numInList--;
				if (nameSize==search->nameSize)
				{
					found=true;
					for (unsigned int i=0;(i<nameSize)&&(found);i++)	
						if(nodeName[i]!=search->name[i])
							found=false;	
				}				
				search=search->next;
			}			
			return ((!found)?NONE:numInList); 
		}
		void changeMatrix()
		{
			unsigned int source;
			int tmp;
			
		
			for (unsigned int i = nodeListSize; i < matrixSize; i++) 
	    			delete [] matrixC[i];
			matrixSize=nodeListSize;
	
			
			source=search(&S,1);
			if (source!=0) 	
			{
			
				node * nodeS=nodeHead;
				for (unsigned int i = 0; i < nodeListSize-source-1; i++) 		
	    			nodeS=nodeS->next;	
	    		cout<<nodeS->name<<endl;
	    		
	    		node * tmp=nodeHead; 
	    		if (tmp!=nodeS)
	    			while (tmp->next!=nodeS)
	    				tmp=tmp->next;
	    		tmp->next=nodeS->next;	
	    		nodeS->next=NULL;
	    		while (tmp->next!=NULL) 
	    			tmp=tmp->next; 
	    		tmp->next=nodeS;
	    		
	    		
	    		
				int **newMatrixC =  new int*[nodeListSize]; 	
	    		for (unsigned int i = 0; i < nodeListSize; i++) 	    	
	    			newMatrixC[i] = new int[nodeListSize];			    
			  
			    for (unsigned int i = 0; i < nodeListSize; i++) 
	    			for(unsigned int j = 0; j < nodeListSize; j++)
	    			{
	    				if ((i==source)&&(j==source))	
	    					newMatrixC[0][0]=matrixC[i][j];
	    				if ((i==source)&&(j!=source))
	    				{
	    					if (j<source)
	    						newMatrixC[0][j+1]=matrixC[i][j];
	    					else
	    						newMatrixC[0][j]=matrixC[i][j];
						}
						if ((i!=source)&&(j==source))
	    				{
	    					if (i<source)
	    						newMatrixC[i+1][0]=matrixC[i][j];
	    					else
	    						newMatrixC[i][0]=matrixC[i][j];
						}
						if ((i<source)&&(j<source))
							newMatrixC[i+1][j+1]=matrixC[i][j];
						if ((i<source)&&(j>source))
							newMatrixC[i+1][j]=matrixC[i][j];
						if ((i>source)&&(j<source))
							newMatrixC[i][j+1]=matrixC[i][j];
						if ((i>source)&&(j>source))
							newMatrixC[i][j]=matrixC[i][j];
					}			
	    		for (unsigned int i = 0; i < nodeListSize; i++) 
	    			delete [] matrixC[i];
			    delete[] matrixC;
			    matrixC=newMatrixC;
			}
			source=search(&T,1);
			if (source!=nodeListSize-1) 
			{
				int **newMatrixC =  new int*[nodeListSize]; 	
	    		for (unsigned int i = 0; i < nodeListSize; i++) 	    	
	    			newMatrixC[i] = new int[nodeListSize];			    
			
			    for (unsigned int i = 0; i < nodeListSize; i++)  
	    			for(unsigned int j = 0; j < nodeListSize; j++)
	    			{
	    		
	    				if ((i==source)&&(j==source))	
	    					newMatrixC[nodeListSize-1][nodeListSize-1]=matrixC[i][j];
	    				if ((i==source)&&(j!=source))
	    				{
	    					if (j<source)
	    						newMatrixC[nodeListSize-1][j]=matrixC[i][j];
	    					else
	    						newMatrixC[nodeListSize-1][j-1]=matrixC[i][j];
						}
						if ((i!=source)&&(j==source))
	    				{
	    					if (i<source)
	    						newMatrixC[i][nodeListSize-1]=matrixC[i][j];
	    					else
	    						newMatrixC[i-1][nodeListSize-1]=matrixC[i][j];
						}
						if ((i<source)&&(j<source))
							newMatrixC[i][j]=matrixC[i][j];
						if ((i<source)&&(j>source))
							newMatrixC[i][j-1]=matrixC[i][j];
						if ((i>source)&&(j<source))
							newMatrixC[i-1][j]=matrixC[i][j];
						if ((i>source)&&(j>source))
							newMatrixC[i-1][j-1]=matrixC[i][j];
					}			
	    		for (unsigned int i = 0; i < nodeListSize; i++) 
	    			delete [] matrixC[i];
			    delete[] matrixC;
			    matrixC=newMatrixC;
			}
		}
		void addNewnode(char * nodeName, unsigned int nodeNameSize)
		{
			node * newNode=new node;
			newNode->next = nodeHead;
			newNode->nameSize=nodeNameSize;
			nodeHead=newNode;
			memcpy(newNode->name, nodeName, nodeNameSize+1);
			nodeListSize++; 
			if (nodeListSize>matrixSize) 
			{
				unsigned int newMatrixSize=matrixSize+stepChangeMatrixSize;
				int **newMatrix =  new int*[newMatrixSize]; 
	    		for (unsigned int i = 0; i < newMatrixSize; i++) 	    	
	    			newMatrix[i] = new int[newMatrixSize];			    
			   
			    for (unsigned int i = 0; i < newMatrixSize; i++)  
	    			for(unsigned int j = 0; j < newMatrixSize; j++)
	    				if ((i>=matrixSize)||(j>=matrixSize))
	    					newMatrix[i][j]=0;			
	    				else
	    					newMatrix[i][j]=matrixC[i][j];
	    					
	    		for (unsigned int i = 0; i < matrixSize; i++) 
	    			delete [] matrixC[i];
			    delete[] matrixC;
			    matrixSize=newMatrixSize;
			    matrixC=newMatrix;
			}
		}
		
		void madeMatrices()
		{			
			matrixF = new int*[nodeListSize]; 
    		for (unsigned int i = 0; i < nodeListSize; i++) 
    		{
    			matrixF[i] = new int[nodeListSize];
    			for(unsigned int j = 0; j < nodeListSize; j++)
       					matrixF[i][j]=0;
			}	
		
			for (unsigned int i=1; i<nodeListSize; i++)
			{
				matrixF[0][i] = matrixC[0][i];
				matrixF[i][0] = -matrixC[0][i];
			}
			
			matrixH = new int[nodeListSize]; 
			matrixH[0] = nodeListSize;
			for (unsigned int i=1; i<nodeListSize; i++)
				matrixH[i] =0 ;
				
			matrixE = new int[nodeListSize]; 
			matrixE[0]=0;
			for (unsigned int i=1; i<nodeListSize; i++)
				matrixE[i] = matrixF[0][i];
		}
		
		int MaxWay()
		{
			bool done=false;
			unsigned int i;
			unsigned int j;
			while (!done)
			{
				
				for (i=1; i<nodeListSize-1; i++)
					if (matrixE[i] > 0)
						break;
				if (i == nodeListSize-1)
					done=true;
		
				for (j=0; j<nodeListSize; j++)
					if (matrixC[i][j]-matrixF[i][j] > 0 && matrixH[i]==matrixH[j]+1)
						break;
				if (j < nodeListSize)
					push (i, j);
				else
					lift (i);
			}
			int flow = 0;
			for (int i=0; i<nodeListSize; i++)
				if (matrixC[0][i]!=0)
					flow += matrixF[0][i];
			
		
			cout <<"Maximum Flow: "<< max(flow,0);
			return max(flow,0);	
		}
		
		void push (int u, int v)
		{
			int d = min (matrixE[u], matrixC[u][v] - matrixF[u][v]);
			matrixF[u][v] += d;
			matrixF[v][u] = - matrixF[u][v];
			matrixE[u] -= d;
			matrixE[v] += d;
		}
		
		void lift (int u)
		{
			int d = NONE;
			for (int i = 0; i < nodeListSize; i++)
				if (matrixC[u][i]-matrixF[u][i] > 0)
					d = min (d, matrixH[i]);
			if (d == NONE)
				return;
			matrixH[u] = d + 1;
		}
		
		bool checkST()
		{
			if ((search(&S,1)==NONE)||(search(&T,1)==NONE))
				return false;
			else
				return true;
		}
};

int main()
{
	SetConsoleOutputCP(1251);
	const unsigned int strMaxSize=128; 
	char str[strMaxSize];
	GR sewerage; 
	
	FILE *input=fopen("database.txt","r");
    if (input==NULL)
    {
        printf("database.txt not found\n");
        return 1;
    }
    bool endReading=false;
    bool errorReading=false;
    char *estr;	
    while ((!endReading)&&(!errorReading))
    {
    	estr=fgets(str,strMaxSize,input);
        if (estr==NULL)
        {
            if (feof(input)!=0)
                printf("\nReading done.\n\n");
            else
                printf("\nError reading. :( \n\n");
            endReading=true;
        }
        else
        {
        	errorReading=sewerage.parser(str);
        }
	}
	
    if (!errorReading)
    {
    	if (sewerage.checkST())
    	{
    		sewerage.printNodes();
		    sewerage.printMatrix();
		    sewerage.changeMatrix(); 
		  	
		  	sewerage.madeMatrices();
		  	sewerage.printMatrix();
		  	sewerage.MaxWay();
		}
	    else
			cout<<"S or T not found\n";	
	}
    else
     	cout<<"Error input\n";
     
	return 0;
}
