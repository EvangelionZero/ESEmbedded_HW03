void reset_handler_1(void)
{
	int a=1;
	a=reset_handler_2(a);
}


int reset_handler_2(int a)
{
	a=a+1;
	a=reset_handler_3(a);
	return a;	
}

int reset_handler_3(int a)
{
	int b=6;
	b=a*b;
	return b;
}
 

