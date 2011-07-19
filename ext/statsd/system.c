#include <ruby.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>


static VALUE cScClockTick()
{
  /*char *clock_tick;*/
  /*snprintf(clock_tick, 1024, "%ld", sysconf(_SC_CLK_TCK));*/
  return INT2FIX(sysconf(_SC_CLK_TCK));
}

void Init_system()
{
  static VALUE mStatsd;
  static VALUE mSystem;
  mStatsd = rb_define_module("Statsd");
  mSystem = rb_define_module_under(mStatsd, "System");
  rb_define_module_function(mSystem, "sc_clock_tick", cScClockTick, 0);
}
