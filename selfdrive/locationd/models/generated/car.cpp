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
void err_fun(double *nom_x, double *delta_x, double *out_4621547673265240374) {
   out_4621547673265240374[0] = delta_x[0] + nom_x[0];
   out_4621547673265240374[1] = delta_x[1] + nom_x[1];
   out_4621547673265240374[2] = delta_x[2] + nom_x[2];
   out_4621547673265240374[3] = delta_x[3] + nom_x[3];
   out_4621547673265240374[4] = delta_x[4] + nom_x[4];
   out_4621547673265240374[5] = delta_x[5] + nom_x[5];
   out_4621547673265240374[6] = delta_x[6] + nom_x[6];
   out_4621547673265240374[7] = delta_x[7] + nom_x[7];
   out_4621547673265240374[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4527069186343691966) {
   out_4527069186343691966[0] = -nom_x[0] + true_x[0];
   out_4527069186343691966[1] = -nom_x[1] + true_x[1];
   out_4527069186343691966[2] = -nom_x[2] + true_x[2];
   out_4527069186343691966[3] = -nom_x[3] + true_x[3];
   out_4527069186343691966[4] = -nom_x[4] + true_x[4];
   out_4527069186343691966[5] = -nom_x[5] + true_x[5];
   out_4527069186343691966[6] = -nom_x[6] + true_x[6];
   out_4527069186343691966[7] = -nom_x[7] + true_x[7];
   out_4527069186343691966[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6693843632392876727) {
   out_6693843632392876727[0] = 1.0;
   out_6693843632392876727[1] = 0.0;
   out_6693843632392876727[2] = 0.0;
   out_6693843632392876727[3] = 0.0;
   out_6693843632392876727[4] = 0.0;
   out_6693843632392876727[5] = 0.0;
   out_6693843632392876727[6] = 0.0;
   out_6693843632392876727[7] = 0.0;
   out_6693843632392876727[8] = 0.0;
   out_6693843632392876727[9] = 0.0;
   out_6693843632392876727[10] = 1.0;
   out_6693843632392876727[11] = 0.0;
   out_6693843632392876727[12] = 0.0;
   out_6693843632392876727[13] = 0.0;
   out_6693843632392876727[14] = 0.0;
   out_6693843632392876727[15] = 0.0;
   out_6693843632392876727[16] = 0.0;
   out_6693843632392876727[17] = 0.0;
   out_6693843632392876727[18] = 0.0;
   out_6693843632392876727[19] = 0.0;
   out_6693843632392876727[20] = 1.0;
   out_6693843632392876727[21] = 0.0;
   out_6693843632392876727[22] = 0.0;
   out_6693843632392876727[23] = 0.0;
   out_6693843632392876727[24] = 0.0;
   out_6693843632392876727[25] = 0.0;
   out_6693843632392876727[26] = 0.0;
   out_6693843632392876727[27] = 0.0;
   out_6693843632392876727[28] = 0.0;
   out_6693843632392876727[29] = 0.0;
   out_6693843632392876727[30] = 1.0;
   out_6693843632392876727[31] = 0.0;
   out_6693843632392876727[32] = 0.0;
   out_6693843632392876727[33] = 0.0;
   out_6693843632392876727[34] = 0.0;
   out_6693843632392876727[35] = 0.0;
   out_6693843632392876727[36] = 0.0;
   out_6693843632392876727[37] = 0.0;
   out_6693843632392876727[38] = 0.0;
   out_6693843632392876727[39] = 0.0;
   out_6693843632392876727[40] = 1.0;
   out_6693843632392876727[41] = 0.0;
   out_6693843632392876727[42] = 0.0;
   out_6693843632392876727[43] = 0.0;
   out_6693843632392876727[44] = 0.0;
   out_6693843632392876727[45] = 0.0;
   out_6693843632392876727[46] = 0.0;
   out_6693843632392876727[47] = 0.0;
   out_6693843632392876727[48] = 0.0;
   out_6693843632392876727[49] = 0.0;
   out_6693843632392876727[50] = 1.0;
   out_6693843632392876727[51] = 0.0;
   out_6693843632392876727[52] = 0.0;
   out_6693843632392876727[53] = 0.0;
   out_6693843632392876727[54] = 0.0;
   out_6693843632392876727[55] = 0.0;
   out_6693843632392876727[56] = 0.0;
   out_6693843632392876727[57] = 0.0;
   out_6693843632392876727[58] = 0.0;
   out_6693843632392876727[59] = 0.0;
   out_6693843632392876727[60] = 1.0;
   out_6693843632392876727[61] = 0.0;
   out_6693843632392876727[62] = 0.0;
   out_6693843632392876727[63] = 0.0;
   out_6693843632392876727[64] = 0.0;
   out_6693843632392876727[65] = 0.0;
   out_6693843632392876727[66] = 0.0;
   out_6693843632392876727[67] = 0.0;
   out_6693843632392876727[68] = 0.0;
   out_6693843632392876727[69] = 0.0;
   out_6693843632392876727[70] = 1.0;
   out_6693843632392876727[71] = 0.0;
   out_6693843632392876727[72] = 0.0;
   out_6693843632392876727[73] = 0.0;
   out_6693843632392876727[74] = 0.0;
   out_6693843632392876727[75] = 0.0;
   out_6693843632392876727[76] = 0.0;
   out_6693843632392876727[77] = 0.0;
   out_6693843632392876727[78] = 0.0;
   out_6693843632392876727[79] = 0.0;
   out_6693843632392876727[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6624366898111013898) {
   out_6624366898111013898[0] = state[0];
   out_6624366898111013898[1] = state[1];
   out_6624366898111013898[2] = state[2];
   out_6624366898111013898[3] = state[3];
   out_6624366898111013898[4] = state[4];
   out_6624366898111013898[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6624366898111013898[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6624366898111013898[7] = state[7];
   out_6624366898111013898[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6958933586889171013) {
   out_6958933586889171013[0] = 1;
   out_6958933586889171013[1] = 0;
   out_6958933586889171013[2] = 0;
   out_6958933586889171013[3] = 0;
   out_6958933586889171013[4] = 0;
   out_6958933586889171013[5] = 0;
   out_6958933586889171013[6] = 0;
   out_6958933586889171013[7] = 0;
   out_6958933586889171013[8] = 0;
   out_6958933586889171013[9] = 0;
   out_6958933586889171013[10] = 1;
   out_6958933586889171013[11] = 0;
   out_6958933586889171013[12] = 0;
   out_6958933586889171013[13] = 0;
   out_6958933586889171013[14] = 0;
   out_6958933586889171013[15] = 0;
   out_6958933586889171013[16] = 0;
   out_6958933586889171013[17] = 0;
   out_6958933586889171013[18] = 0;
   out_6958933586889171013[19] = 0;
   out_6958933586889171013[20] = 1;
   out_6958933586889171013[21] = 0;
   out_6958933586889171013[22] = 0;
   out_6958933586889171013[23] = 0;
   out_6958933586889171013[24] = 0;
   out_6958933586889171013[25] = 0;
   out_6958933586889171013[26] = 0;
   out_6958933586889171013[27] = 0;
   out_6958933586889171013[28] = 0;
   out_6958933586889171013[29] = 0;
   out_6958933586889171013[30] = 1;
   out_6958933586889171013[31] = 0;
   out_6958933586889171013[32] = 0;
   out_6958933586889171013[33] = 0;
   out_6958933586889171013[34] = 0;
   out_6958933586889171013[35] = 0;
   out_6958933586889171013[36] = 0;
   out_6958933586889171013[37] = 0;
   out_6958933586889171013[38] = 0;
   out_6958933586889171013[39] = 0;
   out_6958933586889171013[40] = 1;
   out_6958933586889171013[41] = 0;
   out_6958933586889171013[42] = 0;
   out_6958933586889171013[43] = 0;
   out_6958933586889171013[44] = 0;
   out_6958933586889171013[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6958933586889171013[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6958933586889171013[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6958933586889171013[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6958933586889171013[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6958933586889171013[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6958933586889171013[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6958933586889171013[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6958933586889171013[53] = -9.8100000000000005*dt;
   out_6958933586889171013[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6958933586889171013[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6958933586889171013[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6958933586889171013[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6958933586889171013[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6958933586889171013[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6958933586889171013[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6958933586889171013[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6958933586889171013[62] = 0;
   out_6958933586889171013[63] = 0;
   out_6958933586889171013[64] = 0;
   out_6958933586889171013[65] = 0;
   out_6958933586889171013[66] = 0;
   out_6958933586889171013[67] = 0;
   out_6958933586889171013[68] = 0;
   out_6958933586889171013[69] = 0;
   out_6958933586889171013[70] = 1;
   out_6958933586889171013[71] = 0;
   out_6958933586889171013[72] = 0;
   out_6958933586889171013[73] = 0;
   out_6958933586889171013[74] = 0;
   out_6958933586889171013[75] = 0;
   out_6958933586889171013[76] = 0;
   out_6958933586889171013[77] = 0;
   out_6958933586889171013[78] = 0;
   out_6958933586889171013[79] = 0;
   out_6958933586889171013[80] = 1;
}
void h_25(double *state, double *unused, double *out_5696314533542565340) {
   out_5696314533542565340[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5255877481426644938) {
   out_5255877481426644938[0] = 0;
   out_5255877481426644938[1] = 0;
   out_5255877481426644938[2] = 0;
   out_5255877481426644938[3] = 0;
   out_5255877481426644938[4] = 0;
   out_5255877481426644938[5] = 0;
   out_5255877481426644938[6] = 1;
   out_5255877481426644938[7] = 0;
   out_5255877481426644938[8] = 0;
}
void h_24(double *state, double *unused, double *out_5128055596476793433) {
   out_5128055596476793433[0] = state[4];
   out_5128055596476793433[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4785419999383306214) {
   out_4785419999383306214[0] = 0;
   out_4785419999383306214[1] = 0;
   out_4785419999383306214[2] = 0;
   out_4785419999383306214[3] = 0;
   out_4785419999383306214[4] = 1;
   out_4785419999383306214[5] = 0;
   out_4785419999383306214[6] = 0;
   out_4785419999383306214[7] = 0;
   out_4785419999383306214[8] = 0;
   out_4785419999383306214[9] = 0;
   out_4785419999383306214[10] = 0;
   out_4785419999383306214[11] = 0;
   out_4785419999383306214[12] = 0;
   out_4785419999383306214[13] = 0;
   out_4785419999383306214[14] = 1;
   out_4785419999383306214[15] = 0;
   out_4785419999383306214[16] = 0;
   out_4785419999383306214[17] = 0;
}
void h_30(double *state, double *unused, double *out_8810273519341179810) {
   out_8810273519341179810[0] = state[4];
}
void H_30(double *state, double *unused, double *out_728181151299036740) {
   out_728181151299036740[0] = 0;
   out_728181151299036740[1] = 0;
   out_728181151299036740[2] = 0;
   out_728181151299036740[3] = 0;
   out_728181151299036740[4] = 1;
   out_728181151299036740[5] = 0;
   out_728181151299036740[6] = 0;
   out_728181151299036740[7] = 0;
   out_728181151299036740[8] = 0;
}
void h_26(double *state, double *unused, double *out_93223108268356141) {
   out_93223108268356141[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1514374162552588714) {
   out_1514374162552588714[0] = 0;
   out_1514374162552588714[1] = 0;
   out_1514374162552588714[2] = 0;
   out_1514374162552588714[3] = 0;
   out_1514374162552588714[4] = 0;
   out_1514374162552588714[5] = 0;
   out_1514374162552588714[6] = 0;
   out_1514374162552588714[7] = 1;
   out_1514374162552588714[8] = 0;
}
void h_27(double *state, double *unused, double *out_3729886127726509834) {
   out_3729886127726509834[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2951775222482979957) {
   out_2951775222482979957[0] = 0;
   out_2951775222482979957[1] = 0;
   out_2951775222482979957[2] = 0;
   out_2951775222482979957[3] = 1;
   out_2951775222482979957[4] = 0;
   out_2951775222482979957[5] = 0;
   out_2951775222482979957[6] = 0;
   out_2951775222482979957[7] = 0;
   out_2951775222482979957[8] = 0;
}
void h_29(double *state, double *unused, double *out_3887072796077638979) {
   out_3887072796077638979[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1238412495613428924) {
   out_1238412495613428924[0] = 0;
   out_1238412495613428924[1] = 1;
   out_1238412495613428924[2] = 0;
   out_1238412495613428924[3] = 0;
   out_1238412495613428924[4] = 0;
   out_1238412495613428924[5] = 0;
   out_1238412495613428924[6] = 0;
   out_1238412495613428924[7] = 0;
   out_1238412495613428924[8] = 0;
}
void h_28(double *state, double *unused, double *out_1271787139934335811) {
   out_1271787139934335811[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3843986521456101650) {
   out_3843986521456101650[0] = 1;
   out_3843986521456101650[1] = 0;
   out_3843986521456101650[2] = 0;
   out_3843986521456101650[3] = 0;
   out_3843986521456101650[4] = 0;
   out_3843986521456101650[5] = 0;
   out_3843986521456101650[6] = 0;
   out_3843986521456101650[7] = 0;
   out_3843986521456101650[8] = 0;
}
void h_31(double *state, double *unused, double *out_5853501201893694485) {
   out_5853501201893694485[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5286523443303605366) {
   out_5286523443303605366[0] = 0;
   out_5286523443303605366[1] = 0;
   out_5286523443303605366[2] = 0;
   out_5286523443303605366[3] = 0;
   out_5286523443303605366[4] = 0;
   out_5286523443303605366[5] = 0;
   out_5286523443303605366[6] = 0;
   out_5286523443303605366[7] = 0;
   out_5286523443303605366[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4621547673265240374) {
  err_fun(nom_x, delta_x, out_4621547673265240374);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4527069186343691966) {
  inv_err_fun(nom_x, true_x, out_4527069186343691966);
}
void car_H_mod_fun(double *state, double *out_6693843632392876727) {
  H_mod_fun(state, out_6693843632392876727);
}
void car_f_fun(double *state, double dt, double *out_6624366898111013898) {
  f_fun(state,  dt, out_6624366898111013898);
}
void car_F_fun(double *state, double dt, double *out_6958933586889171013) {
  F_fun(state,  dt, out_6958933586889171013);
}
void car_h_25(double *state, double *unused, double *out_5696314533542565340) {
  h_25(state, unused, out_5696314533542565340);
}
void car_H_25(double *state, double *unused, double *out_5255877481426644938) {
  H_25(state, unused, out_5255877481426644938);
}
void car_h_24(double *state, double *unused, double *out_5128055596476793433) {
  h_24(state, unused, out_5128055596476793433);
}
void car_H_24(double *state, double *unused, double *out_4785419999383306214) {
  H_24(state, unused, out_4785419999383306214);
}
void car_h_30(double *state, double *unused, double *out_8810273519341179810) {
  h_30(state, unused, out_8810273519341179810);
}
void car_H_30(double *state, double *unused, double *out_728181151299036740) {
  H_30(state, unused, out_728181151299036740);
}
void car_h_26(double *state, double *unused, double *out_93223108268356141) {
  h_26(state, unused, out_93223108268356141);
}
void car_H_26(double *state, double *unused, double *out_1514374162552588714) {
  H_26(state, unused, out_1514374162552588714);
}
void car_h_27(double *state, double *unused, double *out_3729886127726509834) {
  h_27(state, unused, out_3729886127726509834);
}
void car_H_27(double *state, double *unused, double *out_2951775222482979957) {
  H_27(state, unused, out_2951775222482979957);
}
void car_h_29(double *state, double *unused, double *out_3887072796077638979) {
  h_29(state, unused, out_3887072796077638979);
}
void car_H_29(double *state, double *unused, double *out_1238412495613428924) {
  H_29(state, unused, out_1238412495613428924);
}
void car_h_28(double *state, double *unused, double *out_1271787139934335811) {
  h_28(state, unused, out_1271787139934335811);
}
void car_H_28(double *state, double *unused, double *out_3843986521456101650) {
  H_28(state, unused, out_3843986521456101650);
}
void car_h_31(double *state, double *unused, double *out_5853501201893694485) {
  h_31(state, unused, out_5853501201893694485);
}
void car_H_31(double *state, double *unused, double *out_5286523443303605366) {
  H_31(state, unused, out_5286523443303605366);
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
