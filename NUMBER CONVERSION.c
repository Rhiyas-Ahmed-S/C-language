#include<stdio.h>
#define p printf
#define s scanf
#include<math.h>
#include<string.h>
void bitoall(char d[100])
{
	for(int i =0; d[i]!='\0'; i++)
	{
		if(d[i]!= '0' && d[i]!='1')
		{
			p("Entered number is not the binary number");
			return;
		}
	}
	int length = strlen(d),c = 0,tot = 0;
	for(int i=0; i<length; i++)
	{
		if(d[i] == '1')
		{
			c = pow(2,length -1-i);
			tot = tot+c;
		}
	}
	printf("decimal conversion of the given binary number :%d\n",tot);
	int hexatot=tot;
	int e = 0,oct[100],j=0;
	while(tot>0)
	{
		e = tot%8;
		tot/=8;
		oct[j++] = e;
	}
	p("octal conversion of the given binary number :");
	for(int k=j-1; k>= 0; k--)
	{
		p("%d", oct[k]);
	}
	p("\n");

	int f =0,l = 0;
	char hexa[100];
	while(hexatot>0)
	{
		f = hexatot%16;
		hexatot/=16;
		if(f<10)
		{
			hexa[l++] = f + '0';
		}
		else
		{
			hexa[l++] = f - 10 + 'A';
		}
	}
	p("Hexadecimal conversion of the given binary number :");
	for(int m = l-1; m>=0; m--)
	{
		p("%c",hexa[m]);
	}
	p("\n");
}
void octtoall(int a)
{
	int c,d,tot=0,i=0,e;

	while(a>0)
	{
		c = a%10;
		a/=10;
		d = c*pow(8,i);
		tot +=d;
		i++;
	}
	printf("Decimal conversion of the given number:%d\n",tot);
	e = tot;
	//convert to the binary using decimal number
	int f[100],k = 0,l;
	while(tot>0)
	{
		f[k++] = tot%2;
		tot/=2;
	}
	printf("Binray conversion of the given number:");
	for(l=k-1; l>=0; l--)
	{
		printf("%d",f[l]);
	}
	printf("\n");

	int g,hexa[100],m = 0,o;
	while(e>0)
	{
		g = e%16;
		e/=16;
		if(g<10)
		{
			hexa[m++] = g + '0';
		}
		else
		{
			hexa[m++] = g - 10 + 'A';
		}
	}
	printf("Hexa decimal conversion of the given number:");
	for(o=m-1; o>=0; o--)
	{
		printf("%c",hexa[o]);
	}

}
void decitoall(int a)
{
	//binary conversion
	int b[100],c,i = 0,j,oct,hexa;
	oct = a;
	hexa = a;
	while(a>0)
	{
		c = a%2;
		a/=2;
		b[i++] = c;
	}
	printf("Binray conversion of the given number:");
	for(j=i-1; j>=0; j--)
	{
		printf("%d",b[j]);
	}
	printf("\n");
	//octal conversion
	int d[100],k = 0,l,e;
	while(oct>0)
	{
		e = oct%8;
		oct/=8;
		d[k++] = e;
	}
	printf("octal conversion of the given number:");
	for(l=k-1; l>=0; l--)
	{
		printf("%d",d[l]);
	}
	printf("\n");
	//Hexadecimal conversion
	int f[100],m = 0,o,g;
	while(hexa>0)
	{
		g = hexa%16;
		hexa/=16;
		if(g<10)
		{
			f[m++] = g + '0';
		}
		else
		{
			f[m++] = g - 10+'A';
		}
	}
	printf("Hexa decimal conversion of the given number:");
	for(o=m-1; o>=0; o--)
	{
		printf("%c",f[o]);
	}
}
void Hexatoall(char b[10])
{
	//decimal conversion
	int l,c,i,tot=0,a;
	l = strlen(b);
	for(i = 0; i<l; i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			c = b[i] - '0';
		}
		else if(b[i]>='A'&&b[i]<='F')
		{
			c = b[i]-'A'+10;
		}
		else if (b[i]>='a'&&b[i]<='f')
		{
			c = b[i]-'a'+10;
		}
		else
		{
			p("entered number is not the hexadecimal number");
			return;
		}
		tot = tot*16+c;
	}
	p("Decimal value of given number:%d\n",tot);
	int oct = tot;
	//binary conversion
	int j = 0,k,d[100];
	while(tot>0)
	{
		d[j++] = tot%2;
		tot/=2;
	}
	p("Binary value of given number:");
	for(k=j-1; k>=0; k--)
	{
		p("%d",d[k]);
	}
	p("\n");
	//octal conversion
	int m = 0,n,o[100];
	while(oct>0)
	{
		o[m++]=oct%8;
		oct/=8;
	}
	p("octal value of given number:");
	for(n=m-1; n>=0; n--)
	{
		p("%d",o[n]);
	}
}
int main()
{
	int option;
	p("enter the option:\n1.Binary to all other conversion\n2.Octal to all other conversion\n3.Decimal to all other conversion\n4.Hexadecimal to all other conversion\n");
	s("%d",&option);
	switch(option)
	{
	case 1:
	{
		p("Enter the Binary number:");
		char str1[100];
		s("%s",str1);
		bitoall(str1);
		break;
	}
	case 2:
	{
		int n;
		printf("Enter the octal number:");
		scanf("%d",&n);
		octtoall(n);
		break ;
	}
	case 3:
	{
		int n;
		printf("Enter the Decimal number:");
		scanf("%d",&n);
		decitoall(n);
		break;
	}
	case 4:
	{
		char str[10];
		p("Enter the Hexa decimal number:");
		s("%s",str);
		Hexatoall(str);
		break;
	}
	}
}
