#include <messageloop.hpp>

namespace messageloop {

Messageloop::Messageloop() {
    number = 6;
}

int Messageloop::get_number() const {
  return number;
}

}
