#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<ctype.h>

//begin struct 
struct employee
{
	char empl[5000];
	char firstname[5000];
	char lastname[5000];
	char gender[5000];
	char dayofbirt[5000];
	char department[5000];
	char country[5000];
} ps[2000];

struct progress
{
	int employee;
	int id;
	float progress;
} ps2[2000];


// ham chinh cau bai vaf doc 
void readfileprogress(struct progress ps2[] , int l);
void readfileofemployee( struct employee ps[] , int *y);
void readstringinfile( struct employee ps[] , char lineinfile[] , int k);
void infile_error();
int countnvinfile();
int checkstring(char v[] , char c[] );
//Ham giai
int count(struct employee ps[] , char v[] , int y);//yeu cau 1
void countmale(struct employee ps[] , int y);//yeu cau 2
void countfemale(struct employee ps[] , int y);//yeu cau 2
void writeemployee(struct progress ps2[] , float x  , int l);//yeu cau 3
void sortdesc(struct employee ps[] , int y);// yeu cau 4
void sortasc(struct employee ps[] , int y);//yeu cau 4
void tbcprogress(struct progress ps2[] , float x , int l);//yeu cau 5
void writecountry(struct employee ps[] , char v[] , int y) ;// yeu cau 6
// ham bo tro
void writeinfile(struct employee ps[] , int y);
int  checkdaugach(char c[]);
void xoadaugach(char v[]);
void chuyenhoachuoi(char v[]);
void fixcountry(struct employee ps[] , int y);
void enter(int y , int l );
void ghepchuoi(char d  , char e[]);
int checkpttrung(int k , float x );

//end ham

// ham kiem tra va in
void inprogress(struct progress ps2[], int l);
void inemployee( struct employee ps[] , int y);

// end 
int main()
{
    //read file :
	int y  , l;
	readfileofemployee(ps,&y);
	l = countnvinfile()-1;
	readfileprogress(ps2 , l);
	// end read file
	fixcountry(ps,y);
    //begin command
	//inemployee(ps ,y);
	//inprogress(ps2 ,l);
    enter(y ,l);
	return 0;
}

// ham chuc nang

void enter(int y , int l)
{
	float x;
	int h;
	char d;
    char e[20] , v[20];

	scanf("%c" , &d);
	if( d== ' ' || d == 10)
	{
		infile_error();
		return ;
	}
	else
	{
		scanf("%s" , e);
		ghepchuoi(d , e);
	}
	// end kt
	chuyenhoachuoi(e);
    if( checkstring(e , "list" )==1)
	{
		fgets(v , 100 , stdin);
        xoadaugach(v);
		chuyenhoachuoi(v);
		if( checkdaugach(v) == 1)
		{
			infile_error();
			return ;
		}
		else if( checkstring(  v , "male" )==1 )
		{
			countmale(ps,y);
			return ;
		}
		else if (checkstring(  v , "female" ) ==1 )
		{	
			countfemale(ps,y);
			return ;
			
		}
		else
		{
			infile_error();
			return ;
		}
	}
	else if(checkstring(e , "count" ) == 1)
	{
		fgets( v , 100 , stdin);
		if( v[0] == '\n' || v[0] == 10)
		{
			infile_error();
			return ;
		}
		xoadaugach(v);
		chuyenhoachuoi(v);
		if( v[0] == '\0' || v[0] == 45)
		{
			infile_error();
			return ;
		}

		if( checkdaugach(v) == 1 )
		{
			infile_error();
			return ;
		}
		else if( checkdaugach(v) == 0)
		{
			count( ps , v ,y);
			return ;
		}
		else
		{
			infile_error();
			return ;
		}
	}
	else if(checkstring( e , "country" )==1 )
	{
		fgets( v , 100 ,stdin);
		xoadaugach(v);
		chuyenhoachuoi(v);
		
		if( v[0] == '\n' || v[0] == '\0'   )
		{
			infile_error();
			return ;
		}

		if (checkdaugach(v) == 1)
		{
			infile_error();
			return ;
		}
		else
		{
			v[0] = toupper(v[0]);
			writecountry(ps , v , y);
			return ;
		}
	

	}
	else if( checkstring( e , "sort")==1 )
	{
		fgets(v , 100 ,stdin);
		xoadaugach(v);
		chuyenhoachuoi(v);
		if(checkstring(v , "asc") == 1)
		{
			sortasc(ps , y);
			writeinfile(ps , y);
			return ;
		}
		else if(checkstring( v , "desc") == 1)
		{
			sortdesc( ps , y);
            writeinfile(ps , y);
			return ;
		}
		else
		{
			infile_error();
			return ;
		}
	}
	else if(checkstring( "report" ,e ) == 1)
	{
       	fgets( v , 100 , stdin);
		xoadaugach(v);
		if(v[0] =='\n' || v[0] == '\0' )
		{
			infile_error();
			return ;
		}

		x = atof(v);
		if( checkdaugach(v) == 1)
		{
			infile_error();
			return ;
		}

		if(   v[0] < 48 || v[0] > 57 )
		{
			infile_error();
			return ;
		}
        if( x < 0 || x > 1)
        {
			infile_error();
			return ;
            
        }
		else
		{
            writeemployee(ps2 , x , l);
			return ;
        }

	}	
	else if(checkstring( e , "average" ) == 1)
	{
        fgets( v , 100 , stdin);
		if( v[0] == '\n' || v[0] == '\0')
		{
			infile_error();
			return ;
		}
		xoadaugach(v);

		if( v[0] < 48 || v[0] > 57 || v[0] == 45 )
		{
			infile_error();
			return ;
		}
		h = atoi(v);
		if ( checkdaugach( v ) == 1)
		{
			infile_error();
			return ;
		}
		else
		{
			tbcprogress(ps2 , h , l);
			return;
		}
	
	}
    else
    {
        infile_error();
    }
}

