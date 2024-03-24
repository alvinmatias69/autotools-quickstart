#include "config.h"

#ifdef HAVE_VSLOGGER
#include <libvslogger.h>
#else
#include <stdio.h>
#endif

int main(void) {
#ifdef HAVE_VSLOGGER
  struct vslogger_config config = {
      .level = VSLOGGER_INFO,
      .destination = stdout,
      .enable_date = true,
      .enable_prefix = true,
  };

  vslogger_init(&config);
  vslogger_info("hello info");
  vslogger_clear();
#else
  printf("hello standard\n");
#endif

  return 0;
}
