int	    is_power_of_2(unsigned int n)
{
    long int num = n ;
    if( n % 2 != 0)
        return (0);

    while( num % 2 == 0 && num > 2)
    {
        num = num / 2;
        if(num % 2 != 0)
            return 0;
    } 
    return 1;
}
