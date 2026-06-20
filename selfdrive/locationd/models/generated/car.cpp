#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3928719841740981699) {
   out_3928719841740981699[0] = delta_x[0] + nom_x[0];
   out_3928719841740981699[1] = delta_x[1] + nom_x[1];
   out_3928719841740981699[2] = delta_x[2] + nom_x[2];
   out_3928719841740981699[3] = delta_x[3] + nom_x[3];
   out_3928719841740981699[4] = delta_x[4] + nom_x[4];
   out_3928719841740981699[5] = delta_x[5] + nom_x[5];
   out_3928719841740981699[6] = delta_x[6] + nom_x[6];
   out_3928719841740981699[7] = delta_x[7] + nom_x[7];
   out_3928719841740981699[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5321639104726738897) {
   out_5321639104726738897[0] = -nom_x[0] + true_x[0];
   out_5321639104726738897[1] = -nom_x[1] + true_x[1];
   out_5321639104726738897[2] = -nom_x[2] + true_x[2];
   out_5321639104726738897[3] = -nom_x[3] + true_x[3];
   out_5321639104726738897[4] = -nom_x[4] + true_x[4];
   out_5321639104726738897[5] = -nom_x[5] + true_x[5];
   out_5321639104726738897[6] = -nom_x[6] + true_x[6];
   out_5321639104726738897[7] = -nom_x[7] + true_x[7];
   out_5321639104726738897[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8540419750358065319) {
   out_8540419750358065319[0] = 1.0;
   out_8540419750358065319[1] = 0.0;
   out_8540419750358065319[2] = 0.0;
   out_8540419750358065319[3] = 0.0;
   out_8540419750358065319[4] = 0.0;
   out_8540419750358065319[5] = 0.0;
   out_8540419750358065319[6] = 0.0;
   out_8540419750358065319[7] = 0.0;
   out_8540419750358065319[8] = 0.0;
   out_8540419750358065319[9] = 0.0;
   out_8540419750358065319[10] = 1.0;
   out_8540419750358065319[11] = 0.0;
   out_8540419750358065319[12] = 0.0;
   out_8540419750358065319[13] = 0.0;
   out_8540419750358065319[14] = 0.0;
   out_8540419750358065319[15] = 0.0;
   out_8540419750358065319[16] = 0.0;
   out_8540419750358065319[17] = 0.0;
   out_8540419750358065319[18] = 0.0;
   out_8540419750358065319[19] = 0.0;
   out_8540419750358065319[20] = 1.0;
   out_8540419750358065319[21] = 0.0;
   out_8540419750358065319[22] = 0.0;
   out_8540419750358065319[23] = 0.0;
   out_8540419750358065319[24] = 0.0;
   out_8540419750358065319[25] = 0.0;
   out_8540419750358065319[26] = 0.0;
   out_8540419750358065319[27] = 0.0;
   out_8540419750358065319[28] = 0.0;
   out_8540419750358065319[29] = 0.0;
   out_8540419750358065319[30] = 1.0;
   out_8540419750358065319[31] = 0.0;
   out_8540419750358065319[32] = 0.0;
   out_8540419750358065319[33] = 0.0;
   out_8540419750358065319[34] = 0.0;
   out_8540419750358065319[35] = 0.0;
   out_8540419750358065319[36] = 0.0;
   out_8540419750358065319[37] = 0.0;
   out_8540419750358065319[38] = 0.0;
   out_8540419750358065319[39] = 0.0;
   out_8540419750358065319[40] = 1.0;
   out_8540419750358065319[41] = 0.0;
   out_8540419750358065319[42] = 0.0;
   out_8540419750358065319[43] = 0.0;
   out_8540419750358065319[44] = 0.0;
   out_8540419750358065319[45] = 0.0;
   out_8540419750358065319[46] = 0.0;
   out_8540419750358065319[47] = 0.0;
   out_8540419750358065319[48] = 0.0;
   out_8540419750358065319[49] = 0.0;
   out_8540419750358065319[50] = 1.0;
   out_8540419750358065319[51] = 0.0;
   out_8540419750358065319[52] = 0.0;
   out_8540419750358065319[53] = 0.0;
   out_8540419750358065319[54] = 0.0;
   out_8540419750358065319[55] = 0.0;
   out_8540419750358065319[56] = 0.0;
   out_8540419750358065319[57] = 0.0;
   out_8540419750358065319[58] = 0.0;
   out_8540419750358065319[59] = 0.0;
   out_8540419750358065319[60] = 1.0;
   out_8540419750358065319[61] = 0.0;
   out_8540419750358065319[62] = 0.0;
   out_8540419750358065319[63] = 0.0;
   out_8540419750358065319[64] = 0.0;
   out_8540419750358065319[65] = 0.0;
   out_8540419750358065319[66] = 0.0;
   out_8540419750358065319[67] = 0.0;
   out_8540419750358065319[68] = 0.0;
   out_8540419750358065319[69] = 0.0;
   out_8540419750358065319[70] = 1.0;
   out_8540419750358065319[71] = 0.0;
   out_8540419750358065319[72] = 0.0;
   out_8540419750358065319[73] = 0.0;
   out_8540419750358065319[74] = 0.0;
   out_8540419750358065319[75] = 0.0;
   out_8540419750358065319[76] = 0.0;
   out_8540419750358065319[77] = 0.0;
   out_8540419750358065319[78] = 0.0;
   out_8540419750358065319[79] = 0.0;
   out_8540419750358065319[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5791363154948922080) {
   out_5791363154948922080[0] = state[0];
   out_5791363154948922080[1] = state[1];
   out_5791363154948922080[2] = state[2];
   out_5791363154948922080[3] = state[3];
   out_5791363154948922080[4] = state[4];
   out_5791363154948922080[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5791363154948922080[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5791363154948922080[7] = state[7];
   out_5791363154948922080[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4207718710431964525) {
   out_4207718710431964525[0] = 1;
   out_4207718710431964525[1] = 0;
   out_4207718710431964525[2] = 0;
   out_4207718710431964525[3] = 0;
   out_4207718710431964525[4] = 0;
   out_4207718710431964525[5] = 0;
   out_4207718710431964525[6] = 0;
   out_4207718710431964525[7] = 0;
   out_4207718710431964525[8] = 0;
   out_4207718710431964525[9] = 0;
   out_4207718710431964525[10] = 1;
   out_4207718710431964525[11] = 0;
   out_4207718710431964525[12] = 0;
   out_4207718710431964525[13] = 0;
   out_4207718710431964525[14] = 0;
   out_4207718710431964525[15] = 0;
   out_4207718710431964525[16] = 0;
   out_4207718710431964525[17] = 0;
   out_4207718710431964525[18] = 0;
   out_4207718710431964525[19] = 0;
   out_4207718710431964525[20] = 1;
   out_4207718710431964525[21] = 0;
   out_4207718710431964525[22] = 0;
   out_4207718710431964525[23] = 0;
   out_4207718710431964525[24] = 0;
   out_4207718710431964525[25] = 0;
   out_4207718710431964525[26] = 0;
   out_4207718710431964525[27] = 0;
   out_4207718710431964525[28] = 0;
   out_4207718710431964525[29] = 0;
   out_4207718710431964525[30] = 1;
   out_4207718710431964525[31] = 0;
   out_4207718710431964525[32] = 0;
   out_4207718710431964525[33] = 0;
   out_4207718710431964525[34] = 0;
   out_4207718710431964525[35] = 0;
   out_4207718710431964525[36] = 0;
   out_4207718710431964525[37] = 0;
   out_4207718710431964525[38] = 0;
   out_4207718710431964525[39] = 0;
   out_4207718710431964525[40] = 1;
   out_4207718710431964525[41] = 0;
   out_4207718710431964525[42] = 0;
   out_4207718710431964525[43] = 0;
   out_4207718710431964525[44] = 0;
   out_4207718710431964525[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4207718710431964525[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4207718710431964525[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4207718710431964525[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4207718710431964525[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4207718710431964525[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4207718710431964525[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4207718710431964525[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4207718710431964525[53] = -9.8100000000000005*dt;
   out_4207718710431964525[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4207718710431964525[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4207718710431964525[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4207718710431964525[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4207718710431964525[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4207718710431964525[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4207718710431964525[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4207718710431964525[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4207718710431964525[62] = 0;
   out_4207718710431964525[63] = 0;
   out_4207718710431964525[64] = 0;
   out_4207718710431964525[65] = 0;
   out_4207718710431964525[66] = 0;
   out_4207718710431964525[67] = 0;
   out_4207718710431964525[68] = 0;
   out_4207718710431964525[69] = 0;
   out_4207718710431964525[70] = 1;
   out_4207718710431964525[71] = 0;
   out_4207718710431964525[72] = 0;
   out_4207718710431964525[73] = 0;
   out_4207718710431964525[74] = 0;
   out_4207718710431964525[75] = 0;
   out_4207718710431964525[76] = 0;
   out_4207718710431964525[77] = 0;
   out_4207718710431964525[78] = 0;
   out_4207718710431964525[79] = 0;
   out_4207718710431964525[80] = 1;
}
void h_25(double *state, double *unused, double *out_6333669642167287903) {
   out_6333669642167287903[0] = state[6];
}
void H_25(double *state, double *unused, double *out_619081717384205514) {
   out_619081717384205514[0] = 0;
   out_619081717384205514[1] = 0;
   out_619081717384205514[2] = 0;
   out_619081717384205514[3] = 0;
   out_619081717384205514[4] = 0;
   out_619081717384205514[5] = 0;
   out_619081717384205514[6] = 1;
   out_619081717384205514[7] = 0;
   out_619081717384205514[8] = 0;
}
void h_24(double *state, double *unused, double *out_8914852456241702348) {
   out_8914852456241702348[0] = state[4];
   out_8914852456241702348[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6035123740723980243) {
   out_6035123740723980243[0] = 0;
   out_6035123740723980243[1] = 0;
   out_6035123740723980243[2] = 0;
   out_6035123740723980243[3] = 0;
   out_6035123740723980243[4] = 1;
   out_6035123740723980243[5] = 0;
   out_6035123740723980243[6] = 0;
   out_6035123740723980243[7] = 0;
   out_6035123740723980243[8] = 0;
   out_6035123740723980243[9] = 0;
   out_6035123740723980243[10] = 0;
   out_6035123740723980243[11] = 0;
   out_6035123740723980243[12] = 0;
   out_6035123740723980243[13] = 0;
   out_6035123740723980243[14] = 1;
   out_6035123740723980243[15] = 0;
   out_6035123740723980243[16] = 0;
   out_6035123740723980243[17] = 0;
}
void h_30(double *state, double *unused, double *out_6608863704451793792) {
   out_6608863704451793792[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5146778047511813712) {
   out_5146778047511813712[0] = 0;
   out_5146778047511813712[1] = 0;
   out_5146778047511813712[2] = 0;
   out_5146778047511813712[3] = 0;
   out_5146778047511813712[4] = 1;
   out_5146778047511813712[5] = 0;
   out_5146778047511813712[6] = 0;
   out_5146778047511813712[7] = 0;
   out_5146778047511813712[8] = 0;
}
void h_26(double *state, double *unused, double *out_730578216893078704) {
   out_730578216893078704[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4360585036258261738) {
   out_4360585036258261738[0] = 0;
   out_4360585036258261738[1] = 0;
   out_4360585036258261738[2] = 0;
   out_4360585036258261738[3] = 0;
   out_4360585036258261738[4] = 0;
   out_4360585036258261738[5] = 0;
   out_4360585036258261738[6] = 0;
   out_4360585036258261738[7] = 1;
   out_4360585036258261738[8] = 0;
}
void h_27(double *state, double *unused, double *out_7111401163881418068) {
   out_7111401163881418068[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7321541359312238623) {
   out_7321541359312238623[0] = 0;
   out_7321541359312238623[1] = 0;
   out_7321541359312238623[2] = 0;
   out_7321541359312238623[3] = 1;
   out_7321541359312238623[4] = 0;
   out_7321541359312238623[5] = 0;
   out_7321541359312238623[6] = 0;
   out_7321541359312238623[7] = 0;
   out_7321541359312238623[8] = 0;
}
void h_29(double *state, double *unused, double *out_3249717687452916416) {
   out_3249717687452916416[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4636546703197421528) {
   out_4636546703197421528[0] = 0;
   out_4636546703197421528[1] = 1;
   out_4636546703197421528[2] = 0;
   out_4636546703197421528[3] = 0;
   out_4636546703197421528[4] = 0;
   out_4636546703197421528[5] = 0;
   out_4636546703197421528[6] = 0;
   out_4636546703197421528[7] = 0;
   out_4636546703197421528[8] = 0;
}
void h_28(double *state, double *unused, double *out_8801848998617099028) {
   out_8801848998617099028[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2672916431632095277) {
   out_2672916431632095277[0] = 1;
   out_2672916431632095277[1] = 0;
   out_2672916431632095277[2] = 0;
   out_2672916431632095277[3] = 0;
   out_2672916431632095277[4] = 0;
   out_2672916431632095277[5] = 0;
   out_2672916431632095277[6] = 0;
   out_2672916431632095277[7] = 0;
   out_2672916431632095277[8] = 0;
}
void h_31(double *state, double *unused, double *out_178222446326627774) {
   out_178222446326627774[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4986793138491613214) {
   out_4986793138491613214[0] = 0;
   out_4986793138491613214[1] = 0;
   out_4986793138491613214[2] = 0;
   out_4986793138491613214[3] = 0;
   out_4986793138491613214[4] = 0;
   out_4986793138491613214[5] = 0;
   out_4986793138491613214[6] = 0;
   out_4986793138491613214[7] = 0;
   out_4986793138491613214[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3928719841740981699) {
  err_fun(nom_x, delta_x, out_3928719841740981699);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5321639104726738897) {
  inv_err_fun(nom_x, true_x, out_5321639104726738897);
}
void car_H_mod_fun(double *state, double *out_8540419750358065319) {
  H_mod_fun(state, out_8540419750358065319);
}
void car_f_fun(double *state, double dt, double *out_5791363154948922080) {
  f_fun(state,  dt, out_5791363154948922080);
}
void car_F_fun(double *state, double dt, double *out_4207718710431964525) {
  F_fun(state,  dt, out_4207718710431964525);
}
void car_h_25(double *state, double *unused, double *out_6333669642167287903) {
  h_25(state, unused, out_6333669642167287903);
}
void car_H_25(double *state, double *unused, double *out_619081717384205514) {
  H_25(state, unused, out_619081717384205514);
}
void car_h_24(double *state, double *unused, double *out_8914852456241702348) {
  h_24(state, unused, out_8914852456241702348);
}
void car_H_24(double *state, double *unused, double *out_6035123740723980243) {
  H_24(state, unused, out_6035123740723980243);
}
void car_h_30(double *state, double *unused, double *out_6608863704451793792) {
  h_30(state, unused, out_6608863704451793792);
}
void car_H_30(double *state, double *unused, double *out_5146778047511813712) {
  H_30(state, unused, out_5146778047511813712);
}
void car_h_26(double *state, double *unused, double *out_730578216893078704) {
  h_26(state, unused, out_730578216893078704);
}
void car_H_26(double *state, double *unused, double *out_4360585036258261738) {
  H_26(state, unused, out_4360585036258261738);
}
void car_h_27(double *state, double *unused, double *out_7111401163881418068) {
  h_27(state, unused, out_7111401163881418068);
}
void car_H_27(double *state, double *unused, double *out_7321541359312238623) {
  H_27(state, unused, out_7321541359312238623);
}
void car_h_29(double *state, double *unused, double *out_3249717687452916416) {
  h_29(state, unused, out_3249717687452916416);
}
void car_H_29(double *state, double *unused, double *out_4636546703197421528) {
  H_29(state, unused, out_4636546703197421528);
}
void car_h_28(double *state, double *unused, double *out_8801848998617099028) {
  h_28(state, unused, out_8801848998617099028);
}
void car_H_28(double *state, double *unused, double *out_2672916431632095277) {
  H_28(state, unused, out_2672916431632095277);
}
void car_h_31(double *state, double *unused, double *out_178222446326627774) {
  h_31(state, unused, out_178222446326627774);
}
void car_H_31(double *state, double *unused, double *out_4986793138491613214) {
  H_31(state, unused, out_4986793138491613214);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
