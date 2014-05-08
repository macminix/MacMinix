long 
strtol(s, p, base)
	char	*s, **p;
{
	long	r;
	int	sign, digit, hexlow, hexup, c;

	r = 0L;
	sign = 0;
	while (*s == ' ' || *s == '\t') ++s;
	if (*s == '-')
	{
		sign = 1;
		++s;
	}
	if (base == 0)
	{
		if (*s == '0') base = (s[1] == 'x' || s[1] == 'X') ? 16 : 8;
		else base = 10;
	}
	if (*s == '0' && (s[1] == 'x' || s[1] == 'X') && base == 16) s += 2;
	digit = (base <= 10) ? (base + '0' - 1) : '9';
	hexlow = 'a' + base - 10;
	hexup = 'A' + base - 10;
	for (c = *s ; ; c = *++s)
	{
		if (c >= '0' && c <= digit) c = c - '0';
		else if (c >= 'a' && c < hexlow) c = c - 'a' + 10;
		else if (c >= 'A' && c < hexup)	c = c - 'A' + 10;
		else
		{
			if (p != 0) *p = s;
			return sign ? -r : r;
		}
		r = r * base + c;
	}
}
