#include <common.h>

extern uint64_t g_nr_guest_instr;
FILE *log_fp = NULL;

void init_log(const char *log_file) {
  log_fp = stdout;  //log输出文件指针
  if (log_file != NULL) { //如果传入的参数不为NULL
    FILE *fp = fopen(log_file, "w");  //以只写方式打开该文件
    Assert(fp, "Can not open '%s'", log_file);  //断言是否成功打开
    log_fp = fp;  //修改默认的文件指针
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_instr >= CONFIG_TRACE_START) &&
         (g_nr_guest_instr <= CONFIG_TRACE_END), false);
}
