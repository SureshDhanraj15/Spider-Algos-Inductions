#include<stdio.h>

int firstmatch(int *alter, int n)
{
	int k,l,m,largest,current;
	char c;	
	
	printf("Enter list of querries: ");
	while(1)
	{
		scanf("%d",&current);
		scanf("%c",&c);		
		
		largest=0;		
		for(l=0;l<n;l++)
		{
			if(alter[l]>alter[largest])
			largest=l;			
		}
		
		// precaution against any querry greater than available curtain sizes
		
		if(current>alter[largest])
		{
			printf("Curtain size %d requested greater than available sizes\n",current);
			continue;			
		}
		
		// first element in stack which is greater than current curtain size is cut out
		
		for(k=n-1;k>=0;k--)
		{
			if(alter[k]>=current)
			{
				alter[k]-=current;
				
				// element from stack removed if it has become null
				
				if(alter[k]==0)
				{					
					for(m=k;m<n-1;m++)
					{
						alter[m]=alter[m+1];
					}
					n--;
				}
				break;
			}
		}
		
		/* infer that entering list of querries finished on detecting enter key press
		instead of asking number of querries beforehand to break out of loop */
		
		if (c == '\n')
		break;
	}
	
	printf("Altered stack of curtain sizes: ");
	for(k=0;k<n;k++)
	printf("%d ",alter[k]);	
	
	// update size of altered array for subsequent querries
	return n;
}

int bestmatch(int *alter, int n)
{
	int k,l,m,largest,current,best;
	char c;
	
	printf("Enter list of querries: ");
	while(1)
	{
		scanf("%d",&current);
		scanf("%c",&c); 
		
		largest=0;
		for(l=0;l<n;l++)
		{
			if(alter[l]>alter[largest])
			largest=l;			
		}
		if(current>alter[largest])
		{
			printf("Curtain size %d requested greater than available sizes\n",current);
			continue;			
		}
		
		/*position in stack holding element closest to current querry
		and also greater than it is found by repeatedly updating the 'best' variable */
		 
		best=largest;
		for(k=n-1;k>=0;k--)
		{			
			if(((alter[k]-current)<(alter[best]-current))&&(alter[k]>=current))
			best=k;			
		}
		
		alter[best]-=current;
		if(alter[best]==0)
				{					
					for(m=best;m<n-1;m++)
					{
						alter[m]=alter[m+1];
					}
					n--;
				}
				
				if (c == '\n')
		break;
	}
	
	printf("Altered stack of curtain sizes: ");
	for(k=0;k<n;k++)
	printf("%d ",alter[k]);	
	
	return n;
}

int worstmatch(int *alter, int n)
{
	int k,l,m,largest,current;
	char c;
	
	printf("Enter list of querries: ");
	while(1)
	{
		scanf("%d",&current);
		scanf("%c",&c);
		
		largest=0;
		for(l=0;l<n;l++)
		{
			if(alter[l]>alter[largest])
			largest=l;			
		}
		
		// largest available size used to satisfy current querry
		
		if(current>alter[largest])
		{
			printf("Curtain size %d requested greater than available sizes\n",current);
			continue;			
		}		
	
		alter[largest]-=current;
		if(alter[largest]==0)
				{					
					for(m=largest;m<n-1;m++)
					{
						alter[m]=alter[m+1];
					}
					n--;
				}
				
				if (c == '\n')
		break;
	}
	
	printf("Altered stack of curtain sizes: ");
	for(k=0;k<n;k++)
	printf("%d ",alter[k]);
	
	return n;		
}

main()
{
	int n,i,type;
	
	printf("Enter number of curtain sizes available: ");
	scanf("%d",&n);
	
	int stack[n];
	
	printf("Enter curtain sizes in the order present (bottom to top): ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&stack[i]);
	}
	
	// guide for querry type no and corresponding algorithm to run program
	 
	printf("\nQuerry Types: \nType 1: firstmatch \nType2: bestmatch \nType3: worstmatch");
	
	/* repeatedly let user enter as many querries as they wish 
	on the altered stack from previous querries */
	
	while(1)
	{
		printf("\n\nEnter Type no for querry: ");
		scanf("%d",&type);
		if(type==1)
		{
			n = firstmatch(stack,n);			
		}
		else if(type==2)
		{
			n = bestmatch(stack,n);			
		}
		else if(type==3)
		{
			n = worstmatch(stack,n);			
		}
		else
		{
			printf("Invalid querry type");
		}
	}
}
