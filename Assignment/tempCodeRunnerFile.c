char operation(char a, char b, char operator)
{
	char res;
	if(operator == '^')
		res = (a-48) ^ (b-48); //ASCII value of string numeric starts from 48
	else if(operator == '/')
		res = (a-48) / (b-48);
	else if(operator == '*')
		res = (a-48) * (b-48);
	else if(operator == '%')
		res = (a-48) % (b-48);
	else if(operator == '+')
		res = (a-48) + (b-48);
	else if(operator == '-')
		res = (a-48) - (b-48);
 	return (res+48); 
}