#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>

int main(int argc, char *argv[])
{
  google::InitGoogleLogging(argv[0]);

  google::ParseCommandLineFlags (&argc, &argv, true);

  LOG(INFO) << "INFO 레벨의 로그";
  LOG(WARNING) << "WARNING 레벨의 로그";

  LOG(ERROR) << "ERROR 레벨의 로그";

  // FATAL의 경우, Stack trace를 출력하고 프로그램을 종료시킨다.
  LOG(FATAL) << "FATAL 레벨의 로그";

}
