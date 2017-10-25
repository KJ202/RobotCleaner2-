  #include <time.h>

#include "../include/dp.hpp"
#include "../include/world.hpp"
#include "../include/qlearning.hpp"
#include "../include/qlearningLinearApprox.hpp"
#include "../include/montecarlo.hpp"
#include "../include/montecarloLinearApprox.hpp"


  int main(){
  srand (time(NULL));
  cleaner::world w(2,2,3);//width/height/cbattery
  std::cout << w << std::endl;

  /*cleaner::dp dp_solver(w, 0.001, 0.99);
  dp_solver.solve();
  std::cout << "dp_solver("<< *w.getState(0) << ") = " << dp_solver.getValueAt(0) << std::endl;*/

  cleaner::montecarloLinearApprox mc_solver(w, 0.1, 0.99, 100);
  mc_solver.solve();
  std::cout << "mc_solver("<< *w.getState(0) << ") = " << mc_solver.getValueAt(0) << std::endl;
/*
  cleaner::qlearning q_solver(w, 0.1, 0.1, 0.99, 1000);
  q_solver.solve();
  std::cout << "q_solver("<< *w.getState(0) << ") = " << q_solver.getValueAt(0) << std::endl;*/
  
/*  cleaner::qlearningLinearApprox qla_solver(w, 0.1, 0.1, 0.99, 1000);
  qla_solver.solve();
  std::cout << "qla_solver("<< *w.getState(0) << ") = " << qla_solver.getValueAt(0) << std::endl;*/

  return 0;
}
