
template<class Seq, class T, class R>
void apply(Seq& sq, R(T::*f)(A1, A2) const) {
  typename Seq::iterator it = sq.begin();
  while (sq.end() != it) {
    ((*it++)->*f)();
  }
}


template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A) const, A a) {
  typename Seq::iterator it = sq.begin();
  while (sq.end() != it) {
    ((*it++)->*f)(a);
  }
}

template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2)const, A1 a1, A2 a2) {
  typename Seq::iterator it = sq.begin();
  while (sq.end() != it) {
    ((*it++)->*f)(a1, a2);
  }
}

class Gromit {
  int arf;
  int totalBarks;
public:

  Gromit(int arf = 1) : arf(arf + 1), totalBarks(0) {

  }

  void speak(int) {
    for (int i = 0; i < arf; i++) {
      std::cout << "" << endl;
      ++totalBarks;
    }
    std::cout << std::endl;
  }

  char eat(float) const {
    std::cout << "chomp!" << std::endl;
    return 'z';
  }

  int sleep(char, double) const {
    std::cout << "zzz..." << std::endl;
    return 0;
  }

  void sit() const {
    std::cout << "Sitting..." << std::endl;
  }
};
