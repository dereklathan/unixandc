//author: derek lathan
//file: dereklathan.c
//assignment: lab 2 - matrix algebra package
#include <stdio.h>
#include <stdlib.h>

void press_enter()
{
	char c;
	printf("\nPRESS ENTER TO CONTINUE\n");
	getchar();
	while(1)
	{	
		c=getchar();
		if(c=='\n')
			break;
	}
}

void vector_inner_product()
{
	int a,b;

	int **v=(int **) malloc(2*sizeof(int *));
	for (a=0;a<2;a++)
		v[a]=(int *) malloc(3*sizeof(int));

	printf("enter i, j, and k scalars respectively for first vector.\n");
	for(a=0;a<3;a++)
		scanf("%d",&v[0][a]);
	printf("now for the second.\n");
	for(a=0;a<3;a++)
		scanf("%d",&v[1][a]);
	b=(v[0][0]*v[1][0])+(v[0][1]*v[1][1])+(v[0][2]*v[1][2]);
	printf("\nvector inner product of:\n\n");
	for(a=0;a<3;a++)
	{
		printf("(%d)%c ",v[0][a],a+105);
	if(a!=2)
		printf("+ ");
	}
	printf("\n\nand:\n\n");
	for(a=0;a<2;a++)
		printf("(%d)%c + ",v[1][a],a+105);
	printf("(%d)k",v[1][2]);
	printf("\n\nis: %d\n",b);
	free(v);
	press_enter();
}

void product_matrix_matrix()
{
	int n,m,i,j,k,o;

	printf("how many columns for first matrix?\n");
	scanf("%d",&n);
	printf("how many rows for first matrix?\n");
	scanf("%d",&m);
	int **m1=(int **) malloc(m*sizeof(int *));
	for (j = 0; j < m; j++)
		m1[j]=(int *) malloc(n*sizeof(int));
	for(i=0;i<m;i++)
	{	
		printf("enter values for row %d\n",i+1);
		for(j=0;j<n;j++)
			scanf("%d",&m1[i][j]);
	}
	printf("how many columns for second?\n");
	scanf("%d",&o);
	printf("rows must equal %d.\n",n);
	int **m2=(int **) malloc(n*sizeof(int *));
	for (j=0;j<n;j++)
		m2[j]=(int *) malloc(o*sizeof(int));
	for(i=0;i<n;i++)
	{	
		printf("enter values for row %d\n",i+1);
		for(j=0;j<o;j++)
			scanf("%d",&m2[i][j]);
	}

	int **m3=(int**) malloc(m*sizeof(int *));
	for(j=0;j<m;j++)
		m3[j]=(int *) malloc(o*sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<o;j++)
			m3[i][j]=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<o;j++)
		{
			for(k=0;k<n;k++)
				m3[i][j]=m3[i][j]+(m1[i][k]*m2[k][j]);
		}
	}
	printf("\nthe product of:\n\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d ",m1[i][j]);
		printf("\n");
	}
	printf("\nand:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<o;j++)
			printf("%5d ",m2[i][j]);
		printf("\n");
	}
	printf("\nis:\n\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<o;j++)
			printf("%5d ",m3[i][j]);
		printf("\n");
	}
	free(m3);
	free(m1);
	free(m2);
	press_enter();
}


void vector_addition()
{
	int c;
	int **v=(int **) malloc(3*sizeof(int *));
	for (c = 0; c < 3; c++){
		v[c]=(int *) malloc(3*sizeof(int));
	}
	printf("enter i, j, and k scalars respectively for first vector.\n");
	for(c=0;c<3;c++)
		scanf("%d", &v[0][c]);
	printf("now for the second.\n");
	for(c=0;c<3;c++)
		scanf("%d",&v[1][c]);
	for(c=0;c<3;c++)
		v[2][c]=v[0][c]+v[1][c];
	printf("\nthe sum of:\n\n");
	printf("(%d)i + (%d)j + (%d)k\n\n",v[0][0],v[0][1],v[0][2]);
	printf("and:\n\n(%d)i + (%d)j + (%d)k\n\n",v[1][0],v[1][1],v[1][2]);
	printf("is:\n\n(%d)i + (%d)j + (%d)k\n\n",v[2][0],v[2][1],v[2][2]);
	free(v);
	press_enter();
}

