#include <iostream>
#include "tools.h"

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

  VectorXd rmse(4);
  rmse.fill(0.0);

  if((estimations.length() != ground_truth.length()) 
  	                  && (estimations.length() != 0))
  {
    for(int i=0; i < estimations.size(); ++i)
    {
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = pow(residual.array(), 2);
    rmse += residual;
    }
  }
  else
  {
    return rmse;
  }


 rmse /= estimations.length();

 rmse = rmse.array().sqrt();

 return rmse;

}

