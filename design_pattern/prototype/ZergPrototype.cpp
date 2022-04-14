#include <iostream>
#include <memory>

namespace zerg {
class Unit{
public:
  virtual ~Unit() {}
  virtual Unit* clone() = 0;
  virtual void print() = 0;
};

class Zergling : public Unit
{
public:
  Zergling(int hp, int atk, int spd ) : hp_(hp), atk_(atk), spd_(spd) {}

  virtual Unit *clone() {
    return new Zergling(hp_, atk_, spd_);
  }

  void print()
  {
    std::cout << "Property :\tZergling" << std::endl;
    std::cout << "HP :\t" << hp_ << std::endl;
    std::cout << "ATK :\t" << atk_ << std::endl;
    std::cout << "SPd :\t" << spd_ << std::endl;
  }

private:
  int hp_;
  int atk_;
  int spd_;
};

class Hydralisk : public Unit
{
public:
  Hydralisk(int hp, int atk, int spd ) : hp_(hp), atk_(atk), spd_(spd) {}

  virtual Unit *clone() {
    return new Hydralisk(hp_, atk_, spd_);
  }

  void print()
  {
    std::cout << "Property :\tHydralisk" << std::endl;
    std::cout << "HP :\t" << hp_ << std::endl;
    std::cout << "ATK :\t" << atk_ << std::endl;
    std::cout << "SPd :\t" << spd_ << std::endl;
  }

private:
  int hp_;
  int atk_;
  int spd_;
};

class Mutalisk : public Unit
{
public:
  Mutalisk(int hp, int atk, int spd ) : hp_(hp), atk_(atk), spd_(spd) {}

  virtual Unit *clone() {
    return new Mutalisk(hp_, atk_, spd_);
  }

  void print()
  {
    std::cout << "Property :\tMutalisk" << std::endl;
    std::cout << "HP :\t" << hp_ << std::endl;
    std::cout << "ATK :\t" << atk_ << std::endl;
    std::cout << "SPd :\t" << spd_ << std::endl;
  }

private:
  int hp_;
  int atk_;
  int spd_;
};

class ProductionBuilding {
public:
  ProductionBuilding(Unit *prototype) : prototype_ptr(prototype) {}
  Unit* spawn() {
    return prototype_ptr->clone();
  }
private:
  Unit *prototype_ptr;
};
} // namespace zerg

int main(int argc, char * argv[])
{
  zerg::Zergling* zergling1 = new zerg::Zergling(35, 40, 2);
  zerg::ProductionBuilding* spawning_pool = new zerg::ProductionBuilding(zergling1);

  zerg::Hydralisk* hydralisk1 = new zerg::Hydralisk(75, 20, 1);
  zerg::ProductionBuilding* hydralisk_den = new zerg::ProductionBuilding(hydralisk1);

  auto zergling2 = spawning_pool->spawn();
  zergling1->print();
  zergling2->print();

  auto hydralisk2 = hydralisk_den->spawn();
  hydralisk1->print();
  hydralisk2->print();
}


