/* cgrind.c */

/* Author:
 *	Steve Kirkendall
 *	16820 SW Tallac Way
 *	Beaverton, OR 97006
 *	kirkenda@jove.cs.pdx.edu, or ...uunet!tektronix!psueea!jove!kirkenda
 */


/* This file contains the complete source-code for the cgrind program. */

/* Cgrind underlines C's reserved words, and emboldens function names.
 * It does this by inserting "\fB", "\fU", and "\fR" into the file.
 *	usage: cgrind [file.c]... >file
 */

#include <stdio.h>
#include <ctype.h>

/* These store the fonts that are used for various parts of the source */
char	font_reserved = 'U';
char	font_function = 'B';
char	font_comment = '\0';
char	font_string = '\0';
int	Bflag = 0;

/* This array contains all C reserved words.  The words are segregated
 * according to their first letter, to speed lookups
 */
char *reserved[26][5] =
{
	{"auto"},
	{"break"},
	{"case", "char", "continue"},
	{"default", "do", "double"},
	{"else", "enum", "extern"},
	{"far", "float", "for"},
	{"goto"},
	{(char *)0},
	{"if", "int"},
	{(char *)0},
	{(char *)0},
	{"long"},
	{(char *)0},
	{"near"},
	{(char *)0},
	{(char *)0},
	{(char *)0},
	{"register", "return"},
	{"short", "sizeof", "static", "struct", "switch"},
	{"typedef"},
	{"union", "unsigned"},
	{"void", "volatile"},
	{"while"},
	{(char *)0},
	{(char *)0},
	{(char *)0},
};

/* the program name, for diagnostics */
char	*progname;

main(argc, argv)
	int	argc;	/* number of command-line args */
	char	**argv;	/* values of the command line args */
{
	FILE	*fp;
	int	i;

	progname = argv[0];

	/* parse the flags */
	for (i = 1; i < argc && *argv[i] == '-'; i++)
	{
		switch (argv[i][1])
		{
		  case 'r':
			font_reserved = argv[i][2];
			break;

		  case 'f':
			font_function = argv[i][2];
			break;

		  case 'c':
			font_comment = argv[i][2];
			break;

		  case 's':
			font_string = argv[i][2];
			break;

		  case 'B':
			Bflag = 1;
			break;

		  default:
			fputs(progname, stderr);
			fputs(": invalid flag (valid ones are -rC -fC -cC -sC)\n", stderr);
			exit(2);
		}
	}

	if (i == argc)
	{
		/* probably shouldn't read from keyboard */
		if (isatty(fileno(stdin)))
		{
			fputs("usage: ", stderr);
			fputs(progname, stderr);
			fputs(" [-B] [-rC] [-fC] [-cC] [-sC] [filename.c]...\n", stderr);
			exit(3);
		}

		/* no files named, so use stdin */
		cgrind(stdin);
	}
	else
	{
		for (; i < argc; i++)
		{
			fp = fopen(argv[i], "r");
			if (!fp)
			{
				perror(argv[i]);
			}
			else
			{
				cgrind(fp);
				if (i < argc - 1)
				{
					putchar('\f');
				}
				fclose(fp);
			}
		}
	}
}


/* This function does the cgrind thing to a single file */
cgrind(fp)
	FILE	*fp;
{
	char	linebuf[1025];
	char	*fgets();
	char	*ptr;
	int	newfont;

	/* for each line ... */
	while (fgets(linebuf, sizeof linebuf, fp))
	{
		/* for each char of the line... */
		for (ptr = linebuf; *ptr; ptr++)
		{
			/* output a font string, if needed */
			newfont = grindchar(ptr);
			if (newfont)
			{
				putchar('\\');
				putchar('f');
				putchar(newfont);
			}

			/* output this character */
			putchar(*ptr);

			/* if going into nroff, then \ becomes \e */
			if (Bflag && *ptr == '\\')
			{
				putchar('e');
			}

#if 0
			/* if going into nroff, then insert .br between lines */
			if (Bflag && *ptr == '\n')
			{
				puts(".br\n");
			}
#endif
		}
	}
}


/* This function detects when the font should change.  It should be called
 * for each position in the line of text, including the '\n' or '\0' that
 * marks its end.  This function returns '\0' normally, or one of 'B', 'U',
 * or 'R' to change the font.
 */
grindchar(ptr)
	char	*ptr;	/* pointer to the char to process */
{
	static	font = 'R';	/* start in regular font */
	static	context = '\0';	/* not in string, not in comment */
	static	afternl = 0;	/* after a newline in funny context? */
	static	delay = 0;	/* delay the emission of font? */
	int	i, j, k;

	/* if we're in a funny context & get a '\n' or '\0', then make sure we
	 * go out of its font during the newline and then go back into it
	 */
	if ((*ptr == '\n' || *ptr == '\0') && context)
	{
		afternl = 1;
		delay = 0;
		if (font && font != 'R')
			return 'R';
		return '\0';
	}
	if (afternl && context)
	{
		afternl = 0;
		delay = 0;
		return font;
	}

	/* strings */
	if (!context && *ptr == '"')
	{
		context = '"';
		font = font_string;
		delay = 1;
		return '\0';
	}
	if (context == '"' && *ptr == '"')
	{
		context = '\0';
		font = 'R';
		delay = 0;
		return font_string ? 'R' : '\0';
	}

	/* comments */
	if (!context && *ptr == '/' && ptr[1] == '*')
	{
		context = '*';
		font = font_comment;
		delay = 0;
		return font;
	}
	if (context == '*' && *ptr == '*' && ptr[1] == '/')
	{
		context = '\0';
		font = 'R';
		if (font_comment)
			delay = 2;
		return '\0';
	}

	/* handle delayed output */
	if (delay > 0)
	{
		delay--;
		if (delay == 0)
			return font;
	}

	/* within funny contexts, don't look for reserved words or functions */
	if (context)
	{
		return '\0';
	}

	/* if this isn't alphanumeric, and font != 'R', then change to 'R' */
	if (!isalnum(*ptr) && *ptr != '_')
	{
		if (font != 'R')
		{
			font = 'R';
			return 'R';
		}
		return '\0';
	}

	/* if this *is* alphanumeric, and font != 'R', then it stays the same */
	if ((isalnum(*ptr) || *ptr == '_') && font != 'R')
	{
		return '\0';
	}

	/* if neither functions nor reserved words are used, skip! */
	if (!font_function && !font_reserved)
	{
		return '\0';
	}

	/* is this a reserved word? */
	if (islower(*ptr))
	{
		i = *ptr - 'a';
		for (j = 0; j < 5 && reserved[i][j]; j++)
		{
			k = strlen(reserved[i][j]);
			if (!strncmp(ptr, reserved[i][j], k) && !islower(ptr[k]))
			{
				if (font_reserved)
					font = font_reserved;
				return font_reserved;
			}
		}
	}

	/* is this word followed by a '(' ? */
	do
	{
		ptr++;
	} while (isalnum(*ptr) || *ptr == '_');
	while (*ptr == ' ')
	{
		ptr++;
	}
	if (*ptr == '(')
	{
		if (font_function)
			font = font_function;
		return font_function;
	}

	return '\0';
}
