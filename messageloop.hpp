#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_MESSAGELOOP
    #define MESSAGELOOP_PUBLIC __declspec(dllexport)
  #else
    #define MESSAGELOOP_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_MESSAGELOOP
      #define MESSAGELOOP_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define MESSAGELOOP_PUBLIC
  #endif
#endif

namespace messageloop {

class MESSAGELOOP_PUBLIC Messageloop {

public:
  Messageloop();
  int get_number() const;

private:

  int number;

};

}

