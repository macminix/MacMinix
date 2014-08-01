#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


/* Man - find, nroff & display online manuals
 *
 * Written by Warren Toomey. Dec, 1989.
 * You may freely copy or give away this source as
 * long as this notice remains intact.
 *
 */

/* Things to do:
	if stdout != tty, don't page (I think?)
*/

#define EPAGE "PAGER"		/* Pager environment variable name */
#define EMAN  "MANPATH"		/* Man path environment variable name */

#define PAGER   "less"			/* Default pager */
#define MANPATH "/usr/man"		/* Default man directory */
#define WHATIS  "whatis"		/* Whatis file */
#define NROFF   "nroff -man"		/* Nroff for manuals */

#define WNAME	500			/* Whatis file name length */
#define WNUM	30			/* # words on a whatis line */
#define WSIZE	50			/* Size of each word */

char *getenv();

int fgetarg(stream,cbuf)		/* Get next arg from file into cbuf, */
 FILE *stream;				/* returning the character that      */
 char *cbuf;				/* terminated it. Cbuf returns NULL  */
 {					/* if no arg. EOF is returned if no  */
  int ch;				/* args left in file.                */
  int i;				/* Modified to stop on commas!	     */

  i=0; cbuf[i]=NULL;

  while (((ch=fgetc(stream))==' ') || (ch=='\t') || (ch=='\n') || (ch==','))
    if (ch=='\n') return(ch);				/* Bypass leading */
							/* whitespace     */
  if (feof(stream)) return(EOF);
  
  cbuf[i++]=ch;

  while (((ch=fgetc(stream))!=' ') && (ch!='\t') && (ch!='\n') && (ch!=','))
    cbuf[i++]=ch;					/* Get the argument */

  cbuf[i]=NULL;
  return(ch);
 }



int fsize(path,siz)		/* Return the size of a file in bytes */
 char *path;			/* or an error if cannot stat it */
 int *siz;
 {
  struct stat buf;
  int i=0;


  if (i=stat(path,&buf)) return(i);

  *siz= buf.st_size;
  return(0);
 }


cutstring(s1,ary)		/* Cut string of fields into separate */
 char *s1, *ary[];		/* fields. Separator is space, tab or : */
 {
  int i=0;

  ary[0]=s1;			/* Set first field */
  while (*s1)
   {
    if ((*s1==' ') || (*s1=='\t') || (*s1==':'))
     {
      *s1=NULL;
      ary[++i]= s1+1;
     }
   s1++;
  }
 ary[++i]=NULL;			/* Don't forget to terminate the list */
 }


char *msearch(mp,title,sect)	/* Find the section of the manual where */
 char *mp, *title;		/* the requested title is in */
 char *sect;			/* returning the new title, plus sect */
 {
  char whatis[WNAME], word[WNUM][WSIZE], ch;
  int size,i,minus;
  FILE *zin;

  sprintf(whatis,"%s/%s",mp,WHATIS);		/* find `whatis' */

  if (fsize(whatis,&size)!=0) return(NULL);	/* Use size to search */

  if ((zin=fopen(whatis,"r"))==NULL) return(NULL);

  ch='a';
  while (ch!=EOF)				/* search for title */
   {
    i=0; minus=0; ch=1;
    while ((ch!=EOF) && (ch!='\n'))		/* get a line */
      {
       ch=fgetarg(zin,word[i]);
       if (!strcmp(word[i],"-")) minus=i;	/* looking for "-" */
       i++;
      }

    if (minus!=0) 
     {
     ch=word[--minus][1];			/* Get section number */

      for (i= --minus;i>=0;i--)			/* Now check title */
       if ((!strcmp(word[i],title)) && ((*sect=='0') || (*sect==ch)))
	{ *sect=ch;
	  fclose(zin);
          return(word[0]);
        }
     }
   }
  *sect='0';
  fclose(zin);
  return(NULL);
 }



usage()
 {
  fprintf(stderr,"Usage: man [section] title\n");
  exit(0);
 }



main(argc,argv,envp)
 int argc;
 char *argv[], *envp[];
 {
  int i,size;
  char *pager, *manpath, *temp, sect, usersect;
  char *mandir[100];
  char cmd[200],title[50];

  if ((argc<2) || (argc>3)) usage();

  usersect='0';
  if (argc==3)
    { usersect=argv[1][0];			/* Get any section */
      if ((usersect<'1') || (usersect>'8'))
	usage();
    }

  pager=getenv(EPAGE);			/* Set up pager path */
  if (pager==NULL) pager= PAGER;

  manpath=getenv(EMAN);			/* Set up manual path */
  if (manpath==NULL) manpath= MANPATH;

  cutstring(manpath,mandir);		/* Split man path */

  for (i=0;mandir[i]!=NULL;i++)		/* For every manual directory */
   {						/* find an entry */
    sect=usersect;
    temp=msearch(mandir[i],argv[argc-1],&sect);
    if (temp!=NULL) strcpy(title,temp);

    if (sect!='0')				/* If a manual */
      {
	sprintf(cmd,"%s/cat%c/%s.%c",		/* Check cat entry */
		mandir[i],sect,title,sect);

	if (fsize(cmd,&size))			/* If none, nroff */
          {					/* a new one */
	   fprintf(stderr,"Reformatting page. Please wait...\n");
	   sprintf(cmd,"%s %s/man%c/%s.%c | %s",NROFF, mandir[i],
		sect,title,sect,pager);

	   system(cmd);
	   exit(0);
	  }
        else					/* just page the cat file */
          {
	   sprintf(cmd,"%s %s/cat%c/%s.%c",pager, mandir[i],
		sect,title,sect);

	   system(cmd);
	   exit(0);
	  }
      }
   }
  printf("No manual on %s\n",argv[argc-1]);
  exit(1);
 }