void ghepchuoi( char g , char e[])
{
	int i;
	for( i=strlen(e) ; i>=0 ; i--)
	{
		e[i+1] =  e[i];
	}
	e[0] = g;
}


void xoadaugach(char v[])
{
    int i;
    for(i= 0; v[i] != '\0' ;i++)
    {
        v[i] = v[i+1];
    }
    v[i-2] = '\0';
}

//dieu kien cau len khong hop le

int  checkdaugach(char c[])
{
	int i;
	for( i=0 ; c[i] != '\0';i++)
	{
		if( c[i] == ' ' && c[i+1] !=' ')
		{
			return 1;
		}
	}
	return 0;
}
// ghi file k hop le
void infile_error()
{
	FILE *fp;
    fp = fopen("check.txt" , "w");
	fprintf(fp , "%s" , "wrong syntax");
    fclose(fp);
}

void readfileofemployee( struct employee ps[] , int *y)
{
	FILE *file;
	char lineinfile[200];
	file = fopen("Employee.csv" , "r");
	if( file == NULL)
	{
		printf("k mo dc");
	}
	char c[100];
	fgets(c , 100 , file);
	
	int i=0;
	while( fgets( lineinfile , 200 , file) != NULL)
	{
		readstringinfile(ps ,lineinfile ,i);
		i++;
	}
	*y = i;

	fclose(file);
}

