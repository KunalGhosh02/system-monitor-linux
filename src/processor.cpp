#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  long ActiveJiffies = LinuxParser::ActiveJiffies();
  long IdleJiffies = LinuxParser::IdleJiffies();

  long TotalTime = ActiveJiffies + IdleJiffies;

  return static_cast<float>(ActiveJiffies) / static_cast<float>(TotalTime);
}