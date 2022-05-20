#include "request.h"

void Request::process() {
  outFnc("Starting processsing request " + std::to_string(value) + "...");
}

void Request::finish() {
  outFnc("Finished request" + std::to_string(value));`
}