void readstringinfile( struct employee ps[] , char lineinfile[] , int k)
{
	int j ;
	int d=0;
	for(j=0; lineinfile[j]!=',';j++)
	{
		ps[k].empl[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j+1 ; lineinfile[j]!=',' ;j++ )
	{
		ps[k].firstname[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j+1 ; lineinfile[j]!=',' ;j++ )
	{
		ps[k].lastname[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j+1 ; lineinfile[j]!=',' ;j++ )
	{
		ps[k].gender[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j+1 ; lineinfile[j]!=',' ;j++ )
	{
		ps[k].dayofbirt[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j+1 ; lineinfile[j]!=',' ;j++ )
	{
		ps[k].department[d] = lineinfile[j];
		d++;
	}
	d=0;
	for( j =j +1; lineinfile[j]!='\0' ;j++ )
	{
		ps[k].country[d] = lineinfile[j];
		d++;
	}	

}

int countnvinfile()
{
	char line[200];
	FILE *file;
	file = fopen("Progress.csv" , "r");
	if( file == NULL)
	{
		printf("Khong mo dc");
	}
	int i = 0;
	while(fgets(line , 200 , file) != NULL)
	{
		i++;
	}
	fclose(file);
	return i;

}
void readfileprogress(struct progress ps2[], int l)
{
	char c[100] ;
	char lineinfile2[200];
	FILE *file;
	file =fopen("Progress.csv" , "r");
	if(file == NULL)
	{
		printf("no file ");
	}
	fgets(c , 100 , file);
	
	int i;
	char d;
	for( i=0 ; i<l ;i++)
	{
		fscanf(file ,"%d", &ps2[i].employee);
		fscanf(file , "%c" , &d);
		fscanf(file , "%d" , &ps2[i].id);
		fscanf(file , "%c" , &d);
		fscanf(file , "%f" , &ps2[i].progress);
	}
	fclose(file);
}

// yc 1 
int count(struct employee ps[] , char v[] , int y)
{
	int i;
	FILE *file;
	file = fopen("result.csv" , "w");
	int d=0;
	for (i=0;i<y;i++)
	{
		if(checkstring(ps[i].department , v)==1)
		{
			d++;
		}
	}
	
	fprintf( file , "%d" , d);
	fclose(file);
}
//end thao tac file employee

//printf list staff male , yc 2  and 3 , 4

void countmale(struct employee ps[] , int y)
{
	int i;
	char d;
	FILE *fp ;
	fp = fopen("result.csv" , "w");
	fscanf( fp , "%c" , &d);
	for(i=0;i<y;i++)
	{
		if( checkstring(ps[i].gender , "Male" )==1)
		{
			fprintf(fp , "%s," , ps[i].empl);
			fprintf(fp , "%s," , ps[i].firstname);
			fprintf(fp , "%s," , ps[i].lastname);
			fprintf(fp , "%s," , ps[i].gender);
			fprintf(fp , "%s," , ps[i].dayofbirt);
			fprintf(fp , "%s," , ps[i].department);
			fprintf(fp , "%s\n" , ps[i].country);
		}
	}
	fclose(fp);

}

void countfemale(struct employee ps[] , int y)
{
	int i,d=0;
	FILE *fp;
	fp = fopen("result.csv" , "w");
	for(i=0;i<y;i++)
	{
		if( checkstring(ps[i].gender , "Female" )==1)
		{
			fprintf(fp , "%s," , ps[i].empl);
			fprintf(fp , "%s," , ps[i].firstname);
			fprintf(fp , "%s," , ps[i].lastname);
			fprintf(fp , "%s," , ps[i].gender);
			fprintf(fp , "%s," , ps[i].dayofbirt);
			fprintf(fp , "%s," , ps[i].department);
			fprintf(fp , "%s\n" , ps[i].country);
		}
	}
	fclose(fp);
}
//end printf list staff male

// yc 5 read employss compelete progress

void writeemployee(struct progress ps2[] , float x , int l) 
{
	int i;
	FILE *fp;
	fp = fopen("result.csv" , "w");
	for(i=0;i<l;i++)
	{
		if(ps2[i].progress == x && checkpttrung(i , x)==1)
		{	
			fprintf(fp , "%d\n" , ps2[i].employee );
		}
	}
	fclose(fp);
}

int checkpttrung(int k , float x)
{
	int j;
	for(j=0;j<k;j++)
	{
		if( ps2[j].employee == ps2[k].employee && ps2[j].progress ==  x)
		{
			return 0;
		}
	}
	return 1;
}
//yc 6 : Tbc average 

void tbcprogress(struct progress ps2[] , float x , int l)
{
	int d=0;
	FILE *fp ;
	fp = fopen("result.csv" , "w");
	float sum = 0;
	float k = 0;

	int i;
	for(i=0;i<l;i++)
	{
		if(ps2[i].id == x)
		{
			sum += ps2[i].progress;
			d++;
		}
	}
	if( d == 0)
	{
		fprintf(fp ,"%d", d );
	}
	else
	{
		fprintf(fp ,"%0.3f", sum/d );
	}
	fclose(fp);
}

// yc 7 sx

void sortasc(struct employee ps[] , int y)
{
	int i, j , min;
	FILE *fp ;
	fp = fopen("result.csv" , "w");
	for(i=0;i< y;i++)
	{
		for(j=0; j < y - 1 - i ;j++)
		{
			if(strcmp( ps[j].lastname , ps[j + 1].lastname ) > 0)
			{
				struct employee ps3 = ps[j+1];
				ps[j+1] = ps[j];
				ps[j] = ps3;
			}
			else if( strcmp( ps[j].lastname , ps[j+1].lastname) == 0 )
			{
				if(strcmp( ps[j].firstname , ps[j+1].firstname) > 0)
				{
					struct employee ps3 = ps[j+1];
					ps[j+1] = ps[j];
					ps[j] = ps3;;
				}
			}
		}	
	}
	fclose(fp);

}

void sortdesc(struct employee ps[] , int y)
{
	int i, j ;
	FILE *fp ;
	fp = fopen("result.csv" , "w");
	for(i=0;i<y;i++)
	{
		for(j= 0 ; j< y -1 - i ;j++)
		{
			if(strcmp( ps[j].lastname , ps[j+1].lastname ) < 0)
			{
				struct employee ps3 = ps[j+1];
				ps[j+1] = ps[j];
				ps[j] = ps3;
			}
			else if( strcmp( ps[j].lastname , ps[j+1].lastname) == 0 )
			{
				if(strcmp( ps[j].firstname , ps[j+1].firstname) > 0)
				{
					struct employee ps3 = ps[j+1];
					ps[j+1] = ps[j];
					ps[j] = ps3;
				}
			}
		}	
	}
	fclose(fp);

}



// yc 8 read country
void writecountry(struct employee ps[] , char v[] , int y)
{
	int i;
	FILE *fp ;
	fp = fopen("result.csv" , "w");

	for(i=0;i<y;i++)
	{
		if(checkstring( v , ps[i].country ) == 1)
		{
			fprintf(fp , "%s," , ps[i].empl);
			fprintf(fp , "%s," , ps[i].firstname);
			fprintf(fp , "%s," , ps[i].lastname);
			fprintf(fp , "%s," , ps[i].gender);
			fprintf(fp , "%s," , ps[i].dayofbirt);
			fprintf(fp , "%s," , ps[i].department);
			fprintf(fp , "%s\n" , ps[i].country);
		}

	}
	fclose(fp);
	
 } 

void chuyenhoachuoi(char v[])
{
	int i;
	for( i =0 ; v[i] != '\0' ; i++)
	{
		v[i] =  tolower(v[i]);
	}
}

// end file result.csv

// check string 
int checkstring(char v[] , char c[]  )
{
	int i;
	for(i=0;v[i] !='\0';i++)
	{
		if(v[i] != c[i])
		{
			return 0;
		}
	}
	for( i = i ; i>=0;i--)
	{
		if(v[i] != c[i])
		{
			return 0;
		}
	}
	return 1;
 } 
// end check string

void writeinfile(struct employee ps[] , int y)
{
    FILE *fp;
    fp =fopen("result.csv" , "w");
    int i;
    for(i=0;i<y;i++)
    {
        fprintf(fp , "%s," , ps[i].empl);
		fprintf(fp , "%s," , ps[i].firstname);
		fprintf(fp , "%s," , ps[i].lastname);
		fprintf(fp , "%s," , ps[i].gender);
		fprintf(fp , "%s," , ps[i].dayofbirt);
		fprintf(fp , "%s," , ps[i].department);
		fprintf(fp , "%s\n" , ps[i].country);
    }
    fclose(fp);
}

// check bug
void inprogress(struct progress ps2[] , int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		printf("%d\n%d , " ,i+1 , ps2[i].employee);
		printf("%d," , ps2[i].id);
		printf("%f\n" , ps2[i].progress);
	}
}

void inemployee( struct employee ps[] , int y)
{
	int i;
	for( i = 0 ; i < y ; i++)
	{
		printf( "%s," , ps[i].empl);
		printf( "%s," , ps[i].firstname);
		printf( "%s," , ps[i].lastname);
		printf( "%s," , ps[i].gender);
		printf( "%s," , ps[i].dayofbirt);
		printf( "%s," , ps[i].department);
		printf( "%s\n" , ps[i].country);
	}

}

void fixcountry(struct employee ps[] , int y)
{
	int i , j ;
	for(i=0;i<y;i++)
	{
		j = strlen( ps[i].country ) - 1 ;
		if( ps[i].country[j] == 10 || ps[i].country[j]==13)
		{
			ps[i].country[j] = '\0';
		}
		j = strlen( ps[i].country ) - 1 ;
		if( ps[i].country[j] == 10 || ps[i].country[j]==13)
		{
			ps[i].country[j] = '\0';
		}
	}
}