#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(const int pid);
  void SetCpuUtilization(long active_ticks, long system_ticks);
  int Pid();
  std::string User();
  std::string Command();
  float CpuUtilization();
  std::string Ram();
  long int UpTime();
  bool operator>(Process const& a) const;

 private:
  int pid_;
  float cpu_utilization_;
  long cached_active_ticks_;
  long cached_idle_ticks_;
  long cached_system_ticks_;
};

#endif