struct config {
  char  root[255];		/* name of root file system */
  short heap;			/* size of heap */
  char  keymap;			/* use builtin map? */
  char  ram;			/* use ram disk? */
  char  porta;			/* user serial port a? */
  char  portb;			/* user serial port b? */
  char  mapopt;			/* remap option key to control? */
  char  mapcmdopt;		/* remap cmd-opt-[0-6] to extended keys? */
  char  maptoescape;		/* remap a key to escape? */
};