void vector_product()
{
	int c;
	int **v=(int **) malloc(3*sizeof(int *));
	for (c = 0; c < 3; c++){
		v[c]=(int *) malloc(3*sizeof(int));
	}
	printf("enter i, j, and k scalars respectively for first vector.\n");
	for(c=0;c<3;c++)
		scanf("%d", &v[0][c]);
	printf("now for the second.\n");
	for(c=0;c<3;c++)
		scanf("%d",&v[1][c]);
	v[2][0]=(v[0][1]*v[1][2])-(v[0][2]*v[1][1]);
	v[2][1]=(v[0][2]*v[1][0])-(v[0][0]*v[1][2]);
	v[2][2]=(v[0][0]*v[1][1])-(v[0][1]*v[1][0]);
	printf("\nthe product of:\n\n");
	for(c=0;c<3;c++)
	{
		printf("(%d)%c ",v[0][c],c+105);
		if(c!=2)
			printf("+ ");
	}
	printf("\n\nand:\n\n");
	for(c=0;c<3;c++)
	{
		printf("(%d)%c ",v[1][c],c+105);
		if(c!=2)
			printf("+ ");
	}

	printf("is:\n\n");
	for(c=0;c<3;c++)
	{
		printf("(%d)%c ",v[2][c],c+105);
		if(c!=2)
			printf("+ ");
	}
	free(v);
	press_enter();

}

void product_matrix_vector()
{
	int a, b, c;
	printf("how many rows for the matrix?(columns must be 3)\n");
	scanf("%d",&a);
	int **m=(int **) malloc(a*sizeof(int *));
	for(b=0;b<a;b++)
		m[b]=(int *) malloc(3*sizeof(int));
	int *v=(int *) malloc(3*sizeof(int));
	for(b=0;b<a;b++)
	{
		printf("enter values for row %d.\n",b+1);
		for(c=0;c<3;c++)
			scanf("%d",&m[b][c]);
	}
	printf("enter i, j, and k scalars respectively for the vector.\n");
	for(b=0;b<3;b++)
		scanf("%d",&v[b]);
	int *m1=(int *) malloc(a*sizeof(int));
	for(b=0;b<3;b++)
		m1[b]=0;
	for(b=0;b<a;b++)
	{
		for(c=0;c<3;c++)
			m1[b]=m1[b]+(m[b][c]*v[c]);
	}
	printf("the product of:\n\n");
	for(b=0;b<a;b++)
	{
		for(c=0;c<3;c++)
			printf("%5d ",m[b][c]);
		printf("\n");
	}
	printf("\n\nand:\n\n");
	for(b=0;b<3;b++)
	{
		printf("(%d)%c ",v[b],b+105);
		if(b!=2)
			printf("+ ");
	}
	printf("\nis:\n\n");
	for(b=0;b<a;b++)
		printf("%5d\n",m1[b]);
	free(m1);
	free(m);
	free(v);
	press_enter();
}

void transpose_matrix()
{
	int a, b, c, d;
	printf("how many columns for the matrix?\n");
	scanf("%d",&a);
	printf("how man rows?\n");
	scanf("%d",&b);
	int **m1=(int **) malloc(b*sizeof(int *));
	for(c=0;c<b;c++)
		m1[c]=(int *) malloc(a*sizeof(int));
	int **m2=(int **) malloc(a*sizeof(int *));
	for(c=0;c<a;c++)
		m2[c]=(int *) malloc(b*sizeof(int));
	for(c=0;c<b;c++)
	{
		printf("enter values for row %d.\n",c+1);
		for(d=0;d<a;d++)
			scanf("%d",&m1[c][d]);
	}	
	for(c=0;c<a;c++)
	{
		for(d=0;d<b;d++)
			m2[c][d]=m1[d][c];
	}
	printf("\nTranspose of:\n\n");
	for(c=0;c<b;c++)
	{
		for(d=0;d<a;d++)
			printf("%5d ",m1[c][d]);
		printf("\n");
	}
	printf("\nis:\n\n");	

	for(c=0;c<a;c++)
	{
		for(d=0;d<b;d++)
			printf("%5d ",m2[c][d]);
		printf("\n");
	}
	free(m1);
	free(m2);
	press_enter();
}

int main()
{
	char c;
	while(1){
	printf("\tMATRIX ALGEBRA PACKAGE\n\na) VECTOR ADDITION\nb) VECTOR PRODUCT\nc) VECTOR INNER PRODUCT\nd) PRODUCT MATRIX VECTOR\ne) PRODUCT MATRIX MATRIX\nf) TRANSPOSE MATRIX\ng) EXIT\n\nEnter the index for the task you want to perform:\n");

	c=getchar();
	if(c=='a')
		vector_addition();
	else if(c=='b')
		vector_product();
	else if(c=='c')
		vector_inner_product();
	else if(c=='d')
		product_matrix_vector();
	else if(c=='e')
		product_matrix_matrix();
	else if(c=='f')
		transpose_matrix();
	else if(c=='g')
		return 0;
	else
		printf("%c is not an option. please enter valid index\n",c);
	}
}
