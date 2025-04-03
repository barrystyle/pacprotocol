#include <memdebug.h>

void process_mem_usage(double& vm_usage, double& resident_set) {

   unsigned long vsize;
   long rss;

   std::string pid, comm, state, ppid, pgrp, session, tty_nr;
   std::string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   std::string utime, stime, cutime, cstime, priority, nice;
   std::string O, itrealvalue, starttime;

   vm_usage     = 0.0;
   resident_set = 0.0;

   std::ifstream stat_stream("/proc/self/stat",std::ios_base::in);

   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss;

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}

void print_usage(char* id) {

   double vm, rss;
   process_mem_usage(vm, rss);

   LogPrintf("(%s) memusage vm: %.0fkb, rss: %.0fkb\n", id, vm, rss);
}
