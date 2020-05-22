#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
Process::Process(const int pid) : pid_(pid){};
//  Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() { return cpu_utilization_; }

void Process::SetCpuUtilization(long active_ticks, long system_ticks) {
  long duration_active{active_ticks - cached_active_ticks_};
  long duration{system_ticks - cached_system_ticks_};
  cpu_utilization_ = static_cast<float>(duration_active) / duration;
  cached_active_ticks_ = active_ticks;
  cached_system_ticks_ = system_ticks;
}

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

//  Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

//  Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

//  Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

//  Overload the "less than" comparison operator for Process objects
bool Process::operator>(Process const& a) const {
  return (cpu_utilization_ > a.cpu_utilization_);
}