#include <iostream>
#include <gflags/gflags.h>


namespace gflag_test {


DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english, french, german", "comma-separated list of languages to offer in the 'lang' menu");

// Sanity-checking Flag Values
bool ValidatePort(const char* flagname, int value) {
  if (value > 0 && value < 32768) { // value is ok
    std::cout << "Valid value for " << flagname << " with value : " << (int)value << std::endl;
    return true;
  }
  std::cout << "Invalid value for " << flagname << " with value : " << (int)value << std::endl;
  return false;
}

DEFINE_int32(port, 0, "what prot to listen on");
DEFINE_validator(port, &ValidatePort);
}

using namespace gflag_test;

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << "\t[flag list] " << std::endl;
  std::cout << std::endl;
  std::cout << "\t big_menu: \t" << FLAGS_big_menu << std::endl;
  std::cout << "\t port: \t\t" << FLAGS_port << std::endl;
  std::cout << "\t languages: \t" << FLAGS_languages << std::endl;
  return 0;
}


